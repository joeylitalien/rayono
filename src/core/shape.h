// core/shape.h
#ifndef RT_CORE_SHAPE_H
#define RT_CORE_SHAPE_H

#include "raytracer.h"
#include "geometry.h"

// New material type declaration
// DIFFuse (most objects), SPECular (e.g. mirror) or REFRactive (e.g. glass)
enum Mat_t { DIFF, SPEC, REFR };

// Shape class declaration
// Position p, emission e, color c
// Material m (diffuse, specular, refraction)
class Shape {
public:
  Shape(const Vec &p_, const Vec &e_, const Vec &c_, const Mat_t &m_)
    : p(p_), e(e_), c(c_), m(m_) {}
  virtual ~Shape() {}
  virtual double Intersect(const Ray &ray) const;

  Vec p, e, c;
  Mat_t m;
};

// Sphere subclass declaration
// Sphere of radius r
class Sphere : public Shape {
public:
  Sphere(const double &r_, const Vec &p_, const Vec &e_, const Vec &c_,
         const Mat_t &m_)
    : r(r_), Shape(p_, e_, c_, m_) {}
  double Intersect(const Ray &ray) const;

  double r;
};

// Cube subclass declaration
// Cube of length l
class Cube : public Shape {
public:
  Cube(const double &l_, const Vec &p_, const Vec &e_, const Vec &c_,
         const Mat_t &m_)
    : l(l_), Shape(p_, e_, c_, m_) {}
  double Intersect(const Ray &ray) const;

  double l;
};

#endif   // RT_CORE_SHAPE_H
