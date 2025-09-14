#include <iostream>
#include <string>

#include "point.h"
#include "circle.h"
#include "point3D.h"
#include "sphere.h"

//#define USER_INPUT
#define TESTS

#ifdef TESTS
bool test_0_1_the_radius_is_less_than_zero() {
    try {
        Circle<int> z1(3, 4, 0), z2(1, 3, -1);
    }
    catch (const std::exception& e) {
        //std::cerr << e.what() << std::endl;
        return 1;
    }
};

bool test_0_2_the_radius_is_less_than_zero() {
    try {
        Point<int> p1(0, 0), p2(10, -10);
        Circle<int> z1(p1, 0), z2(p2, -1);
    }
    catch (const std::exception& e) {
        //std::cerr << e.what() << std::endl;
        return 1;
    }
};

bool test_1_the_circles_match() {
    Circle<float> z1, z2;

    if (z1.check_relative_location(z2) == "The circles match") { return 1; }
};

bool test_2_do_not_intersect_or_touch() {
    Point<int> p1(0, 0), p2(10, -10);
    Circle<int> z1(p1, 1), z2(p2, 2);

    if (z1.check_relative_location(z2) == "The circles do not intersect or touch") { return 1; }
};

bool test_3_touch_at_one_point_externally() {
    Circle<int> z1(5, 5, 5), z2(-5, 5, 5);

    if (z1.check_relative_location(z2) == "The circles touch at one point (externally)") { return 1; }
};

bool test_4_1_intersect_at_two_points() {
    Circle<float> z1(-2.3f, -3.4f, 5.7f), z2(-1.2f, 1.0f, 2.7f);

    if (z1.check_relative_location(z2) == "The circles intersect at two points") { return 1; }
};

bool test_4_2_intersect_at_two_points() {
    Circle<int> z1(10, -2, 5), z2(6, -2, 2);

    if (z1.check_relative_location(z2) == "The circles intersect at two points") { return 1; }
};

bool test_5_1_one_circle_is_inside_the_other() {
    Circle<double> z1(-2.3, -3.4, 5.7), z2(-2.2, -3.3, 2.5);

    if (z1.check_relative_location(z2) == "One circle is inside the other") { return 1; }
};

bool test_5_2_one_circle_is_inside_the_other() {
    Circle<double> z1(-1.2, 3.4, 1.2), z2(-0.2, 3.4, 0.2);

    if (z1.check_relative_location(z2) == "One circle is inside the other") { return 1; }
};
#endif // TESTS

int main() {

#ifdef USER_INPUT
    try {
        Point<int> d;
        Circle<float> a, b;
        std::cout << "Enter first circle parameters (center_x center_y radius): ";
        std::cin >> a;
        std::cout << "Circle a: " << a << std::endl;

        std::cout << "Enter second circle parameters (center_x center_y radius): ";
        std::cin >> b;
        std::cout << "Circle b: " << b << std::endl;

        std::cout << a.check_relative_location(b) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

#endif // USER_INPUT

#ifdef TESTS
    if (test_0_1_the_radius_is_less_than_zero() == 1 &&
        test_0_2_the_radius_is_less_than_zero() == 1 &&
        test_1_the_circles_match() == 1 &&
        test_2_do_not_intersect_or_touch() == 1 &&
        test_3_touch_at_one_point_externally() == 1 &&
        test_4_1_intersect_at_two_points() == 1 &&
        test_4_2_intersect_at_two_points() == 1 &&
        test_5_1_one_circle_is_inside_the_other() == 1 &&
        test_5_2_one_circle_is_inside_the_other() == 1) { std::cout << "OK" << std::endl; }
#endif // TESTS
    return 0;
}
