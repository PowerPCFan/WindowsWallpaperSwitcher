#include "Wallpapers.h"

// Wallpapers Folder //
string wallpapersFolder = "https://charliesmacadventures.neocities.org/wallpapers";
// End Wallpapers Folder //

// Windows Wallpaper Folders //
string xpFolder = wallpapersFolder + "/WindowsXP";
string vistaFolder = wallpapersFolder + "/WindowsVista";
string sevenFolder = wallpapersFolder + "/Windows7";
string eightPointOneFolder = wallpapersFolder + "/Windows8-1";
string tenFolder = wallpapersFolder + "/Windows10";
string elevenFolder = wallpapersFolder + "/Windows11";
// End Windows Wallpaper Folders //

// macOS Wallpaper Folders //
string macOS_10_0_Folder = wallpapersFolder + "/MacOS10.0";
string macOS_10_1_Folder = wallpapersFolder + "/MacOS10.1";
string macOS_10_2_Folder = wallpapersFolder + "/MacOS10.2";
string macOS_10_3_Folder = wallpapersFolder + "/MacOS10.3";
string macOS_10_4_Folder = wallpapersFolder + "/MacOS10.4";
string macOS_10_5_Folder = wallpapersFolder + "/MacOS10.5";
string macOS_10_6_Folder = wallpapersFolder + "/MacOS10.6";
string macOS_10_7_Folder = wallpapersFolder + "/MacOS10.7";
string macOS_10_8_Folder = wallpapersFolder + "/MacOS10.8";
string macOS_10_9_Folder = wallpapersFolder + "/MacOS10.9";
string macOS_10_10_Folder = wallpapersFolder + "/MacOS10.10";
string macOS_10_11_Folder = wallpapersFolder + "/MacOS10.11";
string macOS_10_12_Folder = wallpapersFolder + "/MacOS10.12";
string macOS_10_13_Folder = wallpapersFolder + "/MacOS10.13";
string macOS_10_14_Folder = wallpapersFolder + "/MacOS10.14";
string macOS_10_15_Folder = wallpapersFolder + "/MacOS10.15";
string macOS_11_Folder = wallpapersFolder + "/MacOS11";
string macOS_12_Folder = wallpapersFolder + "/MacOS12";
string macOS_13_Folder = wallpapersFolder + "/MacOS13";
string macOS_14_Folder = wallpapersFolder + "/MacOS14";
string macOS_15_Folder = wallpapersFolder + "/MacOS15";
// End macOS Wallpaper Folders //

// Windows Wallpapers Stores //
WallpaperStore xp = {
    { "Ascent", xpFolder + "/Ascent.jpg" },
    { "Bliss", xpFolder + "/Bliss.jpg" },
    { "Red Moon Desert", xpFolder + "/Red-moon-desert.jpg" },
    { "Autumn", xpFolder + "/Autumn.jpg" },
    { "Follow", xpFolder + "/Follow.jpg" },
    { "Friend", xpFolder + "/Friend.jpg" },
    { "Tulips", xpFolder + "/Tulips.jpg" },
    { "Vortec Space", xpFolder + "/Vortec-space.jpg" },
    { "House", xpFolder + "/House.jpg" }
};

WallpaperStore vista = {
    { "Autumn Leaves", vistaFolder + "/Autumn-Leaves.jpg" },
    { "Desert Landscape", vistaFolder + "/Desert-Landscape.jpg" },
    { "Dock", vistaFolder + "/Dock.jpg" },
    { "Forest Flowers", vistaFolder + "/Forest-Flowers.jpg" },
    { "Forest", vistaFolder + "/Forest.jpg" },
    { "Frangipani Flowers", vistaFolder + "/Frangipani-Flowers.jpg" },
    { "Garden", vistaFolder + "/Garden.jpg" },
    { "Green Sea Turtle", vistaFolder + "/Green-Sea-Turtle.jpg" },
    { "Humpback Whale", vistaFolder + "/Humpback-Whale.jpg" },
    { "img3", vistaFolder + "/img3.jpg" },
    { "img4", vistaFolder + "/img4.jpg" },
    { "img7", vistaFolder + "/img7.jpg" },
    { "img8", vistaFolder + "/img8.jpg" },
    { "img9", vistaFolder + "/img9.jpg" },
    { "img10", vistaFolder + "/img10.jpg" },
    { "img11", vistaFolder + "/img11.jpg" },
    { "img16", vistaFolder + "/img16.jpg" },
    { "img17", vistaFolder + "/img17.jpg" },
    { "img18", vistaFolder + "/img18.jpg" },
    { "img21", vistaFolder + "/img21.jpg" },
    { "img23", vistaFolder + "/img23.jpg" },
    { "Oryx Antelope", vistaFolder + "/Oryx-Antelope.jpg" },
    { "Toco Toucan", vistaFolder + "/Toco-Toucan.jpg" },
    { "Tree", vistaFolder + "/Tree.jpg" },
    { "Waterfall", vistaFolder + "/Waterfall.jpg" },
    { "Winter Leaves", vistaFolder + "/Winter-Leaves.jpg" }
};

WallpaperStore seven = {
    { "Canyon", sevenFolder + "/Canyon.jpg" },
    { "Chrysanthemum", sevenFolder + "/Chrysanthemum.jpg" },
    { "Default", sevenFolder + "/Default.jpg" },
    { "Desert", sevenFolder + "/Desert.jpg" },
    { "Flower", sevenFolder + "/Flower.jpg" },
    { "Ice", sevenFolder + "/Ice.jpg" },
    { "img17", sevenFolder + "/img17.jpg" },
    { "img18", sevenFolder + "/img18.jpg" },
    { "Koala", sevenFolder + "/Koala.jpg" },
    { "Penguins", sevenFolder + "/Penguins.jpg" },
    { "Purple Field", sevenFolder + "/Purple-Field.jpg" },
    { "Waterfall", sevenFolder + "/Waterfall.jpg" }
};

