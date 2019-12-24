#pragma once

#include <chrono>
#include <thread>
#include <functional>

class UpdateLoop{
    private:
    int framerate;
    bool isStop;
    std::function<void()>& todo; // TODO: Better use templating

    void startLoop(){
        int desiredWait = 1000 / this->framerate;
        while(!isStop){
            auto start = std::chrono::steady_clock::now();
            todo();
            auto end = std::chrono::steady_clock::now();
            int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            int waiting = desiredWait - elapsed;
            if(waiting > 0){
                std::this_thread::sleep_for(std::chrono::milliseconds(waiting));
            }
        }
    }

    public:
    UpdateLoop(int framerate, std::function<void()>& fn) : todo(fn){
        this->framerate = framerate;
        this->isStop = false;
        this->startLoop();
    }

    void stop(){
        this->isStop = true;
    }
};
