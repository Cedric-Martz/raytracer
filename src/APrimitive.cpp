/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** APrimitive
*/

#include "../include/APrimitive.hpp"
#include "../include/sphere.hpp"
#include "../include/plane.hpp"

APrimitive::APrimitive()
{
}

APrimitive::~APrimitive()
{
}

bool APrimitive::hit(const Ray &ray, Interval rayInterval, HitRecord &record) const
{
    return false;
}

boundingBox APrimitive::applyBoundingBox() const
{
    return boundingBox();
}

std::shared_ptr<APrimitive> APrimitive::createPrimitive(conf::Primitive *object, std::string material)
{
    if (conf::Sphere *obj = dynamic_cast<conf::Sphere *>(object)) {
        if (material == "flat") {
            auto material = std::make_shared<Flat>(Color(obj->getcolR(),obj->getcolG(),obj->getcolB()));
            return (std::make_shared<Sphere>(Point3D(obj->getposX(),obj->getposY(),obj->getposZ()), obj->getradius(), material));
        }
        if (material == "glass") {
            auto material = std::make_shared<Glass>(obj->getcolR());
            return (std::make_shared<Sphere>(Point3D(obj->getposX(),obj->getposY(),obj->getposZ()),obj->getradius(), material));
        }
        if (material == "metal") {
            auto material = std::make_shared<Metal>(Color(obj->getcolR(),obj->getcolG(),obj->getcolB()), 0.0);
            return (std::make_shared<Sphere>(Point3D(obj->getposX(),obj->getposY(),obj->getposZ()), obj->getradius(), material));
        }
        if (material == "light") {
            auto material = std::make_shared<Light>(Color(obj->getcolR(),obj->getcolG(),obj->getcolB()));
            return (std::make_shared<Sphere>(Point3D(obj->getposX(),obj->getposY(),obj->getposZ()), obj->getradius(), material));
        }
    }
    if (conf::Plane *obj = dynamic_cast<conf::Plane *>(object)) {
        if (material == "flat") {
            auto material = std::make_shared<Flat>(Color(obj->getCol()[0],obj->getCol()[1],obj->getCol()[2]));
            return (std::make_shared<Plane>(Point3D(obj->getQ()[0], obj->getQ()[1], obj->getQ()[2]),
            Vector3D(obj->getV()[0], obj->getV()[1], obj->getV()[2]),
            Vector3D(obj->getU()[0], obj->getU()[1], obj->getU()[2]), material));
        }
        if (material == "light") {
            auto material = std::make_shared<Light>(Color(obj->getCol()[0],obj->getCol()[1],obj->getCol()[2]));
            return (std::make_shared<Plane>(Point3D(obj->getQ()[0], obj->getQ()[1], obj->getQ()[2]),
            Vector3D(obj->getV()[0], obj->getV()[1], obj->getV()[2]),
            Vector3D(obj->getU()[0], obj->getU()[1], obj->getU()[2]), material));
        }
    }
    return nullptr;
}
