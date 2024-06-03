#include "tests.hpp"

TEST(parsing, test_1) {
  auto& controller = s21::Controller::getInstance();
  controller.parseFile("tests/datasets/test1.obj");
  auto& object = controller.getObject();
  auto& points = object.vertexes;

  EXPECT_DOUBLE_EQ(points.size(), 8);
  EXPECT_DOUBLE_EQ(points.at(0).x, 1);
  EXPECT_DOUBLE_EQ(points.at(0).y, 1);
  EXPECT_DOUBLE_EQ(points.at(0).z, -1);

  EXPECT_DOUBLE_EQ(points.at(1).x, 1);
  EXPECT_DOUBLE_EQ(points.at(1).y, -1);
  EXPECT_DOUBLE_EQ(points.at(1).z, -1);

  EXPECT_DOUBLE_EQ(points.at(2).x, -1);
  EXPECT_DOUBLE_EQ(points.at(2).y, -1);
  EXPECT_DOUBLE_EQ(points.at(2).z, -1);

  EXPECT_DOUBLE_EQ(points.at(3).x, -1);
  EXPECT_DOUBLE_EQ(points.at(3).y, 1);
  EXPECT_DOUBLE_EQ(points.at(3).z, -1);

  EXPECT_DOUBLE_EQ(points.at(4).x, 1);
  EXPECT_DOUBLE_EQ(points.at(4).y, 1);
  EXPECT_DOUBLE_EQ(points.at(4).z, 1);

  EXPECT_DOUBLE_EQ(points.at(5).x, 1);
  EXPECT_DOUBLE_EQ(points.at(5).y, -1);
  EXPECT_DOUBLE_EQ(points.at(5).z, 1);

  EXPECT_DOUBLE_EQ(points.at(6).x, -1);
  EXPECT_DOUBLE_EQ(points.at(6).y, -1);
  EXPECT_DOUBLE_EQ(points.at(6).z, 1);

  EXPECT_DOUBLE_EQ(points.at(7).x, -1);
  EXPECT_DOUBLE_EQ(points.at(7).y, 1);
  EXPECT_DOUBLE_EQ(points.at(7).z, 1);

  auto& facets = object.lines;

  EXPECT_EQ(facets.at(0).indexes.size(), 4);
  EXPECT_EQ(facets.at(0).indexes.at(0), 1);
  EXPECT_EQ(facets.at(0).indexes.at(1), 2);
  EXPECT_EQ(facets.at(0).indexes.at(2), 3);
  EXPECT_EQ(facets.at(0).indexes.at(3), 4);

  EXPECT_EQ(facets.at(1).indexes.size(), 4);
  EXPECT_EQ(facets.at(1).indexes.at(0), 5);
  EXPECT_EQ(facets.at(1).indexes.at(1), 6);
  EXPECT_EQ(facets.at(1).indexes.at(2), 7);
  EXPECT_EQ(facets.at(1).indexes.at(3), 8);

  EXPECT_EQ(facets.at(2).indexes.size(), 2);
  EXPECT_EQ(facets.at(2).indexes.at(0), 1);
  EXPECT_EQ(facets.at(2).indexes.at(1), 5);

  EXPECT_EQ(facets.at(3).indexes.size(), 2);
  EXPECT_EQ(facets.at(3).indexes.at(0), 2);
  EXPECT_EQ(facets.at(3).indexes.at(1), 6);

  EXPECT_EQ(facets.at(4).indexes.size(), 2);
  EXPECT_EQ(facets.at(4).indexes.at(0), 3);
  EXPECT_EQ(facets.at(4).indexes.at(1), 7);

  EXPECT_EQ(facets.at(5).indexes.size(), 2);
  EXPECT_EQ(facets.at(5).indexes.at(0), 4);
  EXPECT_EQ(facets.at(5).indexes.at(1), 8);
}

