# spotify-qt-quick
This repo contains the Qt Quick user interface for [spotify-qt](https://github.com/kraxarn/spotify-qt). 
It's mostly intended for use with mobile devices, but can be used with desktop devices as well.

**NOTE:** This application is currently being re-written from the ground up, so a lot of features 
will be missing or not working. If you need something now, use the latest "stable" version, or
use [spotify-qt](https://github.com/kraxarn/spotify-qt) instead.

## Building yourself

Make sure you have Qt (5.9+/6.0+) with SVG support, CMake (3.5+) and various build tools like
`make`, `g++` and `git`.

```
git clone --branch v3.4 --recursive https://github.com/kraxarn/spotify-qt.git spotify-qt-quick
cd spotify-qt-quick
mkdir build
cd build
cmake -DUSE_QT_QUICK=1 ..
cmake --build .
./spotify-qt-quick
```