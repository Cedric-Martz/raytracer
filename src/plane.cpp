/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** quad
*/

#include "../include/plane.hpp"

void Plane::setBoundingBox(void)
{
    auto bBoxDiagonal1 = boundingBox(_Q, _Q + _u + _v);
    auto bBoxDiagonal2 = boundingBox(_Q + _u, _Q + _v);
    _bBox = boundingBox(bBoxDiagonal1, bBoxDiagonal2);
}

bool Plane::hit(const Ray &ray, Interval intervalRay, HitRecord &record) const
{
    double denom = dot(_normal, ray.direction());

    if (fabs(denom) < 1e-8)
        return false;

    double t = (_D - dot(_normal, ray.origin())) / denom;
    if (!intervalRay.contains(t))
        return false;

    Point3D intersection = ray.at(t);
    Vector3D intersectionVector = intersection - _Q;
    double alpha = dot(_w, cross(intersectionVector, _v));
    double beta = dot(_w, cross(_u, intersectionVector));

    if (!isInterior(alpha, beta, record))
        return false;

    record.setT(t);
    record.setP(intersection);
    record.setPtr(_mat);
    record.setFaceNormal(ray, _normal);
    return true;
}

bool Plane::isInterior(double pointA, double pointB, HitRecord &hitRecord) const
{
    Interval unitInterval = Interval(0, 1);

    if (!unitInterval.contains(pointA) || !unitInterval.contains(pointB))
        return false;

    hitRecord.setU(pointA);
    hitRecord.setV(pointB);
    return true;
}
