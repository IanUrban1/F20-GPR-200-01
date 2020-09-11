#pragma once
#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

//Got assistane from Peter Shirley, Chapter 6.7 https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Using the framework provided by Mr.Buckstein
// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants vars

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
//a function used to degrees to radians using the pi const variable 
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common Headers

#include "Rays.h"
#include "Vector.h"

#endif