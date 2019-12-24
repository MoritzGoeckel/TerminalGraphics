#include <iostream>
#include <sys/ioctl.h>
#include <string>
#include <stdlib.h>

#include <functional>

#include "Screen.cpp"
#include "UpdateLoop.cpp"

int main(){
    Screen s;
    s.clear();

    int i = 0;
    std::function<void()> fn = [&s, &i](){
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

    UpdateLoop l(30, fn);

    //http://tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html
    //https://stackoverflow.com/questions/38770996/linux-moving-the-console-cursor-visual

    return 0;
}
