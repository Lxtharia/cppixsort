#pragma once
#include "common.h"
#include <vector>
using namespace std;

class PathCreator {
    public:
        enum Direction {
            LEFT, UP, RIGHT, DOWN
        };
        virtual vector<Span> create_spans(int width, int height, Span& pixels) const = 0;
};

class LinePath : public PathCreator {
public:
    Direction direction;
    LinePath(Direction dir): PathCreator() {
        this->direction = dir;
    }
    virtual vector<Span>  create_spans(int width, int height, Span& pixels) const override;
};
