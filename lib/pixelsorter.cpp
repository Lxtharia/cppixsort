#include "pixelsorter.h"
#include <iostream>
using std::cout, std::endl;

void SortingAlgorithm::sort_span(vector<Pixel> data) {
    for (Pixel p : data) {
        cout << "{ r: " << p.r << ", g: " << p.g << ", g: " << p.b << " }" << endl;
        if (p.r) p.r /= 2;
        if (p.g) p.g /= 2;
        if (p.b) p.b /= 2;
    }
};

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

