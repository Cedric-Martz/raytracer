/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** PrimitiveList
*/

#include "../include/PrimitiveList.hpp"

void PrimitiveList::clear()
{
    _objects.clear();
}

void PrimitiveList::add(std::shared_ptr<IPrimitive> object)
{
    _objects.push_back(object);
    _bBox = boundingBox(_bBox, object->applyBoundingBox());
}

bool PrimitiveList::hit(const Ray &r, Interval ray, HitRecord &rec) const
{
    HitRecord tmpRecursive;
    bool hitSomething = false;
    double distanceToClosest = ray.getMax();

    for (const auto &object : _objects) {
        if (object->hit(r, Interval(ray.getMin(), distanceToClosest), tmpRecursive)) {
            hitSomething = true;
            distanceToClosest = tmpRecursive.getT();
            rec = tmpRecursive;
        }
    }
    return hitSomething;
}

boundingBox PrimitiveList::applyBoundingBox() const
{
    return _bBox;
}
