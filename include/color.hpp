/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** color
*/

#ifndef COLOR_H
    #define COLOR_H
    #include "./interval.hpp"
    #include "./vector3D.hpp"
    #include <iostream>

double linearToGamma(double linear_component);
void writeColor(std::ostream &out, const Color &pixel_color);

#endif
