/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** Quad
*/

#ifndef QUAD_HPP
    #define QUAD_HPP
    #include "APrimitive.hpp"

class Plane : public APrimitive {
  public:
    Plane(const Point3D& Q, const Vector3D& u, const Vector3D& v, std::shared_ptr<IMaterial> mat)
      : _Q(Q), _u(u), _v(v), _mat(mat)
    {
        auto n = cross(u, v);
        _normal = unitVector(n);
        _D = dot(_normal, Q);
        _w = n / dot(n,n);
        setBoundingBox();
    }

    virtual void setBoundingBox();
    boundingBox applyBoundingBox() const override { return _bBox; }
    bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const;
    virtual bool isInterior(double a, double b, HitRecord& rec) const;

  private:
    Point3D _Q;
    Vector3D _u, _v;
    Vector3D _normal;
    Vector3D _w;
    double _D;
    std::shared_ptr<IMaterial> _mat;
    boundingBox _bBox;
};

#endif
