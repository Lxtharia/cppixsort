#pragma once
#include "common.h"
#include <vector>
using namespace std;

class PathCreator {
    public:
        enum Direction {
            LEFT, UP, RIGHT, DOWN
        };
        virtual vector<vector<Pixel>> create_spans(int width, int height, vector<Pixel>& pixels) const = 0;
};

class LinePath : public PathCreator {
public:
    Direction direction;
    LinePath(Direction dir): PathCreator() {
        this->direction = dir;
    }
    virtual vector<vector<Pixel>>  create_spans(int width, int height, vector<Pixel>& pixels) const override;
};
