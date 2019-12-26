#include <iostream>
#include <sys/ioctl.h>
#include <string>
#include <stdlib.h>

#include "Screen.cpp"
#include "UpdateLoop.cpp"
#include "Matrix.cpp"
#include "Point.cpp"

void drawMatrix(Screen& screen,
                Matrix<int>& matrix,
                Point& p){
    // Calculate diff from new matrix to old matrix
    // Generate the screen commands
}

int main(){
    Screen s;
    s.clear();

    Matrix<int> sp(10, 5, 0);
    sp.set(4, 2, 1);
    sp.set(5, 2, 1);
    sp.set(5, 3, 1);

    int i = 0;
    auto fn = [&s, &i](){
        int x = rand() % s.getWidth();
        int y = rand() % s.getHight();

        s.moveTo(x, y);
        s.bcolor(rand() % 5);
        std::cout << " ";
        s.bcolor(norm);

        s.moveTo(0, 0);
        std::cout << i++;

        s.flush();
    };

    UpdateLoop<typeof(fn)> l(30, fn);

    //http://tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html
    //https://stackoverflow.com/questions/38770996/linux-moving-the-console-cursor-visual

    return 0;
}
