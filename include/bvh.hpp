/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** bvh
*/

#ifndef BVH_HPP
    #define BVH_HPP
    #include "PrimitiveList.hpp"

class bvhNode : public IPrimitive {
    public:
        bvhNode(PrimitiveList list) : bvhNode(std::move(list.getObj()), 0, list.getObj().size()) {}
        bvhNode(std::vector<std::shared_ptr<IPrimitive>>&& objects, size_t start, size_t end);

        bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;
        boundingBox applyBoundingBox() const override { return _bBox; }
        static bool boxCompare(const std::shared_ptr<IPrimitive> primitiveA, const std::shared_ptr<IPrimitive> primitiveB, int axis_index);
        static bool boxXCompare (const std::shared_ptr<IPrimitive> primitiveA, const std::shared_ptr<IPrimitive> primitiveB);
        static bool boxYCompare (const std::shared_ptr<IPrimitive> primitiveA, const std::shared_ptr<IPrimitive> primitiveB);
        static bool boxZCompare (const std::shared_ptr<IPrimitive> primitiveA, const std::shared_ptr<IPrimitive> primitiveB);

    private:
        std::shared_ptr<IPrimitive> _left;
        std::shared_ptr<IPrimitive> _right;
        boundingBox _bBox;
};

#endif
