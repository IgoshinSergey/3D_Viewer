#include "object.hpp"

/************************************************************
 * @file object.cpp
 * @brief Классы для хранения информации о 3д объекте
 ************************************************************/

s21::Point::Point() : x{0}, y{0}, z{0} {}

s21::Point::Point(double x, double y, double z) : x{x}, y{y}, z{z} {}

s21::Point::~Point() {}

s21::Line::Line() : indexes{} {}

s21::Line::Line(std::vector<int>& other) : indexes{other} {}

s21::Line::~Line() {}

s21::Object::Object() : vertexes{}, lines{} {}

s21::Object::~Object() {}
