#pragma once

#include <iostream>

class Point {
   private:
    using T = int;
    T x;
    T y;

   public:
    Point(T x, T y) : x(x), y(y) {}
    T getX() { return x; }
    T getY() { return y; }
    void print() {
        std::cout << "(" << std::to_string(x) << " " << std::to_string(y)
                  << ")";
    }
};
