#ifndef __raytrace_src_vector_h__
#define __raytrace_src_vector_h__

#include <tuple.h>

#include <cmath>

class Vector : public Tuple {
 public:
  Vector() : Tuple(0, 0, 0, 0.0) {}
  Vector(double x, double y, double z) : Tuple(x, y, z, 0.0) {}

  double magnitude() const {
    return sqrt(x()*x() + y()*y() + z()*z());
  }

  Vector normalize() const {
    auto m = magnitude();
    return Vector(x() / m, y() / m, z() / m);
  }

  double dot(const Vector& v) const {
    return v.x() * x() + v.y() * y() + v.z() * z();
  }

  Vector cross(const Vector& v) const {
    return Vector(y() * v.z() - z() * v.y(),
                  z() * v.x() - x() * v.z(),
                  x() * v.y() - y() * v.x());
  }
};

#endif  // __raytrace_src_vector_h__
