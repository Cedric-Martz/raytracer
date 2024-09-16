/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** Vector3D
*/

#ifndef Vector3D_H
    #define Vector3D_H
    #include <cmath>
    #include <iostream>
    #include "./utilities.hpp"

class Vector3D {
    public:
        Vector3D();
        Vector3D(double x, double y, double z);
        double x() const;
        double y() const;
        double z() const;
        Vector3D operator-() const;
        Vector3D &operator+=(const Vector3D &v);
        Vector3D &operator*=(double t);
        Vector3D &operator/=(double t);
        double length() const;
        double lengthSquared() const;
        bool nearZero() const;
        static Vector3D random();
        static Vector3D random(double min, double max);

    private:
        double _x;
        double _y;
        double _z;
};

using Point3D = Vector3D;
using Color = Vector3D;

std::ostream &operator<<(std::ostream &out, const Vector3D &v);
Vector3D operator+(const Vector3D &u, const Vector3D &v);
Vector3D operator-(const Vector3D &u, const Vector3D &v);
Vector3D operator*(const Vector3D &u, const Vector3D &v);
Vector3D operator*(double t, const Vector3D &v);
Vector3D operator*(const Vector3D &v, double t);
Vector3D operator/(const Vector3D &v, double t);
double dot(const Vector3D &u, const Vector3D &v);
Vector3D cross(const Vector3D &u, const Vector3D &v);
Vector3D unitVector(const Vector3D &v);
Vector3D randomHemisphere(const Vector3D &normal);
Vector3D reflect(const Vector3D &v, const Vector3D &n);
Vector3D refract(const Vector3D &uv, const Vector3D &n, double etat);
Vector3D randomUnitSphere();
Vector3D randomUnitVector();
Vector3D randomUnitDisk();

#endif
