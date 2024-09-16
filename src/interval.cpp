/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** interval
*/

#include "../include/interval.hpp"

Interval::Interval() : _min(+std::numeric_limits<double>::infinity()), _max(-std::numeric_limits<double>::infinity()) {}

Interval::Interval(double min, double max) : _min(min), _max(max) {}

Interval::Interval(const Interval& a, const Interval& b)
{
    _min = (a._min <= b._min) ? a._min : b._min;
    _max = (a._max >= b._max) ? a._max : b._max;
}

Interval Interval::_empty = Interval(+std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity());
Interval Interval::_universe = Interval(-std::numeric_limits<double>::infinity(), +std::numeric_limits<double>::infinity());

double Interval::size() const
{
    return _max - _min;
}

bool Interval::contains(double x) const
{
    return _min <= x && x <= _max;
}

bool Interval::surrounds(double x) const
{
    return _min < x && x < _max;
}

double Interval::clamp(double x) const
{
    if (x < _min)
        return _min;
    if (x > _max)
        return _max;
    return x;
}

Interval Interval::expand(double delta) const
{
    return Interval(_min - (delta / 2), _max + (delta / 2));
}

double Interval::getMin() const
{
    return _min;
}

double Interval::getMax() const
{
     return _max;
}

void Interval::setMin(double min)
{
    _min = min;
}

void Interval::setMax(double max)
{
    _max = max;
}

Interval Interval::getUniverse()
{
    return _universe;
}

Interval Interval::getEmpty()
{
    return _empty;
}
