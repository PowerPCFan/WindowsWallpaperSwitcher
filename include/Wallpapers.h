#pragma once

#include <string>
#include <vector>

typedef std::string string;

struct Wallpaper {
    string name;
    string url;
};

typedef std::vector<Wallpaper> WallpaperStore;

extern string wallpapersFolder;
extern string xpFolder;
extern string vistaFolder;
extern string sevenFolder;
extern string eightPointOneFolder;
extern string tenFolder;
extern string elevenFolder;

extern WallpaperStore xp;
extern WallpaperStore vista;
extern WallpaperStore seven;
extern WallpaperStore eightPointOne;
extern WallpaperStore ten;
extern WallpaperStore eleven;
