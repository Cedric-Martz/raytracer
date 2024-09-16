/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** readFileConf
*/

#include "../include/readFileConf.hpp"

namespace conf
{
    Camera::Camera(libconfig::Config &cfg)
    {
        cfg.lookupValue("camera.resolution.width", _viewPortW);
        cfg.lookupValue("camera.from.x", _camFromx);
        cfg.lookupValue("camera.from.y", _camFromy);
        cfg.lookupValue("camera.from.z", _camFromz);
        cfg.lookupValue("camera.at.x", _camAtx);
        cfg.lookupValue("camera.at.y", _camAty);
        cfg.lookupValue("camera.at.z", _camAtz);
        cfg.lookupValue("camera.rotation.x", _camRotx);
        cfg.lookupValue("camera.rotation.y", _camRoty);
        cfg.lookupValue("camera.rotation.z", _camRotz);
        cfg.lookupValue("camera.fieldOfView", _camFov);
        cfg.lookupValue("camera.focalLength", _focalLength);
        cfg.lookupValue("camera.sPerPixel", _sPerPixel);
        cfg.lookupValue("camera.depth", _depth);
        cfg.lookupValue("camera.vup.x", _camVupx);
        cfg.lookupValue("camera.vup.y", _camVupy);
        cfg.lookupValue("camera.vup.z", _camVupz);
        cfg.lookupValue("camera.focusAngle", _focusAngle);
        cfg.lookupValue("camera.focusDistance", _focusDistance);
        cfg.lookupValue("camera.background.r", _backGround[0]);
        cfg.lookupValue("camera.background.g", _backGround[1]);
        cfg.lookupValue("camera.background.b", _backGround[2]);
    }

    Camera::~Camera() {}

    Sphere::Sphere() {}

    Sphere::~Sphere() {}

    Plane::Plane() {}

    Plane::~Plane() {}

    Light::Light(std::string path)
    {
        libconfig::Config cfg;
        cfg.readFile(path.c_str());

        cfg.lookupValue("lights.ambient", _ambient);
        cfg.lookupValue("lights.diffuse", _diffuse);
        cfg.lookupValue("lights.point.x", _PointLightX);
        cfg.lookupValue("lights.point.y", _PointLightY);
        cfg.lookupValue("lights.point.z", _PointLightZ);
        cfg.lookupValue("lights.directional.x", _DirectionX);
        cfg.lookupValue("lights.directional.y", _DirectionY);
        cfg.lookupValue("lights.directional.z", _DirectionZ);
    }

    Light::~Light() {}

    void readFileFunc(char *filepath, libconfig::Config &cfg)
    {
        cfg.readFile(filepath);
    }

    std::list<conf::Sphere> getListSphere(libconfig::Config &cfg)
    {
        const libconfig::Setting &primitives = cfg.lookup("primitives");
        const libconfig::Setting &spheresSetting = primitives["spheres"];

        double val;
        std::string material;
        std::list<conf::Sphere> sp;
        for (int i = 0; i < spheresSetting.getLength(); i++) {
            conf::Sphere newSphere;

            spheresSetting[i].lookupValue("x", val);
            newSphere.setPosX(val);
            spheresSetting[i].lookupValue("y", val);
            newSphere.setPosY(val);
            spheresSetting[i].lookupValue("z", val);
            newSphere.setPosZ(val);
            spheresSetting[i].lookupValue("r", val);
            newSphere.setRadius(val);
            spheresSetting[i].lookupValue("material", material);
            newSphere.setMaterial(material);

            const libconfig::Setting &colorSetting = spheresSetting[i]["color"];
            colorSetting.lookupValue("r", val);
            newSphere.setColR(val);
            colorSetting.lookupValue("g", val);
            newSphere.setColG(val);
            colorSetting.lookupValue("b", val);
            newSphere.setColB(val);
            sp.push_back(newSphere);
        }
        return sp;
    }

    std::list<conf::Plane> getListPlane(libconfig::Config &cfg)
    {
        const libconfig::Setting &primitives = cfg.lookup("primitives");
        const libconfig::Setting &planesSetting = primitives["planes"];

        std::list<conf::Plane> pl;
        double val;
        std::string material;
        for (int i = 0; i < planesSetting.getLength(); i++) {
            conf::Plane newplane;

            planesSetting[i].lookupValue("qx", val);
            newplane.setQ(val, 0);
            planesSetting[i].lookupValue("qy", val);
            newplane.setQ(val, 1);
            planesSetting[i].lookupValue("qz", val);
            newplane.setQ(val, 2);

            planesSetting[i].lookupValue("vx", val);
            newplane.setV(val, 0);
            planesSetting[i].lookupValue("vy", val);
            newplane.setV(val, 1);
            planesSetting[i].lookupValue("vz", val);
            newplane.setV(val, 2);

            planesSetting[i].lookupValue("ux", val);
            newplane.setU(val, 0);
            planesSetting[i].lookupValue("uy", val);
            newplane.setU(val, 1);
            planesSetting[i].lookupValue("uz", val);
            newplane.setU(val, 2);

            const libconfig::Setting &colorSetting = planesSetting[i]["color"];
            colorSetting.lookupValue("r", val);
            newplane.setCol(val, 0);
            colorSetting.lookupValue("g", val);
            newplane.setCol(val, 1);
            colorSetting.lookupValue("b", val);
            newplane.setCol(val, 2);
            planesSetting[i].lookupValue("material", material);
            newplane.setMaterial(material);

            pl.push_back(newplane);
        }
        return pl;
    }
}
