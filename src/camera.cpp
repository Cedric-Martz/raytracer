/*
** EPITECH PROJECT, 2024
** B-OOP-400-STG-4-1-raytracer-cedric.martz
** File description:
** camera
*/

#include "../include/camera.hpp"

void Camera::render(const PrimitiveList& world)
{
    initialize();

    std::cout << "P3\n" << _imageWidth << ' ' << _imageHeight << "\n255\n";

    for (int j = 0; j < _imageHeight; j++) {
        std::clog << "\rProgress: " << (((((_imageHeight - j) * 100) / _imageHeight) - 100) * (-1)) << "% " << std::flush;
        for (int i = 0; i < _imageWidth; i++) {
            Color pixelColor(0,0,0);
            for (int sample = 0; sample < _samplesPerPixel; sample++) {
                Ray r = getRay(i, j);
                pixelColor += rayColor(r, _maxDepth, world);
            }
            writeColor(std::cout, _pixelSamplesScale * pixelColor);
        }
    }
    std::clog << "\rDone.                   \n";
}

void Camera::initialize()
{
    _imageHeight = int(_imageWidth / _aspectRatio);
    _imageHeight = (_imageHeight < 1) ? 1 : _imageHeight;
    _pixelSamplesScale = 1.0 / _samplesPerPixel;
    _center = _lookFrom;
    double theta = degreesToRadians(_vFov);
    double h = tan(theta / 2);
    double viewportHeight = 2 * h * _focusDistance;
    double viewportWidth = viewportHeight * (double(_imageWidth) / _imageHeight);
    _w = unitVector(_lookFrom - _lookAt);
    _u = unitVector(cross(_vUp, _w));
    _v = cross(_w, _u);
    Vector3D horizontalViewport = viewportWidth * _u;
    Vector3D viewport_v = viewportHeight * -_v;
    _pixelHorizontalDelta = horizontalViewport / _imageWidth;
    _pixelVerticalDelta = viewport_v / _imageHeight;
    Vector3D topLeftViewport = _center - (_focusDistance * _w) - horizontalViewport / 2 - viewport_v / 2;
    _originPixelLocation = topLeftViewport + 0.5 * (_pixelHorizontalDelta + _pixelVerticalDelta);
    double defocusRadius = _focusDistance * tan(degreesToRadians(_defocusAngle / 2));
    _defocusHorizontalDisk = _u * defocusRadius;
    _defocusVerticalDisk = _v * defocusRadius;
}

Ray Camera::getRay(int i, int j) const
{
    Vector3D offset = sampleSquare();
    Vector3D pixelSample = _originPixelLocation + ((i + offset.x()) * _pixelHorizontalDelta)
                        + ((j + offset.y()) * _pixelVerticalDelta);

    Vector3D rayOrigin = (_defocusAngle <= 0) ? _center : defocusDiskSample();
    Vector3D rayDirection = pixelSample - rayOrigin;
    return Ray(rayOrigin, rayDirection);
}

Vector3D Camera::sampleSquare() const
{
    return Vector3D(randomDouble() - 0.5, randomDouble() - 0.5, 0);
}

Point3D Camera::defocusDiskSample() const
{
    Vector3D p = randomUnitDisk();
    return _center + (p.x() * _defocusHorizontalDisk) + (p.y() * _defocusVerticalDisk);
}

Color Camera::rayColor(const Ray& r, int depth, const PrimitiveList& world) const
{
    if (depth <= 0)
        return Color(0,0,0);

    HitRecord rec;

    if (!world.hit(r, Interval(0.001, infinity), rec))
            return _background;

    Ray scattered;
    Color attenuation;
    Color color_from_emission = rec.getPtr()->emitted(rec.getU(), rec.getV(), rec.getP());

    if (!rec.getPtr()->scatter(r, rec, attenuation, scattered))
        return color_from_emission;

    Color color_from_scatter = attenuation * rayColor(scattered, depth-1, world);

    return color_from_emission + color_from_scatter;
}
