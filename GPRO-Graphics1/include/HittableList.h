#pragma once
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

//Got assistane from Peter Shirley, Chapter 6.5 https://raytracing.github.io/books/RayTracingInOneWeekend.html
//Using the framework provided by Mr.Buckstein

#include "Hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

//a class that stores hittable objects
class hittable_list : public hittable {
public:
    //creating the hittableList
    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    //clearing objects from list
    void clear() { objects.clear(); }
    //adding objects to list
    void add(shared_ptr<hittable> object) { objects.push_back(object); }


    virtual bool hit(
        const ray& r, double tmin, double tmax, hit_record& rec) const override;

public:
    //member var
    std::vector<shared_ptr<hittable>> objects;
};

//a boolean function used to check if any objects
//within the hittable_list have been hit
bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    //creating local vars for later
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    //a forloop that checks if any objects have been hit
    //if they have add them to the hit record
    for (const auto& object : objects) {
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    //return hit_anything even if nothing has been hit
    //if something has been hit this function will return true
    return hit_anything;
}

#endif