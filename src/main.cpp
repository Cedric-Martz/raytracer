/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** main
*/

#include "../include/vector3D.hpp"
#include "../include/color.hpp"
#include "../include/IPrimitive.hpp"
#include "../include/PrimitiveList.hpp"
#include "../include/sphere.hpp"
#include "../include/camera.hpp"
#include "../include/material.hpp"
#include "../include/readFileConf.hpp"
#include "../include/bvh.hpp"
#include "../include/plane.hpp"

static void addPrimitivesToWorld(PrimitiveList &world, libconfig::Config &cfg)
{
    std::list<conf::Sphere> sp = conf::getListSphere(cfg);
    std::list<conf::Plane> pl = conf::getListPlane(cfg);

    for(auto &sphere : sp) {
        auto primitive = APrimitive::createPrimitive(&sphere, sphere.getMaterial());
        world.add(primitive);
    }
    for(auto &plane : pl) {
        auto primitive = APrimitive::createPrimitive(&plane, plane.getMaterial());
        world.add(primitive);
    }
}

static void renderWorld(PrimitiveList &world, libconfig::Config &cfg)
{
    Camera cam;
    conf::Camera c(cfg);

    cam.setaspectRatio(16.0 / 9.0);
    cam.setimageWidth(c.getViewPortW());
    cam.setsamplesPerPixel(c.getSPixel());
    cam.setmaxDepth(c.getDepth());
    cam.setvFov(c.getCamFov());
    cam.setlookFrom(Point3D(c.getcamFromx(), c.getcamFromy(), c.getcamFromz()));
    cam.setlookAt(Point3D(c.getcamAtx(), c.getcamAty(), c.getcamAtz()));
    cam.setvUp(Vector3D(c.getVupx(), c.getVupy(), c.getVupz()));
    cam.setdefocusAngle(c.getFocusAngle());
    cam.setfocusDistance(c.getFocusDistance());
    cam.setBackgroundColor(Color(c.getBackGround()[0], c.getBackGround()[1], c.getBackGround()[2]));
    cam.render(world);
}

int main(int ac, char **av)
{
    PrimitiveList world;
    libconfig::Config cfg;

    if (ac != 2)
        throw AMaterial::Error("Invalid number of arguments");
    conf::readFileFunc(av[1], cfg);
    addPrimitivesToWorld(world, cfg);

    renderWorld(world, cfg);
}
