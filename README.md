# Meerkat Engine
Just a hobby game engine (WIP)

## About
A game engine project with ecs at it's core (found in `/Core`).

## Dependencies

### All platforms
* `premake5` - Used to generate makefiles

### Desktop
* `cc` - Any C compiler supported by premake (`#pragma once` support also required)
* `sdl2` - Used in the graphics api

### Web
* `emsdk` - Provides web support
* `make` - Prefered build system for web

## Building
Ensure `premake5` is installed along with the development tools for your specific platform.

### Desktop
Refer to the `premake5` [manual](https://premake.github.io/docs/Using-Premake).

### Web
```sh
premake5 gmake
emmake make -C build config=web
```
