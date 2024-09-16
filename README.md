# Raytracer Project Documentation

## Introduction
The Raytracer Project is a software for rendering images using the ray tracing technique.
It generates scene renderings featuring geometric shapes. A configuration file is used to easily modify the rendered scene.

## Installation and Configuration
To install and configure the Raytracer Project, follow these steps:

1. Clone the GitHub repository: `git clone https://github.com/EpitechPromo2027/B-OOP-400-STG-4-1-raytracer-cedric.martz.git`
2. Install libconfig packages depending on your packet manager.
For example :
`sudo apt install libconfig-dev`
if you use apt.
3. Go to the repo with `cd` and build the project by running `make`.
4. You can now use the raytracer as follows :
`./raytracer [config_file] > result.ppm`

## Project Architecture
The Raytracer Project is organized into several main components:

- `src/`: Contains the source code of the raytracer.
- `include` : Contains the headers for the source code.

## User Guide
To use the raytracer, follow these instructions:

1. Create a configuration for the raytracer or use a provided file.
2. Run the raytracer with the configuration file as an argument.
3. Wait until it's done, then look with a ppm picture viewer the result.

## Features
The Raytracer Project boasts the following features:

- **Geometric Primitives Rendering**: It supports rendering of some geometric primitives such as spheres and planes.
- **Material Handling**: The raytracer allows users to specify material properties for objects in the scene, including metal,
glass and mat color.
- **Special Effects**: The raytracer supports special effects such as lights, shadows, reflections, refractions, and depth of
field.

## Examples and Tutorials
To help users get started, the Raytracer Project provides a collection of examples and tutorials:

- **Pre-generated Render Scenes**: The `scenes/` directory contains previously generated scenes and their associated
configuration files.
- **Tutorial:** You can find a tutorial on how to create a configuration file in the `tutorial.md` file.
