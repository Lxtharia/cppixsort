#include "pixelsorter.h"
#include <iostream>
using namespace std;

void Pixelsorter::sort_pixels(int width, int height, vector<Pixel> data) {
	std::cout << "Sorting a image with dimenstions: [" << width << "x" << height << "]" << std::endl;
    for (int x = 0; x < width; x++) {
        vector<Pixel> span {}; 
        for (int y = 0; y < height; y++) {
            int index = y * width + x;
            span.push_back(data[index]);
        }
        std::cout << "Sorting span of length: "  << span.size() << std::endl;
        this->algo.sort_span(span);
    }
}

