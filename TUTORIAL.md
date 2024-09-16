## Create a configuration file

To properly create a configuration file for the raytracer, you can follow these steps:

1. **Read `README.md`**: Before create something new, make sure to understand the `README.md` file. It contains informations about the raytracer usage.

2. **Create a New File**: Start by creating a new text file using a text editor of your choice.

3. **Define Camera Settings**: Begin by adding the camera settings in the file. These settings set the position, orientation, field of view, sampling rate, and depth of the camera. Here's an example of how to define camera settings:

```
# Configuration of the camera
camera :
{
    resolution = { width = 200; };
    from = { x = 13.0; y = 2.0; z = 3.0; };
    at = { x = 0.0; y = 0.0; z = 0.0; }
    rotation = { x = 0; y = 0; z = 0; };
    fieldOfView = 20.0;
    sPerPixel = 500;
    depth = 50;
    vup = { x = 0.0; y = 1.0; z =  0.0; }
    focusAngle = 0.6;
    focusDistance = 10.0;
};
```

4. **Define Primitives in the Scene:** Next, define the primitives (spheres or planes) in the configuration file.
Each primitive should include its position, size, color, and material.
The avalaibles materials are `flat, glass and metal`.
For example, you can have something like that:

```
# Primitives in the scene
primitives :
{
    # List of spheres
    spheres = (
        { x = 0.0; y = -1000.0; z = 0.0; r = 1000.0; color = { r = 0.5; g = 0.5; b = 0.5; }; material = "flat"; },
        { x = 0.0; y = 1.0; z = 0.0; r = 1.0; color = { r = 1.5; g = 0.0; b = 0.0; }; material = "glass"; },
        { x = -4.0; y = 1.0; z = 0.0; r = 1.0; color = { r = 0.4; g = 0.2; b = 0.1; }; material = "flat";},
        { x = 6.0; y = 1.0; z = 0.0; r = 0.2; color = { r = 0.1; g = 0.1; b = 0.1; }; material = "flat";},
        { x = 4.0; y = 1.0; z = 0.0; r = 1.0; color = { r = 0.7; g = 0.6; b = 0.5; }; material = "metal"; }
    );

    # List of planes
  planes = (
    { axis = "Z"; position = -20.0; color = { r = 64.0; g = 64.0; b = 255.0; }; }
    );
};
```

As you can see, you need to separate the lists of differents primitives.
