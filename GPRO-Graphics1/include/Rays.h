#pragma once
//Got assistane from Peter Shirley, Chapter 4.1-4.2: https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Using the framework provided by Mr.Buckstein
#ifndef RAY_H
#define RAY_H

#include "Vector.h"

//class ray is used 
class ray {
public:
    //creating and defining the ray class
    ray() {}
    ray(const point3& origin, const vec3& direction)
        : orig(origin), dir(direction)
    {}

    //return the orgin and direction of the ray
    point3 origin() const { return orig; }
    vec3 direction() const { return dir; }

    //using the equation P(t)(position along a line in 3D) = A(ray origin) + t(real number, normally a double)b(ray direction)
    //If you plug in a different t value and P(t) or the position along the line will move
    //Positive values will point you in front of A, whereas negative t values will point you behind A
    point3 at(double t) const {
        return orig + t * dir;
    }

public:
    //member vars
    point3 orig;
    vec3 dir;
};

#endif