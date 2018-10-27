#ifndef __raytrace_src_tuple_h__
#define __raytrace_src_tuple_h__

#include <array>

class Tuple {
 public:
  Tuple(double x, double y, double z, double w) { values_ = {x, y, z, w}; }

  bool isPoint() const { return values_[3] == 1.0; }
  bool isVector() const { return values_[3] == 0.0; }

  double x() const { return values_[0]; }
  double y() const { return values_[1]; }
  double z() const { return values_[2]; }
  double w() const { return values_[3]; }

  Tuple operator+(Tuple& t) const { return Tuple(x() + t.x(), y() + t.y(), z() + t.z(), w() + t.w()); }

  Tuple operator-(Tuple& t) const { return Tuple(x() - t.x(), y() - t.y(), z() - t.z(), w() - t.w()); }

  Tuple operator-() const { return Tuple(-x(), -y(), -z(), -w()); }

  Tuple operator*(double& scalar) const { return Tuple(scalar * x(), scalar * y(), scalar * z(), scalar * w()); }

  Tuple operator/(double& scalar) const { return Tuple(scalar / x(), scalar / y(), scalar / z(), scalar / w()); }

 protected:
  std::array<double, 4> values_ = {0};
};

#endif  // __raytrace_src_tuple_h__
