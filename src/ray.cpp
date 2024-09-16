/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** ray
*/

#include "../include/ray.hpp"

Ray::Ray() {}

Ray::Ray(const Point3D &origin, const Vector3D &direction) : _orig(origin), _dir(direction) {}
const Point3D &Ray::origin() const
{
    return _orig;
}

const Vector3D &Ray::direction() const
{
    return _dir;
}

Point3D Ray::at(double t) const
{
    return _orig + t * _dir;
}
