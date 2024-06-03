#include "opengl.h"

#include <iostream>

s21::OpenGl::OpenGl() : c{s21::Controller::getInstance()} {}

s21::OpenGl::~OpenGl() {}

void s21::OpenGl::setVerticesColor(const float& red, const float& green,
                                   const float& blue) {
  vertex_color.red = red;
  vertex_color.green = green;
  vertex_color.blue = blue;
}

void s21::OpenGl::setVerticesThickness(const float& thickness) {
  vertices_thickness = thickness;
}

void s21::OpenGl::setVetricesType(const int& type) { vertex_type = type; }

void s21::OpenGl::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void s21::OpenGl::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  projection();
  glClearColor(background_color.red, background_color.green,
               background_color.blue, 1.0f);
  if (vertex_type != 0) paintVertices();

  paintLine();
}

void s21::OpenGl::mouseMoveEvent(QMouseEvent* me) {
  c.TransformModel(s21::RotateY, (me->pos().x() - mouse.x()) * 0.02);
  c.TransformModel(s21::RotateX, (me->pos().y() - mouse.y()) * 0.02);
  update();
}

void s21::OpenGl::mousePressEvent(QMouseEvent* me) { mouse = me->pos(); }

void s21::OpenGl::paintVertices() {
  glEnable(GL_BLEND);
  if (vertex_type == 1) glEnable(GL_POINT_SMOOTH);
  if (vertex_type == 2) glDisable(GL_POINT_SMOOTH);
  glPointSize(vertices_thickness * 2);
  glColor3f(vertex_color.red, vertex_color.green, vertex_color.blue);
  auto& obj = c.getObject();
  glBegin(GL_POINTS);
  for (auto& v : obj.vertexes) {
    glVertex3d(v.x, v.y, v.z);
  }
  glEnd();
}

void s21::OpenGl::renderScene() { paintGL(); }

void s21::OpenGl::paintLine() {
  auto& obj = c.getObject();
  auto& vertexes = obj.vertexes;
  auto& lines = obj.lines;
  glColor3f(line_color.red, line_color.green, line_color.blue);
  for (auto& f : lines) {
    glLineWidth(line_width);
    if (is_solid_line) {
      glDisable(GL_LINE_STIPPLE);
      glBegin(GL_LINE_LOOP);
    } else {
      glLineStipple(1, 0x00ff);
      glEnable(GL_LINE_STIPPLE);
      glBegin(GL_LINE_LOOP);
    }
    for (auto& p : f.indexes) {
      auto& point = vertexes.at(p - 1);
      glVertex3d(point.x, point.y, point.z);
    }
    glEnd();
  }
}

void s21::OpenGl::projection() {
  if (is_parallel_projection) {
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
  } else {
    glFrustum(-0.5f, 0.5f, -0.5f, 0.5f, 0.1f, 100.f);
    glTranslated(0, 0, -1.04);
  }
}
