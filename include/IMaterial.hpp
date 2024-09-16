/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** IMaterial
*/

#ifndef IMATERIAL_HPP_
    #define IMATERIAL_HPP_
    #include "./IPrimitive.hpp"

class IMaterial {
    public:
        virtual ~IMaterial() = default;
        virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const = 0;
        virtual Color emitted(double u, double v, const Point3D& p) const { return Color(0,0,0); }
};

#endif /* !IMATERIAL_HPP_ */
