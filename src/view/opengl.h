#ifndef OPENGL_H
#define OPENGL_H

#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWidget>

#include "../controller/controller.h"
namespace s21 {

struct Color {
  float red, green, blue;
};

class OpenGl : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  OpenGl();
  ~OpenGl();
  void setVerticesColor(const float& red, const float& green,
                        const float& blue);
  void setVerticesThickness(const float& thickness);
  void setVetricesType(const int& type);

 protected:
  void initializeGL() override;  // Метод для инициализирования opengl
  void paintGL() override;  // Метод для вывода изображения на экран
  void mouseMoveEvent(
      QMouseEvent* me) override;  // Метод реагирует на перемещение указателя,
                                  // но по умолчанию setMouseTracking(false)
  void mousePressEvent(
      QMouseEvent* me) override;  // Реагирует на нажатие кнопок мыши
  void paintLine();
  void projection();
  void paintVertices();

 private:
  QPoint mouse;

 public:
  Color line_color{1.f, 1.f, 1.f};
  void renderScene();
  Color vertex_color{1.f, 1.f, 1.f};
  int vertex_type = 0;
  float vertices_thickness = 1.f;
  float line_width = 1.f;
  bool is_solid_line = true;

  Color background_color{0.f, 0.f, 0.f};
  bool is_parallel_projection = true;
  s21::Controller& c;
};
}  // namespace s21

#endif  // OPENGL_H
