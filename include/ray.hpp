/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** ray
*/

#ifndef RAY_H
    #define RAY_H
    #include "vector3D.hpp"

class Ray {
    public:
        Ray();
        Ray(const Point3D &origin, const Vector3D &direction);
        const Point3D &origin() const;
        const Vector3D &direction() const;
        Point3D at(double t) const;

    private:
        Point3D _orig;
        Vector3D _dir;
};

#endif
