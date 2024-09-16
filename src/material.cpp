/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** material
*/

#include "../include/material.hpp"

bool Flat::scatter(const Ray &rayInside, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    Vector3D dispersionDirection = rec.getNormal() + randomUnitVector();
    scattered = Ray(rec.getP(), dispersionDirection);
    attenuation = _tex->value(rec.getU(), rec.getV(), rec.getP());;
    return true;
}

Metal::Metal(const Color &albedo, double fuzz) : _albedo(albedo), _fuzz(fuzz < 1 ? fuzz : 1) {}

bool Metal::scatter(const Ray &rayInside, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    Vector3D reflected = reflect(rayInside.direction(), rec.getNormal());
    reflected = unitVector(reflected) + (_fuzz * randomUnitVector());
    scattered = Ray(rec.getP(), reflected);
    attenuation = _albedo;
    return (dot(scattered.direction(), rec.getNormal()) > 0);
}

static double reflectance(double cosine, double indexOfRefraction) {
    double r0 = (1 - indexOfRefraction) / (1 + indexOfRefraction);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine),5);
}

Glass::Glass(double indexOfRefraction) : _refractionIndex(indexOfRefraction) {}

bool Glass::scatter(const Ray &rayInside, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    attenuation = Color(1.0, 1.0, 1.0);
    double ri = rec.getFrontFace() ? (1.0 / _refractionIndex) : _refractionIndex;
    Vector3D unit = unitVector(rayInside.direction());
    double cosinusTeta = fmin(dot(-unit, rec.getNormal()), 1.0);
    double sinusTeta = sqrt(1.0 - cosinusTeta * cosinusTeta);
    bool cantRefract = ri * sinusTeta > 1.0;
    Vector3D direction;

    if (cantRefract || reflectance(cosinusTeta, ri) > randomDouble())
        direction = reflect(unit, rec.getNormal());
    else
        direction = refract(unit, rec.getNormal(), ri);
    scattered = Ray(rec.getP(), direction);
    return true;
}

Light::Light(std::shared_ptr<ITexture> tex) : _tex(tex) {}

Light::Light(const Color &color) : _tex(std::make_shared<SolidColor>(color)) {}

Color Light::emitted(double u, double v, const Point3D &p) const
{
    return _tex->value(u, v, p);
}