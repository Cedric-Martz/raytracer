/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** APrimitive
*/

#ifndef APRIMITIVE_HPP_
    #define APRIMITIVE_HPP_
    #include "IPrimitive.hpp"
    #include "readFileConf.hpp"
    #include "material.hpp"
    #include <iostream>

class APrimitive : public IPrimitive {
    public:
        APrimitive();
        ~APrimitive();
        bool hit(const Ray &r, Interval ray_t, HitRecord &rec) const override;
        boundingBox applyBoundingBox() const override;
        static std::shared_ptr<APrimitive> createPrimitive(conf::Primitive *object, std::string material);
    private:
};

#endif /* !APRIMITIVE_HPP_ */
