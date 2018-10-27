#ifndef __raytrace_src_point_h__
#define __raytrace_src_point_h__

#include <tuple.h>

class Point : public Tuple {
 public:
  Point() : Tuple(0, 0, 0, 1.0) {}
  Point(double x, double y, double z) : Tuple(x, y, z, 1.0) {}
};

#endif  // __raytrace_src_point_h__
