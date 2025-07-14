#include "pixelsorter.h"
#include <iostream>


void Pixelsorter::sort_pixels(int w, int h, vector<Pixel> data) {
	std::cout << "Sorting a image with dimenstions: [" << w << "x" << h << "]" << std::endl;
    for (Pixel p : data) {
        auto temp = *p.r;
        *p.r = *p.g;
        *p.g = temp;
    }
}

vector<Pixel> img_to_pixels(PIXEL_VALUE_TYPE* data, int size, int depth, int spectrum) {
    vector<Pixel> vec {};
    if (data == nullptr) return vec;
    // Data is stored like this: R1R2R3R4...G1G2G3G4...B1B2B3B4...
    // Size is w*h*dep*spec
    int offset = size/(depth*spectrum);
    for (int i = 0; i < offset; i++) {
        vec.push_back(Pixel{
                &data[i],         //r
                &data[offset+i],  //g
                &data[2*offset+i] //b
            });
    }
    return vec;
}
