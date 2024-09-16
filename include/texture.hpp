/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** texture
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#include "./utilities.hpp"
#include "./color.hpp"
#include "./vector3D.hpp"

class ITexture {
  public:
    virtual ~ITexture() = default;

    virtual Color value(double u, double v, const Point3D& p) const = 0;
};

class SolidColor : public ITexture {
  public:
    SolidColor(const Color& albedo) : _color(albedo) {}
    SolidColor(double red, double green, double blue) : SolidColor(Color(red,green,blue)) {}
    Color value(double u, double v, const Point3D& p) const override { return _color; }

  private:
    Color _color;
};

#endif