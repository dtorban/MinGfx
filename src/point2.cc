#include "point2.h"

#include <math.h>

namespace MinGfx {

static const Point2 s_zerop2d = Point2(0,0);
static const Point2 s_onep2d = Point2(1,1);

const Point2& Point2::origin() { return s_zerop2d; }
const Point2& Point2::zero() { return s_zerop2d; }
const Point2& Point2::one() { return s_onep2d; }
    
    
Point2::Point2() {
    p[0] = 0.0;
    p[1] = 0.0;
}

Point2::Point2(float x, float y) {
    p[0] = x;
    p[1] = y;
}

Point2::Point2(float *ptr) {
    p[0] = ptr[0];
    p[1] = ptr[1];
}

Point2::Point2(const Point2& other) {
    p[0] = other[0];
    p[1] = other[1];
}

Point2::~Point2() {
}

bool Point2::operator==(const Point2& other) const {
    return (fabs(other[0] - p[0]) < MINGFX_MATH_EPSILON &&
            fabs(other[1] - p[1]) < MINGFX_MATH_EPSILON);
}

bool Point2::operator!=(const Point2& other) const {
    return (fabs(other[0] - p[0]) >= MINGFX_MATH_EPSILON ||
            fabs(other[1] - p[1]) >= MINGFX_MATH_EPSILON);
}

Point2& Point2::operator=(const Point2& other) {
    p[0] = other[0];
    p[1] = other[1];
    return *this;
}

float Point2::operator[](const int i) const {
    if ((i>=0) && (i<=1)) {
        return p[i];
    }
    else {
        // w component of a point is 1 so return the constant 1.0
        return 1.0;
    }
}

float& Point2::operator[](const int i) {
    return p[i];
}


const float * Point2::value_ptr() const {
    return p;
}


std::ostream & operator<< ( std::ostream &os, const Point2 &p) {
    return os << "(" << p[0] << ", " << p[1] << ")";
}

std::istream & operator>> ( std::istream &is, Point2 &p) {
    // format:  (x, y)
    char dummy;
    return is >> dummy >> p[0] >> dummy >> p[1] >> dummy;
}

    
} // end namespace