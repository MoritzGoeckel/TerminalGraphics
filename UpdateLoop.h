#pragma once

#include <chrono>
#include <thread>
#include <functional>

template<typename Fn>
class UpdateLoop{
    private:
    int framerate;
    bool isStop;
    Fn task;

    void startLoop(){
        int desiredWait = 1000 / this->framerate;
        while(!isStop){
            auto start = std::chrono::steady_clock::now();
            task();
            auto end = std::chrono::steady_clock::now();
            int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            int waiting = desiredWait - elapsed;
            if(waiting > 0){
                std::this_thread::sleep_for(std::chrono::milliseconds(waiting));
            }
        }
    }

    public:
    UpdateLoop(int framerate, Fn& task) : task(task){
        this->framerate = framerate;
        this->isStop = false;
        this->startLoop();
    }

    void stop(){
        this->isStop = true;
    }
};
