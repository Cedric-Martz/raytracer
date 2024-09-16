/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** AMaterial
*/

#include "../include/AMaterial.hpp"

AMaterial::AMaterial() {}

AMaterial::~AMaterial() {}

bool AMaterial::scatter(const Ray &rayIn, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    return false;
}

AMaterial::Error::Error(std::string error) : _error(error)
{
    std::cerr << _error << std::endl;
    exit(84);
}