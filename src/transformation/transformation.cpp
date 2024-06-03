#include "transformation.hpp"

#include <cmath>

/************************************************************
 * @file transformation.cpp
 * @brief Реализация афинных преобразований
 ************************************************************/

using namespace s21;

void Move::Transform(std::vector<Point>& vertexes, Movement move, double step) {
  switch (move) {
    case MoveX:
      moveX(vertexes, step);
      break;
    case MoveY:
      moveY(vertexes, step);
      break;
    case MoveZ:
      moveZ(vertexes, step);
      break;
    default:
      return;
  }
}

void Move::moveX(std::vector<Point>& vertexes, double step) {
  for (Point& p : vertexes) {
    p.x += step;
  }
}

void Move::moveY(std::vector<Point>& vertexes, double step) {
  for (Point& p : vertexes) {
    p.y += step;
  }
}

void Move::moveZ(std::vector<Point>& vertexes, double step) {
  for (Point& p : vertexes) {
    p.z += step;
  }
}

void Rotate::Transform(std::vector<Point>& vertexes, Movement move,
                       double angle) {
  angle = angle * M_PI / 180;
  switch (move) {
    case RotateX:
      rotateX(vertexes, angle);
      break;
    case RotateY:
      rotateY(vertexes, angle);
      break;
    case RotateZ:
      rotateZ(vertexes, angle);
      break;
    default:
      return;
  }
}

void Rotate::rotateX(std::vector<Point>& vertexes, double angle) {
  for (Point& p : vertexes) {
    double tmpY = p.y;
    p.y = p.y * std::cos(angle) - p.z * std::sin(angle);
    p.z = tmpY * std::sin(angle) + p.z * std::cos(angle);
  }
}

void Rotate::rotateY(std::vector<Point>& vertexes, double angle) {
  for (Point& p : vertexes) {
    double tmpX = p.x;
    p.x = p.x * std::cos(angle) + p.z * std::sin(angle);
    p.z = -tmpX * std::sin(angle) + p.z * std::cos(angle);
  }
}

void Rotate::rotateZ(std::vector<Point>& vertexes, double angle) {
  for (Point& p : vertexes) {
    double tmpX = p.x;
    p.x = p.x * std::cos(angle) - p.y * std::sin(angle);
    p.y = tmpX * std::sin(angle) + p.y * std::cos(angle);
  }
}

void Scale::Transform(std::vector<Point>& vertexes, Movement move,
                      double scal) {
  if (move == SCALE)
    scale(vertexes, scal);
  else
    return;
}

void Scale::scale(std::vector<Point>& vertexes, double scal) {
  for (Point& p : vertexes) {
    p.x *= scal;
    p.y *= scal;
    p.z *= scal;
  }
}

void ObjectTransformer::set_strategy(TransformationStrategy* strategy) {
  strategy_ = strategy;
}

void ObjectTransformer::TransformModel(std::vector<Point>& vertexes,
                                       Movement move, double value) {
  strategy_->Transform(vertexes, move, value);
}
