/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** Sphere
*/

#ifndef SPHERE_H
    #define SPHERE_H
    #include "./APrimitive.hpp"
    #include "./vector3D.hpp"

class APrimitive;

class Sphere : public APrimitive {
    public:
        Sphere(const Point3D &center, double radius, std::shared_ptr<IMaterial> mat);
        bool hit(const Ray &r, Interval ray_t, HitRecord &rec) const;
        boundingBox applyBoundingBox() const;

    private:
        Point3D _center;
        double _radius;
        std::shared_ptr<IMaterial> _mat;
        boundingBox _bBox;
};

#endif
