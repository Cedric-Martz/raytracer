/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** interval
*/

#ifndef INTERVAL_H
    #define INTERVAL_H
    #include "./utilities.hpp"

class Interval {
    public:
        Interval();
        Interval(double min, double max);
        Interval(const Interval &a, const Interval &b);
        double size() const;
        bool contains(double x) const;
        bool surrounds(double x) const;
        double clamp(double x) const;
        Interval expand(double delta) const;
        double getMin() const;
        double getMax() const;
        void setMin(double min);
        void setMax(double max);
        static Interval getUniverse();
        static Interval getEmpty();

    private:
        double _min;
        double _max;
        static Interval _universe;
        static Interval _empty;
};

#endif
