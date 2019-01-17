#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>
#include <string>

const int norm = 0;
const int red = 1;
const int green = 2;
const int yellow = 3;
const int blue = 4;
const int magenta = 5;
const int cyan = 6;

class Screen{

    private:

    std::vector<std::string> fcolors;
    std::vector<std::string> bcolors;
    
    public:

    Screen(){
        this->fcolors.push_back("\e[39m"); //Normal
        this->fcolors.push_back("\e[31m"); //Red
        this->fcolors.push_back("\e[32m"); //Green
        this->fcolors.push_back("\e[33m"); //Yellow
        this->fcolors.push_back("\e[34m"); //Blue
        this->fcolors.push_back("\e[35m"); //Magenta
        this->fcolors.push_back("\e[36m"); //Cyan
        
        this->bcolors.push_back("\e[49m"); //Normal
        this->bcolors.push_back("\e[41m"); //Red
        this->bcolors.push_back("\e[42m"); //Green
        this->bcolors.push_back("\e[43m"); //Yellow
        this->bcolors.push_back("\e[44m"); //Blue
        this->bcolors.push_back("\e[45m"); //Magenta
        this->bcolors.push_back("\e[46m"); //Cyan
    }

    void move(int x, int y){
        if(x < 0)
            std::cout << "\033[" << -x << "D";
        
        if(x > 0)
            std::cout << "\033[" << x << "C";

        if(y < 0)
            std::cout << "\033[" << -y << "B";
        
        if(y > 0)
            std::cout << "\033[" << y << "A";
    }

    void clear(){
        std::cout << "\033[2J"; //Clear and 0,0
    }

    void eraseLine(){
        std::cout << "\033[K";
    }

    void moveTo(int x, int y){
        std::cout << "\033[" << y << ";" << x << "H";
    }

    void save(){
        std::cout << "\033[s";
    }

    void restore(){
        std::cout << "\033[u";
    }

    void bcolor(int code){
        std::cout << bcolors[code];
    }
    
    void fcolor(int code){
        std::cout << fcolors[code];
    }

};

int main(){ 
    Screen s;
    s.clear();
    
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    //std::cout << w.ws_row << "    " << w.ws_col << std::endl;
     
    s.move(10, 5);
    s.bcolor(red); 
    std::cout << "     ";
    s.bcolor(norm);
    s.move(0, -5);
    s.move(-10, -5);
    
    //http://tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html
    //https://stackoverflow.com/questions/38770996/linux-moving-the-console-cursor-visual
    
    return 0;
}