TEST(parsing, test_2) {
  auto& controller = s21::Controller::getInstance();
  controller.clearObject();
  controller.parseFile("tests/datasets/test2.obj");
  auto& object = controller.getObject();
  auto& points = object.vertexes;

  EXPECT_DOUBLE_EQ(points.at(0).x, 1);
  EXPECT_DOUBLE_EQ(points.at(0).y, 2);
  EXPECT_DOUBLE_EQ(points.at(0).z, 3);

  EXPECT_DOUBLE_EQ(points.at(1).x, 2);
  EXPECT_DOUBLE_EQ(points.at(1).y, 3);
  EXPECT_DOUBLE_EQ(points.at(1).z, 4);

  EXPECT_DOUBLE_EQ(points.at(2).x, 3);
  EXPECT_DOUBLE_EQ(points.at(2).y, 4);
  EXPECT_DOUBLE_EQ(points.at(2).z, 5);

  EXPECT_DOUBLE_EQ(points.at(3).x, 4);
  EXPECT_DOUBLE_EQ(points.at(3).y, 5);
  EXPECT_DOUBLE_EQ(points.at(3).z, 6);

  EXPECT_DOUBLE_EQ(points.at(4).x, 5);
  EXPECT_DOUBLE_EQ(points.at(4).y, 6);
  EXPECT_DOUBLE_EQ(points.at(4).z, 7);

  EXPECT_DOUBLE_EQ(points.at(5).x, 6);
  EXPECT_DOUBLE_EQ(points.at(5).y, 7);
  EXPECT_DOUBLE_EQ(points.at(5).z, 8);

  auto& facets = object.lines;

  EXPECT_EQ(facets.at(0).indexes.size(), 3);
  EXPECT_EQ(facets.at(0).indexes.at(0), 1);
  EXPECT_EQ(facets.at(0).indexes.at(1), 2);
  EXPECT_EQ(facets.at(0).indexes.at(2), 3);

  EXPECT_EQ(facets.at(1).indexes.size(), 3);
  EXPECT_EQ(facets.at(1).indexes.at(0), 4);
  EXPECT_EQ(facets.at(1).indexes.at(1), 5);
  EXPECT_EQ(facets.at(1).indexes.at(2), 6);
}

TEST(parsing, test_3) {
  auto& controller = s21::Controller::getInstance();
  controller.clearObject();
  controller.parseFile("tests/datasets/test3.obj");
  auto& object = controller.getObject();
  auto& points = object.vertexes;

  EXPECT_DOUBLE_EQ(points.at(0).x, 1.5);
  EXPECT_DOUBLE_EQ(points.at(0).y, 2.1);
  EXPECT_DOUBLE_EQ(points.at(0).z, 3.9);

  EXPECT_DOUBLE_EQ(points.at(1).x, 2.1);
  EXPECT_DOUBLE_EQ(points.at(1).y, 3.5);
  EXPECT_DOUBLE_EQ(points.at(1).z, 4.2);

  EXPECT_DOUBLE_EQ(points.at(2).x, 3.12);
  EXPECT_DOUBLE_EQ(points.at(2).y, 4.1);
  EXPECT_DOUBLE_EQ(points.at(2).z, 5.4);

  EXPECT_DOUBLE_EQ(points.at(3).x, 4.132);
  EXPECT_DOUBLE_EQ(points.at(3).y, 5.132);
  EXPECT_DOUBLE_EQ(points.at(3).z, 6.33);

  EXPECT_DOUBLE_EQ(points.at(4).x, 5.642);
  EXPECT_DOUBLE_EQ(points.at(4).y, 6.13);
  EXPECT_DOUBLE_EQ(points.at(4).z, 7.15);

  EXPECT_DOUBLE_EQ(points.at(5).x, 6.62);
  EXPECT_DOUBLE_EQ(points.at(5).y, 7.342);
  EXPECT_DOUBLE_EQ(points.at(5).z, 8.74);

  auto& facets = object.lines;

  EXPECT_EQ(facets.at(0).indexes.size(), 3);
  EXPECT_EQ(facets.at(0).indexes.at(0), 1);
  EXPECT_EQ(facets.at(0).indexes.at(1), 2);
  EXPECT_EQ(facets.at(0).indexes.at(2), 3);

  EXPECT_EQ(facets.at(1).indexes.size(), 3);
  EXPECT_EQ(facets.at(1).indexes.at(0), 4);
  EXPECT_EQ(facets.at(1).indexes.at(1), 5);
  EXPECT_EQ(facets.at(1).indexes.at(2), 6);

  EXPECT_EQ(facets.at(2).indexes.size(), 2);
  EXPECT_EQ(facets.at(2).indexes.at(0), 1);
  EXPECT_EQ(facets.at(2).indexes.at(1), 4);

  EXPECT_EQ(facets.at(3).indexes.size(), 2);
  EXPECT_EQ(facets.at(3).indexes.at(0), 2);
  EXPECT_EQ(facets.at(3).indexes.at(1), 5);

  EXPECT_EQ(facets.at(4).indexes.size(), 2);
  EXPECT_EQ(facets.at(4).indexes.at(0), 3);
  EXPECT_EQ(facets.at(4).indexes.at(1), 6);
}