#pragma once
#include "common.h"
#include <vector>
using namespace std;

/*! Base class for creating paths.

   The default implementation will return all the pixels as one span, starting at the top left.
*/
class PathCreator {
    public:
        enum Direction {
            RIGHT, DOWN, LEFT, UP,
        };
        virtual vector<Span> create_spans(int width, int height, Span& pixels) const {
            return { pixels };
        };
};

class LinePath : public PathCreator {
public:
    Direction direction;
    LinePath(Direction dir): PathCreator() {
        this->direction = dir;
    }
    virtual vector<Span>  create_spans(int width, int height, Span& pixels) const override;
};
