#pragma once
#ifndef SPHERE_H
#define SPHERE_H

//Got assistane from Peter Shirley, Chapter 6.3 https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Using the framework provided by Mr.Buckstein
#include "Hittable.h"
#include "Vector.h"

class sphere : public hittable {
public:
    //creating the sphere and its parts(center and radius)
    sphere() {}
    sphere(point3 cen, double r) : center(cen), radius(r) {};

    //either sphere is hit by ray (true) or not(false)
    virtual bool hit(
        const ray& r, double tmin, double tmax, hit_record& rec) const override;

public:
    //member vars
    point3 center;
    double radius = 0.0;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    //setting important vars for later
    vec3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius * radius;
    double discriminant = half_b * half_b - a * c;

   //checking if the discriminant is greater than zero
    if (discriminant > 0) {
        //if it is then square root it and set the value to a local value for later use
        double root = sqrt(discriminant);

        //creating local double temp and then
        //setting its value to be the negative half_b value then subtracting it by the root value we just created
        //by square rooting the discriminant
        double temp = (-half_b - root) / a;

        //now if that temp value is less than the t_max and greater than the t_min
        //set it to an instance of hit_record
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            //surrface side determination(the ray points outward from the surface of the object) 
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);

            return true;
        }

        //now if that temp value is greater than the t_max and less than the t_min
       //set it to an instance of hit_record
        temp = (-half_b + root) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            //surrface side determination(the ray points outward from the surface of the object)
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
    }

    return false;
}


#endif