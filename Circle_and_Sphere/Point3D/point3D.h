#pragma once

#include <iostream>
#include <cctype>

#include "point.h"
#include "point3D.h"

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

    template<class U>
    friend std::istream operator>>(std::istream&, Point3D<U>&);
};

template<class T>
Point3D<T>::Point3D() : _x(0), _y(0), _z(0) {}

template<class T>
Point3D<T>::Point3D(T x, T y, T z) : _x(x), _y(y), _z(z) {}

template<class T>
Point3D<T>::Point3D(const Point3D<T>& other) {
    _x = other._x;
    _y = other._y;
    _z = other._z;
}

template<class T>
Point3D<T>::Point3D(const Point<T>& other) {
    _x = other._x;
    _y = other._y;
    _z = T();
}

template<class T>
void Point3D<T>::set_z(T z) {
    if (!isdigit(x)) throw std::logic_error("Not a number entered!");
    _z = z;
}

template<class T>
T Point3D<T>::get_z() const { return _x; }

template<class U>
std::ostream operator<<(std::ostream&, const Point3D<U>& c) {
    out << "(" << point3D._x << ", " << point3D._y << ", " << point3D._z << ")";
    return out;
}

template<class U>
std::istream operator>>(std::istream&, Point3D<U>& point3D) {
    in >> point3D._x >> point3D._y >> point3D._z;
    return in;
}