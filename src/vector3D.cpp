/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** vector3D
*/

#include "../include/vector3D.hpp"

Vector3D::Vector3D() : _x(0), _y(0), _z(0) {}

Vector3D::Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

double Vector3D::x() const
{
    return _x;
}

double Vector3D::y() const
{
    return _y;
}

double Vector3D::z() const
{
    return _z;
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-_x, -_y, -_z);
}

Vector3D &Vector3D::operator+=(const Vector3D &v)
{
    this->_x += v._x;
    this->_y += v._y;
    this->_z += v._z;
    return *this;
}

Vector3D &Vector3D::operator*=(double t)
{
    this->_x *= t;
    this->_y *= t;
    this->_z *= t;
    return *this;
}

Vector3D &Vector3D::operator/=(double t)
{
    this->_x /= t;
    this->_y /= t;
    this->_z /= t;
    return *this;
}

double Vector3D::lengthSquared() const
{
    return _x * _x + _y * _y + _z * _z;
}

double Vector3D::length() const
{
    return sqrt(lengthSquared());
}

bool Vector3D::nearZero() const
{
    double s = 1e-8;
    return (fabs(_x) < s) && (fabs(_y) < s) && (fabs(_z) < s);
}

Vector3D Vector3D::random()
{
    return Vector3D(randomDouble(), randomDouble(), randomDouble());
}

Vector3D Vector3D::random(double min, double max)
{
    return Vector3D(randomDouble(min,max), randomDouble(min,max), randomDouble(min,max));
}

std::ostream &operator<<(std::ostream &out, const Vector3D &v)
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

Vector3D operator+(const Vector3D &u, const Vector3D &v)
{
    return Vector3D(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

Vector3D operator-(const Vector3D &u, const Vector3D &v)
{
    return Vector3D(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

Vector3D operator*(const Vector3D &u, const Vector3D &v)
{
    return Vector3D(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

Vector3D operator*(double t, const Vector3D &v)
{
    return Vector3D(t * v.x(), t * v.y(), t * v.z());
}

Vector3D operator*(const Vector3D &v, double t)
{
    return t * v;
}

Vector3D operator/(const Vector3D &v, double t)
{
    return (1 / t) * v;
}

double dot(const Vector3D &u, const Vector3D &v)
{
    return u.x() * v.x()
         + u.y() * v.y()
         + u.z() * v.z();
}

Vector3D cross(const Vector3D &u, const Vector3D &v)
{
    return Vector3D(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

Vector3D unitVector(const Vector3D &v)
{
    return v / v.length();
}

Vector3D randomUnitSphere()
{
    while (true) {
        auto p = Vector3D::random(-1,1);
        if (p.lengthSquared() < 1)
            return p;
    }
}

Vector3D randomUnitVector()
{
    return unitVector(randomUnitDisk());
}

Vector3D randomHemisphere(const Vector3D &normal)
{
    Vector3D onUnitSphere = randomUnitVector();
    if (dot(onUnitSphere, normal) > 0.0)
        return onUnitSphere;
    else
        return -onUnitSphere;
}

Vector3D reflect(const Vector3D &v, const Vector3D &n)
{
    return v - 2 * dot(v,n) * n;
}

Vector3D refract(const Vector3D &uv, const Vector3D &n, double etat)
{
    double cosTheta = fmin(dot(-uv, n), 1.0);
    Vector3D rOutPerp =  etat * (uv + cosTheta * n);
    Vector3D rOutParallel = -sqrt(fabs(1.0 - rOutPerp.lengthSquared())) * n;
    return rOutPerp + rOutParallel;
}

Vector3D randomUnitDisk()
{
    while (1) {
        Vector3D p = Vector3D(randomDouble(-1,1), randomDouble(-1,1), 0);
        if (p.lengthSquared() < 1)
            return p;
    }
}
