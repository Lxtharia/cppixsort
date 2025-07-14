#include "pixelsorter.h"
#include <iostream>


void Pixelsorter::sort_pixels(int w, int h, vector<Pixel> data) {
	std::cout << "Sorting a image with dimenstions: [" << w << "x" << h << "]" << std::endl;
    for (Pixel p : data) {
        auto temp = p.r;
        p.r = p.g;
        p.g = temp;
    }
}

vector<Pixel> img_to_pixels(PIXEL_VALUE_TYPE* data, int size, int depth, int spectrum) {
    vector<Pixel> vec {};
    if (data == nullptr) return vec;
    // Size is w*h*dep*spec
    int offset = size/(depth*spectrum);
    for (int i = 0; i < offset; i++) {
        PIXEL_VALUE_TYPE r = data[i];
        PIXEL_VALUE_TYPE g = data[i];
        PIXEL_VALUE_TYPE b = data[i];
        vec.push_back(Pixel{r, g, b});
        // printf("Pixel{ %d, %d, %d }\n", r, g, b);
    }
    return vec;
}
