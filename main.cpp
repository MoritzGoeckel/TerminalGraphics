#include <stdlib.h>
#include <sys/ioctl.h>
#include <iostream>
#include <string>

#include "Matrix.h"
#include "Point.h"
#include "Screen.h"
#include "UpdateLoop.h"

void drawMatrix(Screen& screen, Matrix<int>& matrix, Point& p) {
    // Calculate diff from new matrix to old matrix
    // Generate the screen commands
}

int main() {
    Screen s;
    s.clear();

    Matrix<int> sp(10, 5, 0);
    sp.set(4, 2, 1);
    sp.set(5, 2, 1);
    sp.set(5, 3, 1);

    int i = 0;
    auto fn = [&s, &i]() {
        int x = ((rand() % s.width()) / 2) * 2;
        int y = rand() % s.height();

        s.moveTo(x, y);
        s.bcolor((rand() % 4) + 1);
        std::cout << " ";
        if (x < s.width() - 1) {
            std::cout << " ";
        }
        s.bcolor(COLOR::NORMAL);

        s.moveTo(0, 0);
        std::cout << i++;

        s.flush();
    };

    UpdateLoop<typeof(fn)> l(1000, fn);

    return 0;
}
