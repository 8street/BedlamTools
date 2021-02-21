# BedlamTools

Utility for the Bedlam 1996 game. Allows to view all images from the game files. Also allows to listen all sound files.

[![Lines of Code](https://tokei.rs/b1/github/8street/BedlamTools?category=code)](https://github.com/XAMPPRocky/tokei)

![](https://raw.githubusercontent.com/8street/BedlamTools/master/misc/bedlamtools.png)

# Project State

* Image: drawing all images from binary BIN files
* Sound: playing all RAW, MRW sound files
* MIDI: not playing MRS files (planning)

# Contributing

Contributors, welcome. Create a fork, then create a branch. Modify the source code. Finally, create a pull request to merge with my main branch.

# Compiling

1. Install QT 5.12.10 with MSVC 2017 64(32)-bit components
2. Open Visual Studio 2019, install "QT VS Tools" extension
3. Open QT VS Tools options and set installed QT path 

For more information how to integrate QT with the Visual Studio, see QT documentation.

4. Open msvc/BedlamTools.sln project in Visual Studio 2019
5. Compile x64 platform.

# How to use

1. Compile or [download from releases](https://github.com/8street/BedlamTools/releases)
2. Run

To see images:

3. Open any Bedlam .bin file. If you need, open Bedlam .pal palette file
4. See image.

To listen sound:

3. Open any Bedlam directory with RAW, RMW files
4. Click play to listen sound
