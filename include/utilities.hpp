/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** utilities
*/

#ifndef RTWEEKEND_H
    #define RTWEEKEND_H
    #include <cmath>
    #include <cstdlib>
    #include <iostream>
    #include <limits>
    #include <memory>
    #include <random>
    #include <algorithm>

const double infinity = std::numeric_limits<double>::infinity();
double randomDouble(double min, double max);
double randomDouble();
double randomDoubleGenerator();
double degreesToRadians(double degrees);

#endif
