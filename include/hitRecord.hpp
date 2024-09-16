/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** hitRecord
*/

#ifndef HITRECORD_HPP_
    #define HITRECORD_HPP_
    #include "./ray.hpp"

class IMaterial;

class HitRecord {
    public:
        void setFaceNormal(const Ray &r, const Vector3D &outward_normal);
        Point3D getP() const;
        Vector3D getNormal() const;
        std::shared_ptr<IMaterial> getPtr() const;
        double getT() const;
        bool getFrontFace() const;
        void setP(Point3D p);
        void setNormal(Vector3D n);
        void setPtr(std::shared_ptr<IMaterial> m);
        void setT(double t);
        double getU() const;
        double getV() const;
        void setU(double u);
        void setV(double v);

    private:
        Point3D _p;
        Vector3D _normal;
        std::shared_ptr<IMaterial> _mat;
        double _t;
        bool _frontFace;
        double _u;
        double _v;
};

#endif /* !HITRECORD_HPP_ */
