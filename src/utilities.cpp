/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** utilities
*/

#include "../include/utilities.hpp"

double degreesToRadians(double degrees)
{
    return degrees * M_PI / 180.0;
}

double randomDoubleGenerator() {
    static thread_local std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static thread_local std::mt19937 generator(std::random_device{}());
    return distribution(generator);
}

double randomDouble()
{
    return rand() / (RAND_MAX + 1.0);
}

double randomDouble(double min, double max)
{
    return min + (max-min) * randomDoubleGenerator();
}
