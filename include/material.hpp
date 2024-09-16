/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** material
*/

#ifndef MATERIAL_H
    #define MATERIAL_H
    #include "./IPrimitive.hpp"
    #include "./AMaterial.hpp"
    #include "./texture.hpp"

class Flat : public AMaterial {
    public:
        Flat(const Color &color) : _tex(std::make_shared<SolidColor>(color)) {}
        bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override;

    private:
        std::shared_ptr<ITexture> _tex;
};

class Metal : public AMaterial {
    public:
        Metal(const Color &albedo, double fuzz);
        bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override;

    private:
        Color _albedo;
        double _fuzz;
};

class Glass : public AMaterial {
    public:
        Glass(double refraction_index);
        bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const override;

    private:
        double _refractionIndex;
};

class Light : public AMaterial {
    public:
        Light(std::shared_ptr<ITexture> tex);
        Light(const Color &color);
        Color emitted(double u, double v, const Point3D &p) const override;
    private:
        std::shared_ptr<ITexture> _tex;
};

#endif
