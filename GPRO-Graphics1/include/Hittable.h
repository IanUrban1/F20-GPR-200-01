#pragma once
#ifndef HITTABLE_H
#define HITTABLE_H

//Got assistane from Peter Shirley, Chapter 6.3 & 6.4 https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Using the framework provided by Mr.Buckstein
#include "Rays.h"


struct hit_record {
    point3 p;
    vec3 normal;
    double t = 0.0;

    //The four lines below set and make sure the normal 
    //is always pointing outward from an object's surface
    bool front_face = true;

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }

};

//This class computes the normal when something is hit
//Even if the hit object is closer than expected
//Whatever object is hit, set that to the normal
class hittable {
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif