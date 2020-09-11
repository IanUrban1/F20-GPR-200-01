#pragma once
//Got assistane from Peter Shirley, Chapter 3.1-3.3: https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Using the framework provided by Mr.Buckstein
#ifndef COLOR_H
#define COLOR_H

#include "Vector.h"

#include <iostream>
/*
    Color header is uses a utility function to write a single
    pixel's color to the output stream
*/
void write_color(std::ostream& out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif
