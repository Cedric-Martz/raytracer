/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** sphere
*/

#include "../include/sphere.hpp"

Sphere::Sphere(const Point3D &center, double radius, std::shared_ptr<IMaterial> mat)
    : _center(center), _radius(fmax(0,radius)), _mat(mat)
{
    Vector3D rvec = Vector3D(radius, radius, radius);
    _bBox = boundingBox(_center - rvec, _center + rvec);
}

boundingBox Sphere::applyBoundingBox() const
{
    return _bBox;
}

bool Sphere::hit(const Ray &r, Interval rayT, HitRecord &rec) const
{
    Vector3D oc = _center - r.origin();
    double a = r.direction().lengthSquared();
    double h = dot(r.direction(), oc);
    double c = oc.lengthSquared() - _radius * _radius;
    double discriminant = h * h - a * c;

    if (discriminant < 0)
        return false;

    double sqrtd = sqrt(discriminant);
    double root = (h - sqrtd) / a;
    if (!rayT.surrounds(root)) {
        root = (h + sqrtd) / a;
        if (!rayT.surrounds(root))
            return false;
    }
    rec.setT(root);
    rec.setP(r.at(rec.getT()));
    Vector3D outward_normal = (rec.getP() - _center) / _radius;
    rec.setFaceNormal(r, outward_normal);
    rec.setPtr(_mat);
    return true;
}
