#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>

namespace COLOR {

const int NORMAL = 0;
const int RED = 1;
const int GREEN = 2;
const int YELLOW = 3;
const int BLUE = 4;
const int MAGENTA = 5;
const int CYAN = 6;

}  // namespace COLOR

class Screen {
   private:
    std::vector<std::string> fcolors;
    std::vector<std::string> bcolors;
    int h;
    int w;

   public:
    Screen() {
        struct winsize wi;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &wi);
        h = wi.ws_row;
        w = wi.ws_col;

        // Foreground
        this->fcolors.push_back("\e[39m");  // Normal
        this->fcolors.push_back("\e[31m");  // Red
        this->fcolors.push_back("\e[32m");  // Green
        this->fcolors.push_back("\e[33m");  // Yellow
        this->fcolors.push_back("\e[34m");  // Blue
        this->fcolors.push_back("\e[35m");  // Magenta
        this->fcolors.push_back("\e[36m");  // Cyan

        // Background
        this->bcolors.push_back("\e[49m");  // Normal
        this->bcolors.push_back("\e[41m");  // Red
        this->bcolors.push_back("\e[42m");  // Green
        this->bcolors.push_back("\e[43m");  // Yellow
        this->bcolors.push_back("\e[44m");  // Blue
        this->bcolors.push_back("\e[45m");  // Magenta
        this->bcolors.push_back("\e[46m");  // Cyan
    }

    // Get terminal width and height
    int height() { return h; }
    int width() { return w; }

    // Move cursor relative
    void move(int x, int y) {
        if (x < 0) std::cout << "\033[" << -x << "D";
        if (x > 0) std::cout << "\033[" << x << "C";
        if (y < 0) std::cout << "\033[" << -y << "B";
        if (y > 0) std::cout << "\033[" << y << "A";
    }

    // Clear screen and move to 0,0
    void clear() { std::cout << "\033[2J"; }

    void eraseLine() { std::cout << "\033[K"; }

    // Move cursor absolute
    void moveTo(int x, int y) { std::cout << "\033[" << y << ";" << x << "H"; }

    void save() { std::cout << "\033[s"; }
    void restore() { std::cout << "\033[u"; }

    // Set colors for printing
    void bcolor(int code) { std::cout << bcolors[code]; }
    void fcolor(int code) { std::cout << fcolors[code]; }

    // Set normal colors
    void normal() {
        bcolor(COLOR::NORMAL);
        fcolor(COLOR::NORMAL);
    }

    void flush() { std::cout.flush(); }
};
