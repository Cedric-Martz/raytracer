/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** color
*/

#include "../include/color.hpp"

double linearToGamma(double linearComponent)
{
    if (linearComponent > 0)
        return sqrt(linearComponent);

    return (0);
}

void writeColor(std::ostream &out, const Color &pixelColor)
{
    double r = linearToGamma(pixelColor.x());
    double g = linearToGamma(pixelColor.y());
    double b = linearToGamma(pixelColor.z());
    static const Interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
