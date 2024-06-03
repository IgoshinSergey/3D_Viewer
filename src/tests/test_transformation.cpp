#include <cmath>

#include "../manipulation/manipulation.hpp"
#include "../object/object.hpp"
#include "tests.hpp"

bool isEqualVectors(std::vector<s21::Point>& v1, std::vector<s21::Point>& v2) {
  if (v1.size() != v2.size()) {
    std::cout << "AAAAA" << '\n';
    std::cout << v1.size() << ' ' << v2.size() << '\n';
    return false;
  }
  for (unsigned int i = 0; i < v1.size(); i++) {
    s21::Point& p1 = v1[i];
    s21::Point& p2 = v2[i];
    if (fabs(p1.x - p2.x) > 1e-6) {
      std::cout << p1.x << ' ' << p2.x << '\n';
      return false;
    }
    if (fabs(p1.y - p2.y) > 1e-6) {
      std::cout << p1.y << ' ' << p2.y << '\n';
      return false;
    }
    if (fabs(p1.z - p2.z) > 1e-6) {
      std::cout << p1.z << ' ' << p2.z << '\n';
      return false;
    }
  }
  return true;
}

TEST(MoveX, test_1) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {
      {1, 1, 1}, {3.2, 3.4, 4.3}, {3.2, 0, 0}, {7.2, -43, 4}};
  std::vector<s21::Point> v2 = {
      {2, 1, 1}, {4.2, 3.4, 4.3}, {4.2, 0, 0}, {8.2, -43, 4}};
  model.TransformModel(v1, s21::MoveX, 1);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(MoveX, test_2) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {
      {1, 1, 1}, {3.2, 3.4, 4.3}, {3.2, 0, 0}, {7.2, -43, 4}};
  std::vector<s21::Point> v2 = {
      {0, 1, 1}, {2.2, 3.4, 4.3}, {2.2, 0, 0}, {6.2, -43, 4}};
  model.TransformModel(v1, s21::MoveX, -1);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(MoveX, test_3) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {
      {1, 1, 1}, {3.2, 3.4, 4.3}, {3.2, 0, 0}, {7.2, -43, 4}};
  std::vector<s21::Point> v2 = {
      {1.5, 1, 1}, {3.7, 3.4, 4.3}, {3.7, 0, 0}, {7.7, -43, 4}};
  model.TransformModel(v1, s21::MoveX, 0.5);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(MoveY, test_1) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {{1, 2, 1}, {2, 3, 2}, {3, 4, 3}, {-2, -1, -2}};
  model.TransformModel(v1, s21::MoveY, 1);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(MoveY, test_2) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {{1, 0, 1}, {2, 1, 2}, {3, 2, 3}, {-2, -3, -2}};
  model.TransformModel(v1, s21::MoveY, -1);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(MoveY, test_3) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {
      {1, 0.5, 1}, {2, 1.5, 2}, {3, 2.5, 3}, {-2, -2.5, -2}};
  model.TransformModel(v1, s21::MoveY, -0.5);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(MoveZ, test_1) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {{1, 1, 2}, {2, 2, 3}, {3, 3, 4}, {-2, -2, -1}};
  model.TransformModel(v1, s21::MoveZ, 1);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(MoveZ, test_2) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {{1, 1, 0}, {2, 2, 1}, {3, 3, 2}, {-2, -2, -3}};
  model.TransformModel(v1, s21::MoveZ, -1);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(MoveZ, test_3) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {
      {1, 1, 0.5}, {2, 2, 1.5}, {3, 3, 2.5}, {-2, -2, -2.5}};
  model.TransformModel(v1, s21::MoveZ, -0.5);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(RotateX, test) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {{1, 0.972212, 1.027036},
                                {2, 1.944424, 2.054073},
                                {3, 2.916636, 3.081109},
                                {-2.000000, -1.944424, -2.054073}};
  model.TransformModel(v1, s21::RotateX, 1.5708);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(RotateY, test) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {{0.972212, 1, 1.027036},
                                {1.944424, 2, 2.054073},
                                {2.916636, 3, 3.081109},
                                {-1.944424, -2, -2.054073}};
  model.TransformModel(v1, s21::RotateY, -1.5708);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(RotateZ, test) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {{1.027036, 0.972212, 1},
                                {2.054073, 1.944424, 2},
                                {3.081109, 2.916636, 3},
                                {-2.054073, -1.944424, -2}};
  model.TransformModel(v1, s21::RotateZ, -1.5708);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}

TEST(Scale, test) {
  s21::ManipulationFacade model;
  std::vector<s21::Point> v1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {-2, -2, -2}};
  std::vector<s21::Point> v2 = {
      {0.5, 0.5, 0.5}, {1, 1, 1}, {1.5, 1.5, 1.5}, {-1, -1, -1}};
  model.TransformModel(v1, s21::SCALE, 0.5);
  EXPECT_TRUE(isEqualVectors(v1, v2));
}