WallpaperStore eightPointOne = {
    { "Rainbow Stripes", eightPointOneFolder + "/RainbowStripes.jpg" },
    { "Windows 8 Default", eightPointOneFolder + "/Windows8Default.jpg" }
};

WallpaperStore ten = {
    { "Arch", tenFolder + "/Arch.jpg" },
    { "Archway Islands", tenFolder + "/Archway-Islands.jpg" },
    { "Camping", tenFolder + "/Camping.jpg" },
    { "Camping (Ultrawide Version)", tenFolder + "/Camping-Ultrawide.jpg" },
    { "Windows 10 Default", tenFolder + "/Windows10Default.jpg" }
};

WallpaperStore eleven = {
    { "Blue Flow", elevenFolder + "/BlueFlow.jpg" },
    { "Green Flow", elevenFolder + "/GreenFlow.jpg" },
    { "Pink Flow", elevenFolder + "/PinkFlow.jpg" },
    { "Blue Glow", elevenFolder + "/BlueGlow.jpg" },
    { "Green Glow", elevenFolder + "/GreenGlow.jpg" },
    { "Pink Glow", elevenFolder + "/PinkGlow.jpg" },
    { "Red Glow", elevenFolder + "/RedGlow.jpg" },
    { "Windows 11 Default (Light)", elevenFolder + "/Windows11DefaultLight.jpg" },
    { "Windows 11 Default (Dark)", elevenFolder + "/Windows11DefaultDark.jpg" }
};
// End Windows Wallpapers Stores //

// macOS Wallpaper Stores //
WallpaperStore macOS_10_0 = {
    { "macOS 10.0", macOS_10_0_Folder + "/MacOS10.0.jpg" }
};

WallpaperStore macOS_10_1 = {
    { "macOS 10.1", macOS_10_1_Folder + "/MacOS10.1.jpg" }
};

WallpaperStore macOS_10_2 = {
    { "macOS 10.2", macOS_10_2_Folder + "/MacOS10.2.jpg" }
};

WallpaperStore macOS_10_3 = {
    { "macOS 10.3", macOS_10_3_Folder + "/MacOS10.3.jpg" }
};

WallpaperStore macOS_10_4 = {
    { "macOS 10.4", macOS_10_4_Folder + "/MacOS10.4.jpg" }
};

WallpaperStore macOS_10_5 = {
    { "macOS 10.5", macOS_10_5_Folder + "/MacOS10.5.jpg" }
};

WallpaperStore macOS_10_6 = {
    { "macOS 10.6", macOS_10_6_Folder + "/MacOS10.6.jpg" }
};

WallpaperStore macOS_10_7 = {
    { "macOS 10.7", macOS_10_7_Folder + "/MacOS10.7.jpg" }
};

WallpaperStore macOS_10_8 = {
    { "macOS 10.8", macOS_10_8_Folder + "/MacOS10.8.jpg" }
};

WallpaperStore macOS_10_9 = {
    { "macOS 10.9", macOS_10_9_Folder + "/MacOS10.9.jpg" }
};

WallpaperStore macOS_10_10 = {
    { "macOS 10.10", macOS_10_10_Folder + "/MacOS10.10.jpg" }
};

WallpaperStore macOS_10_11 = {
    { "macOS 10.11", macOS_10_11_Folder + "/MacOS10.11.jpg" }
};

WallpaperStore macOS_10_12 = {
    { "macOS 10.12", macOS_10_12_Folder + "/MacOS10.12.jpg" }
};

WallpaperStore macOS_10_13 = {
    { "macOS 10.13", macOS_10_13_Folder + "/MacOS10.13.jpg" }
};

WallpaperStore macOS_10_14 = {
    { "Day", macOS_10_14_Folder + "/Day.jpg" },
    { "Night", macOS_10_14_Folder + "/Night.jpg" }
};

WallpaperStore macOS_10_15 = {
    { "Day", macOS_10_15_Folder + "/Day.jpg" },
    { "Night", macOS_10_15_Folder + "/Night.jpg" }
};

WallpaperStore macOS_11 = {
    { "Color Day", macOS_11_Folder + "/ColorDay.jpg" },
    { "Color Night", macOS_11_Folder + "/ColorNight.jpg" },
    { "Day", macOS_11_Folder + "/Day.jpg" },
    { "Night", macOS_11_Folder + "/Night.jpg" }
};

WallpaperStore macOS_12 = {
    { "Dark", macOS_12_Folder + "/Dark.jpg" },
    { "Light", macOS_12_Folder + "/Light.jpg" }
};

WallpaperStore macOS_13 = {
    { "Dark", macOS_13_Folder + "/Dark.jpg" },
    { "Light", macOS_13_Folder + "/Light.jpg" }
};

WallpaperStore macOS_14 = {
    { "Dark", macOS_14_Folder + "/Dark.jpg" },
    { "Horizon", macOS_14_Folder + "/Horizon.png" },
    { "Light", macOS_14_Folder + "/Light.jpg" }
};

WallpaperStore macOS_15 = {
    { "Dark", macOS_15_Folder + "/Dark.jpg" },
    { "Light", macOS_15_Folder + "/Light.jpg" },
    { "Sunrise", macOS_15_Folder + "/Sunrise.png" }
};
// End macOS Wallpaper Stores //
