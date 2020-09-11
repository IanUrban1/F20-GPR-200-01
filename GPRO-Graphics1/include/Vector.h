#pragma once
//Got assistane from Peter Shirley, Chapter 3.1-3.3: https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Using the framework provided by Mr.Buckstein



#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
public:
    //creating the vec3 and setting values to double
    //note floats also work
    vec3() : e{ 0,0,0 } {}
    vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    //
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    //vec3 operator overloader for+=
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    //vec3 operator overloader for *= vec3s to doubles
    vec3& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    //vec3 operator/ (vec3 v, double t);

    //vec3 operator overloader for multiplying vec3s by doubles
    vec3 operator*(double t)
    {
        vec3 v;
        v.e[0] = e[0] * t;
        v.e[1] = e[1] * t;
        v.e[2] = e[2] * t;
        return v;
    }
    //vec3 operator overloader for dividing vec3s by doubles
    vec3& operator/(double t)
    {
        vec3 v;
        v.e[0] = e[0] / t;
        v.e[1] = e[1] / t;
        v.e[2] = e[2] / t;
    }

    //vec3 operator overloader for /= ve
    vec3& operator/=(const double t) {
        return *this *= 1 / t;
    }

    //function for returning the square root of the length
    double length() const {
        return sqrt(length_squared());
    }

    //
    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

    //create declaration for added operator overloaders

public:
    //member vars
    double e[3];
};

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

#endif

//vec3 Utility functions
//Each one of these are operator overload functions

//operator overloader for outputting
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//operator overloader for vec3 addition
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

//opertor overloader for vec3 substraction
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}
//operator overloader for vec3 multiplication
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}
//operator overloader for multiplying doubles by const vec3&
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

//operator overloader for multiplying doubles by const vec3&
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

//operator overloader for multiplying doubles by vec3
inline vec3 operator*(vec3& v, double t)
{
    return t * v;
}

//operator overloadr for 1/doubles multiplied by vec3
inline vec3 operator/(vec3 v, double t) {
    return (1 / t) * v;
}


inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}