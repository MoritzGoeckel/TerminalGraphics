#pragma once

#include <iostream>
#include <vector>

#include "Point.cpp"

template<typename T>
class Matrix{
    private:
        std::vector<std::vector<T>> rows;

    public:
        Matrix(size_t w, size_t h, T def) : rows(){
            for(size_t i = 0; i < h; ++i){
                std::vector<T> row;
                for(size_t j = 0; j < w; ++j)
                    row.push_back(def);
                rows.push_back(row);
            }
        }

        void set(Point p, T value){
            set(p.getX(), p.getY(), value);
        }

        void set(size_t x, size_t y, T value){
            rows[y][x] = value;
        }

        void print(){
            for(auto r : rows){
                for(auto c : r){
                    std::cout << c << " ";
                }
                std::cout << std::endl;
            }
        }

        T get(size_t x, size_t y){
            return rows[y][x];
        }
};
