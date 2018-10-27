#include "gtest/gtest.h"

#include <tuple.h>

TEST(TupleTest, TupleWithLastCoordEqualOneIsAPoint) {
  auto t = Tuple(4.3, -4.2, 3.1, 1.0);

  ASSERT_DOUBLE_EQ(t.x(), 4.3);
  ASSERT_DOUBLE_EQ(t.y(), -4.2);
  ASSERT_DOUBLE_EQ(t.z(), 3.1);
  ASSERT_DOUBLE_EQ(t.w(), 1.0);

  ASSERT_TRUE(t.isPoint());
  ASSERT_FALSE(t.isVector());
}

TEST(TupleTest, TupleWithLastCoordEqualZeroIsAVector) {
  auto t = Tuple(4.3, -4.2, 3.1, 0.0);

  ASSERT_DOUBLE_EQ(t.x(), 4.3);
  ASSERT_DOUBLE_EQ(t.y(), -4.2);
  ASSERT_DOUBLE_EQ(t.z(), 3.1);
  ASSERT_DOUBLE_EQ(t.w(), 0.0);

  ASSERT_FALSE(t.isPoint());
  ASSERT_TRUE(t.isVector());
}

TEST(TupleTest, AddingTwoTuplesAddsCoordinates) {
  auto t1 = Tuple(4.3, -4.2, 3.1, 1.0);
  auto t2 = Tuple(4.3, -4.2, 3.1, 1.0);
  auto sum = t1 + t2;

  ASSERT_DOUBLE_EQ(sum.x(), t1.x() + t2.x());
  ASSERT_DOUBLE_EQ(sum.y(), t1.y() + t2.y());
  ASSERT_DOUBLE_EQ(sum.z(), t1.z() + t2.z());
  ASSERT_DOUBLE_EQ(sum.w(), t1.w() + t2.w());
}

TEST(TupleTest, SubtractingTwoTuplesSubtractsCoordinates) {
  auto t1 = Tuple(4.3, -4.2, 3.1, 1.0);
  auto t2 = Tuple(4.3, -4.2, 3.1, 1.0);
  auto diff = t1 - t2;

  ASSERT_DOUBLE_EQ(diff.x(), t1.x() - t2.x());
  ASSERT_DOUBLE_EQ(diff.y(), t1.y() - t2.y());
  ASSERT_DOUBLE_EQ(diff.z(), t1.z() - t2.z());
  ASSERT_DOUBLE_EQ(diff.w(), t1.w() - t2.w());
}

TEST(TupleTest, NegatingATupleNegatesCoordinates) {
  auto t = Tuple(1.0, 2.0, 3.0, 4.0);
  auto neg = -t;

  ASSERT_DOUBLE_EQ(-t.x(), neg.x());
  ASSERT_DOUBLE_EQ(-t.y(), neg.y());
  ASSERT_DOUBLE_EQ(-t.z(), neg.z());
  ASSERT_DOUBLE_EQ(-t.w(), neg.w());
}

TEST(TupleTest, TupleMultipliedByScalarMultipliesCoordinates) {
  auto t = Tuple(1.0, -2.0, 3.0, -4.0);
  auto s = 3.5;
  auto p = t * s;

  ASSERT_DOUBLE_EQ(s * t.x(), p.x());
  ASSERT_DOUBLE_EQ(s * t.y(), p.y());
  ASSERT_DOUBLE_EQ(s * t.z(), p.z());
  ASSERT_DOUBLE_EQ(s * t.w(), p.w());
}

TEST(TupleTest, TupleMultipliedByFractionMultipliesCoordinates) {
  auto t = Tuple(1.0, -2.0, 3.0, -4.0);
  auto s = 0.5;
  auto p = t * s;

  ASSERT_DOUBLE_EQ(s * t.x(), p.x());
  ASSERT_DOUBLE_EQ(s * t.y(), p.y());
  ASSERT_DOUBLE_EQ(s * t.z(), p.z());
  ASSERT_DOUBLE_EQ(s * t.w(), p.w());
}

TEST(TupleTest, TupleDividedByFractionDividesCoordinates) {
  auto t = Tuple(1.0, -2.0, 3.0, -4.0);
  auto s = 0.5;
  auto p = t / s;

  ASSERT_DOUBLE_EQ(s / t.x(), p.x());
  ASSERT_DOUBLE_EQ(s / t.y(), p.y());
  ASSERT_DOUBLE_EQ(s / t.z(), p.z());
  ASSERT_DOUBLE_EQ(s / t.w(), p.w());
}
