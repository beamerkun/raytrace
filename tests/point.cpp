#include "gtest/gtest.h"

#include <point.h>
#include <vector.h>

TEST(PointTest, PointIsATupleWithLastCoordEqualOne) {
  auto p = Point(4.3, -4.2, 3.1);
  ASSERT_DOUBLE_EQ(p.w(), 1.0);
}

TEST(PointTest, SumOfPointsIsNeitherPointNorVector) {
  auto p1 = Point(4.3, -4.2, 3.1);
  auto p2 = Point(4.3, -4.2, 3.1);
  auto sum = p1 + p2;

  ASSERT_FALSE(sum.isVector());
  ASSERT_FALSE(sum.isPoint());
}

TEST(PointTest, SumOfPointAndVectorIsAPoint) {
  auto v = Vector(4.3, -4.2, 3.1);
  auto p = Point(4.3, -4.2, 3.1);
  auto sum = v + p;

  ASSERT_FALSE(sum.isVector());
  ASSERT_TRUE(sum.isPoint());
}

TEST(PointTest, DifferenceOfPointsIsAVector) {
  auto p1 = Point(4.3, -4.2, 3.1);
  auto p2 = Point(4.3, -4.2, 3.1);
  auto diff = p1 - p2;

  ASSERT_TRUE(diff.isVector());
  ASSERT_FALSE(diff.isPoint());
}

TEST(PointTest, DifferenceOfPointAndVectorIsAPoint) {
  auto v = Vector(4.3, -4.2, 3.1);
  auto p = Point(4.3, -4.2, 3.1);
  auto diff = p - v;

  ASSERT_FALSE(diff.isVector());
  ASSERT_TRUE(diff.isPoint());
}

TEST(PointTest, DifferenceOfVectorAndPointIsNeitherAPointNorVector) {
  auto v = Vector(4.3, -4.2, 3.1);
  auto p = Point(4.3, -4.2, 3.1);
  auto diff = v - p;

  ASSERT_FALSE(diff.isVector());
  ASSERT_FALSE(diff.isPoint());
}
