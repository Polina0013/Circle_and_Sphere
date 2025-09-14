#pragma once

#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
#include "point.h"
#include "point3D.h"

template<class T>
class Sphere : Point3D {
    Point3D<T> _center;
    T _radius;
public:
    Sphere();
    Sphere(Point3D<T> center, T radius);
    Sphere(T center_x, T center_y, T center_z, T radius);
    Sphere(const Sphere<T>& other);

    void set_center(Point3D<T> center);
    void set_radius(T radius);

    Point3D<T> get_center() const;
    T get_radius() const;

    template<U>
    friend std::ostream& operator<<(std::ostream&, const Sphere<U>&);

    template<U>
    friend std::istream& operator>>(std::istream&, const Sphere<U>&);

};