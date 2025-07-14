#include "pixelsorter.h"
#include <iostream>
using namespace std;

void Pixelsorter::sort_pixels(int width, int height, vector<Pixel> data) {
    std::cout << "Sorting image with dimenstions: [" << width << "x" << height << "]" << std::endl;

	std::cout << "Creating spans along a path" << std::endl;
    auto spans = this->pathing.create_spans(width, height, data);

    for (vector<Pixel> span : spans) {
        std::cout << "Calculating pixel values for quicker comparison" << std::endl;
        for (Pixel& p : span) {
            p.value = p.r + p.g + p.b;
        }
        std::cout << "Sorting span of length: "  << span.size() << std::endl;
        this->algo.sort_span(span);
    }

}

