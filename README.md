# FMQChallenge

This project was done as part of a test proposed by [Fabamaq](https://www.fabamaq.com/) for their game development recruitment process. The project was written in C++ and uses the [SFML](https://www.sfml-dev.org/) library for rendering 2D graphics. 

# Getting started

If you simply want to try out the game, there are Windows and Linux releases available. 

## Building from source

If you want to build the project yourself, first you must obtain it, as well as the required git submodules.

```bash
git clone git@github.com:fcfalmeida/FMQChallenge.git
cd FMQChallenge/
git submodule update --init --recursive
```

Then build it using cmake.

```bash
mkdir build/
cd build/
cmake --build .
```
