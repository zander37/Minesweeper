# Minesweeper

A simple **Minesweeper** clone written in C++ using **[SFML](https://www.sfml-dev.org/)**. This project demonstrates how to create a graphical user interface with interactive buttons, windows, and more.

## Table of Contents
- [Features](#features)
- [Requirements](#requirements)
- [Building and Running](#building-and-running)
- [Usage](#usage)

---

## Features
- **Graphical Interface**: Uses SFML for drawing windows, buttons, and text.
- **Customizable**: You can adjust the window size and number of mines in the source code.
- **Cross-Platform**: CMake + SFML allows the game to be built on Windows, macOS, and Linux.

---

## Requirements
1. A **C++11** (or higher) compatible compiler (e.g., gcc, clang, MSVC).
2. **CMake** 3.2 or higher.
3. **SFML** 2.5.1 (or newer).

   - You can install SFML from:
     - [SFML official website](https://www.sfml-dev.org/download.php)
     - A package manager (e.g., vcpkg, Conan, homebrew, apt, etc.)
     - Or build SFML from source.

---

## Building and Running

1. **Clone this repository**:

   ```bash
   git clone https://github.com/<YOUR_USERNAME>/Minesweeper.git
   cd Minesweeper

2. **Install SFML**
   If you haven’t already. Make sure SFML is accessible to CMake (for example, via ```SFML_DIR``` or a standard system path).

3. **Generate build files with CMake:**

   ```bash
   cmake -B build -S .

4. **Build the project:**

   ```bash
   cmake --build build

5. **Run the game:**

   - On macOS/Linux:
      ```bash
      ./build/untitled

   - On Windows
     ```bash
     .\build\Debug\untitled.exe

## Usage

- **Left-click** on a tile to reveal it.
- **Right-click** to place/remove flags.
- The goal is to reveal all non-mine tiles without triggering a mine.
   



