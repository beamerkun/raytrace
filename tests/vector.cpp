#include "gtest/gtest.h"

#include <cmath>
#include <tuple>
#include <vector>

#include <vector.h>

using namespace testing;

TEST(VectorTest, VectorIsATupleWithLastCoordEqualZero) {
  auto v = Vector(4.3, -4.2, 3.1);
  ASSERT_DOUBLE_EQ(v.w(), 0.0);
}

TEST(VectorTest, SumOfVectorsIsAVector) {
  auto v1 = Vector(4.3, -4.2, 3.1);
  auto v2 = Vector(4.3, -4.2, 3.1);
  auto sum = v1 + v2;

  ASSERT_TRUE(sum.isVector());
  ASSERT_FALSE(sum.isPoint());
}

TEST(VectorTest, DifferenceOfVectorsIsAVector) {
  auto v1 = Vector(4.3, -4.2, 3.1);
  auto v2 = Vector(4.3, -4.2, 3.1);
  auto diff = v1 - v2;

  ASSERT_TRUE(diff.isVector());
  ASSERT_FALSE(diff.isPoint());
}

TEST(VectorTest, MagnitudeOfVectorIsSquareRootOfCoordinatesSquaresSum) {
  std::vector<Vector> v = {Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 1), Vector(1, 2, 3), Vector(-1, -2, -3)};
  std::vector<double> mag = {1.0, 1.0, 1.0, sqrt(14), sqrt(14)};

  for (int i = 0; i < v.size(); ++i) {
    ASSERT_DOUBLE_EQ(v[i].magnitude(), mag[i]);
  }
}

TEST(VectorTest, NormalizedVectorHasCoordinatedDividedByMagnitude) {
  auto v = Vector(4, 0, 0);
  auto n = v.normalize();

  ASSERT_DOUBLE_EQ(1, n.x());
  ASSERT_DOUBLE_EQ(0, n.y());
  ASSERT_DOUBLE_EQ(0, n.z());

  auto v2 = Vector(1, 2, 3);
  auto n2 = v2.normalize();
  auto mag = v2.magnitude();

  ASSERT_DOUBLE_EQ(v2.x() / mag, n2.x());
  ASSERT_DOUBLE_EQ(v2.y() / mag, n2.y());
  ASSERT_DOUBLE_EQ(v2.z() / mag, n2.z());
}

TEST(VectorTest, NormalizedVectorHadMagnitudeEqualOne) {
  std::vector<Vector> v = {Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 1), Vector(1, 2, 3), Vector(-1, -2, -3)};

  for (int i = 0; i < v.size(); ++i) {
    ASSERT_DOUBLE_EQ(v[i].normalize().magnitude(), 1.0);
  }
}

TEST(VectorTest, DotProductOfVectorsIsSumOfCoordinatesProducts) {
  auto v1 = Vector(1, 2, 3);
  auto v2 = Vector(2, 3, 4);

  ASSERT_DOUBLE_EQ(v1.dot(v2), 20.0);
}

TEST(VectorTest, CrossProductOfVectors) {
  auto v1 = Vector(1, 2, 3);
  auto v2 = Vector(2, 3, 4);

  auto cross1 = v1.cross(v2);
  ASSERT_DOUBLE_EQ(cross1.x(), -1.0);
  ASSERT_DOUBLE_EQ(cross1.y(), 2.0);
  ASSERT_DOUBLE_EQ(cross1.z(), -1.0);

  auto cross2 = v2.cross(v1);
  ASSERT_DOUBLE_EQ(cross2.x(), 1.0);
  ASSERT_DOUBLE_EQ(cross2.y(), -2.0);
  ASSERT_DOUBLE_EQ(cross2.z(), 1.0);
}
