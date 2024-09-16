/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** PrimitiveList
*/

#ifndef HITTABLE_LIST_H
    #define HITTABLE_LIST_H
    #include "./APrimitive.hpp"
    #include "./boundingBox.hpp"
    #include <memory>
    #include <vector>

class PrimitiveList : public APrimitive {
    public:
        PrimitiveList() {}
        PrimitiveList(std::shared_ptr<IPrimitive> object) { add(object); }
        void clear();
        void add(std::shared_ptr<IPrimitive> object);
        bool hit(const Ray &ray, Interval intervalRay, HitRecord &record) const override;
        std::vector<std::shared_ptr<IPrimitive>> getObj() const { return _objects; };
        boundingBox applyBoundingBox() const override;

    private:
        boundingBox _bBox;
        std::vector<std::shared_ptr<IPrimitive>> _objects;
};

#endif
