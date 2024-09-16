/*
** EPITECH PROJECT, 2024
** raytracer_bis
** File description:
** camera
*/

#ifndef CAMERA_H
    #define CAMERA_H
    #include "./PrimitiveList.hpp"
    #include "./material.hpp"
    #include "./color.hpp"

class Camera {
    public:
        void render(const PrimitiveList &world);
        void initialize();
        Ray getRay(int i, int j) const;
        Vector3D sampleSquare() const;
        Point3D defocusDiskSample() const;
        Color rayColor(const Ray &r, int depth, const PrimitiveList &world) const;

        void setaspectRatio(double val) { _aspectRatio = val; };
        void setimageWidth(int val) { _imageWidth = val; };
        void setsamplesPerPixel(int val) { _samplesPerPixel = val; };
        void setmaxDepth(int val) { _maxDepth = val; };
        void setvFov(double val) { _vFov = val; };
        void setlookFrom(Point3D val) { _lookFrom = val; };
        void setlookAt(Point3D val) { _lookAt = val; };
        void setvUp(Vector3D val) { _vUp = val; };
        void setdefocusAngle(double val) { _defocusAngle = val; };
        void setfocusDistance(double val) { _focusDistance = val; };

        double getaspectRatio() const { return _aspectRatio; };
        int getimageWidth() const { return _imageWidth; };
        int getsamplesPerPixel() const { return _samplesPerPixel; };
        int getmaxDepth() const { return _maxDepth; };
        double getvFov() const { return _vFov; };
        Point3D getlookFrom() const { return _lookFrom; };
        Point3D getlookAt() const { return _lookAt; };
        Vector3D getvUp() const { return _vUp; };
        double getdefocusAngle() const { return _defocusAngle; };
        double getfocusDistance() const { return _focusDistance; };

        void setBackgroundColor(Color color) { _background = color; };
        Color getBackgroundColor() const { return _background; };

    private:
        double _aspectRatio = 1.0;
        int _imageWidth = 100;
        int _samplesPerPixel = 10;
        int _maxDepth = 10;
        double _vFov = 90;
        Point3D _lookFrom = Point3D(0,0,0);
        Point3D _lookAt = Point3D(0,0,-1);
        Vector3D _vUp = Vector3D(0,1,0);
        double _defocusAngle = 0;
        double _focusDistance = 10;
        int _imageHeight;
        double _pixelSamplesScale;
        Point3D _center;
        Point3D _originPixelLocation;
        Vector3D _pixelHorizontalDelta;
        Vector3D _pixelVerticalDelta;
        Vector3D _u;
        Vector3D _v;
        Vector3D _w;
        Vector3D _defocusHorizontalDisk;
        Vector3D _defocusVerticalDisk;
        Color _background;
};

#endif
