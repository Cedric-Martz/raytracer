/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** IPrimitive
*/

#ifndef HITTABLE_H
    #define HITTABLE_H
    #include "./interval.hpp"
    #include "./hitRecord.hpp"
    #include "./boundingBox.hpp"

class IPrimitive {
    public:
        virtual ~IPrimitive() = default;
        virtual bool hit(const Ray &r, Interval ray_t, HitRecord &rec) const = 0;
        virtual boundingBox applyBoundingBox() const = 0;
};

#endif
