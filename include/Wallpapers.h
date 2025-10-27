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

extern string macOS_10_0_Folder;
extern string macOS_10_1_Folder;
extern string macOS_10_2_Folder;
extern string macOS_10_3_Folder;
extern string macOS_10_4_Folder;
extern string macOS_10_5_Folder;
extern string macOS_10_6_Folder;
extern string macOS_10_7_Folder;
extern string macOS_10_8_Folder;
extern string macOS_10_9_Folder;
extern string macOS_10_10_Folder;
extern string macOS_10_11_Folder;
extern string macOS_10_12_Folder;
extern string macOS_10_13_Folder;
extern string macOS_10_14_Folder;
extern string macOS_10_15_Folder;
extern string macOS_11_Folder;
extern string macOS_12_Folder;
extern string macOS_13_Folder;
extern string macOS_14_Folder;
extern string macOS_15_Folder;

extern WallpaperStore xp;
extern WallpaperStore vista;
extern WallpaperStore seven;
extern WallpaperStore eightPointOne;
extern WallpaperStore ten;
extern WallpaperStore eleven;

extern WallpaperStore macOS_10_0;
extern WallpaperStore macOS_10_1;
extern WallpaperStore macOS_10_2;
extern WallpaperStore macOS_10_3;
extern WallpaperStore macOS_10_4;
extern WallpaperStore macOS_10_5;
extern WallpaperStore macOS_10_6;
extern WallpaperStore macOS_10_7;
extern WallpaperStore macOS_10_8;
extern WallpaperStore macOS_10_9;
extern WallpaperStore macOS_10_10;
extern WallpaperStore macOS_10_11;
extern WallpaperStore macOS_10_12;
extern WallpaperStore macOS_10_13;
extern WallpaperStore macOS_10_14;
extern WallpaperStore macOS_10_15;
extern WallpaperStore macOS_11;
extern WallpaperStore macOS_12;
extern WallpaperStore macOS_13;
extern WallpaperStore macOS_14;
extern WallpaperStore macOS_15;

