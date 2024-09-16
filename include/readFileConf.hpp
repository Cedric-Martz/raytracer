/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** readFileConf
*/

#ifndef READFILECONF_HPP_
    #define READFILECONF_HPP_
    #include <iostream>
    #include <list>
    #include <libconfig.h++>

namespace conf {

class Primitive {
    public:
        virtual ~Primitive() = default;
};

class Camera : public Primitive {
    public:
        Camera(libconfig::Config &cfg);
        ~Camera();
        int getViewPortW() const { return _viewPortW; };
        double getcamFromx() const { return _camFromx; };
        double getcamFromy() const { return _camFromy; };
        double getcamFromz() const { return _camFromz; };
        double getcamAtx() const { return _camAtx; };
        double getcamAty() const { return _camAty; };
        double getcamAtz() const { return _camAtz; };
        int getcamRotx() const { return _camRotx; };
        int getcamRoty() const { return _camRoty; };
        int getcamRotz() const { return _camRotz; };
        double getCamFov() const { return _camFov; };
        double getFocalLength() const { return _focalLength; };
        int getSPixel() const { return _sPerPixel; };
        int getDepth() const { return _depth; };
        double getVupx() const { return _camVupx; };
        double getVupy() const { return _camVupy; };
        double getVupz() const { return _camVupz; };
        double getFocusAngle() const { return _focusAngle; }
        double getFocusDistance() const { return _focusDistance; }
        auto getBackGround() const { return _backGround; }

    private:
        int _viewPortW;
        double _camFromx;
        double _camFromy;
        double _camFromz;
        double _camAtx;
        double _camAty;
        double _camAtz;
        int _camRotx;
        int _camRoty;
        int _camRotz;
        double _camFov;
        double _focalLength;
        int _sPerPixel;
        int _depth;
        double _camVupx;
        double _camVupy;
        double _camVupz;
        double _focusAngle;
        double _focusDistance;
        double _backGround[3];
};

class Sphere : public Primitive {
    public:
        Sphere();
        ~Sphere();
        double getposX() const { return _posX; };
        double getposY() const { return _posY; };
        double getposZ() const { return _posZ; };
        double getcolR() const { return _colR; };
        double getcolG() const { return _colG; };
        double getcolB() const { return _colB; };
        double getradius() const { return _radius; };
        std::string getMaterial() const { return _material; };
        void setPosX(double posX) { _posX = posX; };
        void setPosY(double posY) { _posY = posY; };
        void setPosZ(double posZ) { _posZ = posZ; };
        void setColR(double colR) { _colR = colR; };
        void setColG(double colG) { _colG = colG; };
        void setColB(double colB) { _colB = colB; };
        void setRadius(double radius) { _radius = radius; };
        void setMaterial(std::string material) { _material = material; };

    private:
        double _posX;
        double _posY;
        double _posZ;
        double _colR;
        double _colG;
        double _colB;
        double _radius;
        std::string _material;
};

class Plane : public Primitive{
    public:
        Plane();
        ~Plane();
        auto getQ() const { return _q; };
        auto getV() const { return _v; };
        auto getU() const { return _u; };
        std::string getMaterial() const { return _material; };
        auto getCol() const { return _col; };
        void setQ(double val, int i) { _q[i] = val; };
        void setV(double val, int i) { _v[i] = val; };
        void setU(double val, int i) { _u[i] = val; };
        void setCol(double val, int i) { _col[i] = val; };
        void setMaterial(std::string m) { _material = m; };

    private:
        double _q[3];
        double _v[3];
        double _u[3];
        double _col[3];
        std::string _material;
};

class Light {
    public:
        Light(std::string path);
        ~Light();
        int getAmbient() const { return _ambient; };
        int getdiffuse() const { return _diffuse; };
        int getPointLightX() const { return _PointLightX; };
        int getPointLightY() const { return _PointLightY; };
        int getPointLightZ() const { return _PointLightZ; };
        int getDirectionX() const { return _DirectionX; };
        int getDirectionY() const { return _DirectionY; };
        int getDirectionZ() const { return _DirectionZ; };

    private:
        int _ambient;
        int _diffuse;
        int _PointLightX;
        int _PointLightY;
        int _PointLightZ;
        int _DirectionX;
        int _DirectionY;
        int _DirectionZ;
};

void readFileFunc(char *filepath, libconfig::Config &cfg);
std::list<Sphere> getListSphere(libconfig::Config &cfg);
std::list<Plane> getListPlane(libconfig::Config &cfg);
}

#endif /* !READFILECONF_HPP_ */
