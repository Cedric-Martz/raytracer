/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** boundingBox
*/

#ifndef BOUNDINGBOX_HPP
    #define BOUNDINGBOX_HPP
    #include "./vector3D.hpp"
    #include "./interval.hpp"
    #include "./ray.hpp"

class boundingBox {
    public:
        boundingBox() {};
        boundingBox(const Interval &x, const Interval &y, const Interval &z);
        boundingBox(const Point3D &a, const Point3D &b);
        boundingBox(const boundingBox &box0, const boundingBox &box1);
        const Interval& axisInterval(int n) const;
        bool hit(const Ray &r, Interval ray_t) const;
        int longestAxis() const;
        static const boundingBox empty, universe;

    private:
        Interval _x;
        Interval _y;
        Interval _z;
        void padToMinimum();
};

#endif
