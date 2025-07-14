#include "common.h"
#include "path_creator.h"


vector<vector<Pixel>> LinePath::create_spans(int width, int height, vector<Pixel>& pixels) const {
    vector<vector<Pixel>> spans {};

    // For every column, sort the row
    int primary = width;
    int secondary = height;
    bool reverse = false;
    bool index_in_order = true;
    if (this->direction == Direction::DOWN || this->direction == Direction::UP) {
        // For every row, sort the columns
        primary = height;
        secondary = width;
        index_in_order = false;
    } else {
        cout << "For every column, sort the row" << endl;
    }
    if (this->direction == Direction::DOWN || this->direction == Direction::LEFT) {
        reverse = !reverse;
    }

    for (int a = 0; a < secondary; a++) {
        vector<Pixel> span {};
        for (int b = reverse?(primary-1):0
            ;reverse?(b > 0):(b < primary)
            ;b += reverse?-1:1
        ) {
            int index = (index_in_order)
                ? a * width + b
                : b * width + a;
            span.push_back(pixels[index]);
            cout << index << " | ";
        }
        cout << endl;
        spans.push_back(span);
    }
    return spans;
}

