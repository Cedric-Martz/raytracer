/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** boundingBox
*/

#include "../include/boundingBox.hpp"

boundingBox::boundingBox(const Interval &x, const Interval &y, const Interval &z)
    : _x(x), _y(y), _z(z)
{
    padToMinimum();
}

boundingBox::boundingBox(const Point3D &a, const Point3D &b)
{
    _x = (a.x() <= b.x()) ? Interval(a.x(), b.x()) : Interval(b.x(), a.x());
    _y = (a.y() <= b.y()) ? Interval(a.y(), b.y()) : Interval(b.y(), a.y());
    _z = (a.z() <= b.z()) ? Interval(a.z(), b.z()) : Interval(b.z(), a.z());

    padToMinimum();
}

boundingBox::boundingBox(const boundingBox &box0, const boundingBox &box1)
{
    _x = Interval(box0._x, box1._x);
    _y = Interval(box0._y, box1._y);
    _z = Interval(box0._z, box1._z);
}

const Interval& boundingBox::axisInterval(int n) const
{
    if (n == 1)
        return _y;
    if (n == 2)
        return _z;
    return _x;
}

bool boundingBox::hit(const Ray& r, Interval ray) const
{
    const Point3D &originRay = r.origin();
    const Vector3D &directionRay  = r.direction();
    const Interval &ax = _x;
    double adinv = 1.0 / directionRay.x();
    double t0 = (ax.getMin() - originRay.x()) * adinv;
    double t1 = (ax.getMax() - originRay.x()) * adinv;

    for (int i = 0; i < 3; i++) {
        if (i) {
            const Interval &ax = _y;
            adinv = 1.0 / directionRay.y();
            t0 = (ax.getMin() - originRay.y()) * adinv;
            t1 = (ax.getMax() - originRay.y()) * adinv;
        }
        if (i == 2) {
            const Interval &ax = _z;
            adinv = 1.0 / directionRay.z();
            t0 = (ax.getMin() - originRay.z()) * adinv;
            t1 = (ax.getMax() - originRay.z()) * adinv;
        }
        if (t0 < t1) {
            if (t0 > ray.getMin())
                ray.setMin(t0);
            if (t1 < ray.getMax())
                ray.setMax(t1);
        } else {
            if (t1 > ray.getMin())
                ray.setMin(t1);
            if (t0 < ray.getMax())
                ray.setMax(t0);
        }
        if (ray.getMax() <= ray.getMin())
            return false;
    }
    return true;
}

void boundingBox::padToMinimum()
{
    double delta = 0.0001;
    if (_x.size() < delta) _x = _x.expand(delta);
    if (_y.size() < delta) _y = _y.expand(delta);
    if (_z.size() < delta) _z = _z.expand(delta);
}

int boundingBox::longestAxis() const
{
    if (_x.size() > _y.size())
        return _x.size() > _z.size() ? 0 : 2;
    else
        return _y.size() > _z.size() ? 1 : 2;
}

const boundingBox boundingBox::empty    = boundingBox(Interval::getEmpty(),    Interval::getEmpty(),    Interval::getEmpty());
const boundingBox boundingBox::universe = boundingBox(Interval::getUniverse(), Interval::getUniverse(), Interval::getUniverse());
