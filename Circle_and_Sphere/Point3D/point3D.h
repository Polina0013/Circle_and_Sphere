#pragma once

#include <iostream>
#include <cctype>

#include "point.h"

template<class T>
class Point3D : Point {
    T _z;
public:
    Point3D();
    Point3D(T x, T y, T z);
    Point3D(const Point3D<T>& other);
    Point3D(const Point<T>& other);

    void set_z(T z);

    T get_z() const;

    template<class U>
    friend std::ostream operator<<(std::ostream&, const Point3D<U>&);

    template<vlass U>
    friend std::istream operator>>(std::istream&, Point3D<U>&);
};