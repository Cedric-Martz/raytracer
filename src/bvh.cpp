/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** bvh
*/

#include "../include/bvh.hpp"

bool bvhNode::boxCompare(const std::shared_ptr<IPrimitive> primitiveA, const std::shared_ptr<IPrimitive> primitiveB, int indexAxis)
{
    auto intervalAAxis = primitiveA->applyBoundingBox().axisInterval(indexAxis);
    auto intervalBAxis = primitiveB->applyBoundingBox().axisInterval(indexAxis);

    return intervalAAxis.getMin() < intervalBAxis.getMin();
}

bool bvhNode::boxXCompare (const std::shared_ptr<IPrimitive> primitiveA, const std::shared_ptr<IPrimitive> primitiveB)
{
    return boxCompare(primitiveA, primitiveB, 0);
}

bool bvhNode::boxYCompare (const std::shared_ptr<IPrimitive> primitiveA, const std::shared_ptr<IPrimitive> primitiveB)
{
    return boxCompare(primitiveA, primitiveB, 1);
}

bool bvhNode::boxZCompare (const std::shared_ptr<IPrimitive> primitiveA, const std::shared_ptr<IPrimitive> primitiveB)
{
    return boxCompare(primitiveA, primitiveB, 2);
}

bvhNode::bvhNode(std::vector<std::shared_ptr<IPrimitive>>&& objects, size_t start, size_t end)
{
    _bBox = boundingBox::empty;
    for (size_t indexObject = start; indexObject < end; indexObject ++)
        _bBox = boundingBox(_bBox, objects[indexObject]->applyBoundingBox());

    int axis = _bBox.longestAxis();
    auto comparator = (axis == 0) ? boxXCompare
    : (axis == 1) ? boxYCompare
    : boxZCompare;

    size_t rangeOfObject = end - start;
    if (rangeOfObject == 1) {
        _left = _right = objects[start];
    } else if (rangeOfObject == 2) {
        _left = objects[start];
        _right = objects[start+1];
    } else {
        std::sort(objects.begin() + start, objects.begin() + end, comparator);
        auto mid = start + rangeOfObject / 2;
        _left = std::make_shared<bvhNode>(std::move(objects), start, mid);
        _right = std::make_shared<bvhNode>(std::move(objects), mid, end);
    }
}

bool bvhNode::hit(const Ray &ray, Interval rayInterval, HitRecord &rec) const
{
    if (!_bBox.hit(ray, rayInterval))
        return false;

    bool hitLeft = _left->hit(ray, rayInterval, rec);
    bool hitRight = _right->hit(ray, Interval(rayInterval.getMin(), hitLeft ? rec.getT() : rayInterval.getMax()), rec);

    return hitLeft || hitRight;
}
