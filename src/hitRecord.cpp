/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** hitRecord
*/

#include "../include/hitRecord.hpp"

Point3D HitRecord::getP() const
{
    return _p;
}

Vector3D HitRecord::getNormal() const
{
    return _normal;
}

std::shared_ptr<IMaterial> HitRecord::getPtr() const
{
    return _mat;
}

double HitRecord::getT() const
{
    return _t;
}

bool HitRecord::getFrontFace() const
{
    return _frontFace;
}

void HitRecord::setP(Point3D p)
{
    _p = p;
}
void HitRecord::setNormal(Vector3D n)
{
    _normal = n;
}
void HitRecord::setPtr(std::shared_ptr<IMaterial> m)
{
    _mat = m;
}
void HitRecord::setT(double t)
{
    _t = t;
}

void HitRecord::setFaceNormal(const Ray &r, const Vector3D &exterior)
{
    _frontFace = false;
    if (dot(r.direction(), exterior) < 0)
        _frontFace = true;
    _normal = _frontFace ? exterior : -exterior;
}

double HitRecord::getU() const
{
    return _u;
}

double HitRecord::getV() const
{
    return _v;
}

void HitRecord::setU(double u)
{
    _u = u;
}

void HitRecord::setV(double v)
{
    _v = v;
}
