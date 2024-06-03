#include "manipulation.hpp"

/************************************************************
 * @file manipulation.cpp
 * @brief Логика модели
 ************************************************************/

s21::ManipulationFacade::ManipulationFacade() : parser{}, transformer{} {}

void s21::ManipulationFacade::parseFile(Object& object, std::string filename) {
  parser.parseFile(object, filename);
}

void s21::ManipulationFacade::TransformModel(std::vector<Point>& vertexes,
                                             Movement move, double val) {
  if (move == MoveX || move == MoveY || move == MoveZ) {
    Move strategy;
    transformer.set_strategy(&strategy);
  } else if (move == RotateX || move == RotateY || move == RotateZ) {
    Rotate strategy;
    transformer.set_strategy(&strategy);
  } else {
    Scale strategy;
    transformer.set_strategy(&strategy);
  }
  transformer.TransformModel(vertexes, move, val);
}

void s21::ManipulationFacade::Normalization(std::vector<Point>& vertexes) {
  double maxX = -100000000, maxY = -100000000, maxZ = -100000000;
  double minX = 100000000, minY = 100000000, minZ = 100000000;
  for (const Point& p : vertexes) {
    maxX = maxX < p.x ? p.x : maxX;
    maxY = maxY < p.y ? p.y : maxY;
    maxZ = maxZ < p.z ? p.z : maxZ;
    minX = minX > p.x ? p.x : minX;
    minY = minY > p.y ? p.y : minY;
    minZ = minZ > p.z ? p.z : minZ;
  }
  double centerX = minX + (maxX - minX) / 2;
  double centerY = minY + (maxY - minY) / 2;
  double centerZ = minZ + (maxZ - minZ) / 2;
  double dmax = std::max(maxX - minX, maxY - minY);
  dmax = std::max(dmax, maxZ - minZ);
  double scal = (0.5 - (0.5 * (-1))) / dmax;
  for (Point& p : vertexes) {
    p.x -= centerX;
    p.x *= scal;
    p.y -= centerY;
    p.y *= scal;
    p.z -= centerZ;
    p.z *= scal;
  }
}
