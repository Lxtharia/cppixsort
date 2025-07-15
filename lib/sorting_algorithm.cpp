#include <iostream>
#include "sorting_algorithm.h"
using namespace std;

void BubbleSort::sort_span(Span& pixels) const {
    // If we don't implement a sort_span, we get a "undefined reference to 'vtable for BubbleSort'" error
    if (pixels.size() <= 1) return;

    if (this->criteria == this->BRIGHTNESS) {
        int t = pixels.size();
        for (int i = 0; i < pixels.size(); i ++) { // Swoops this many times
            for (int j = 1; j < t; j ++) { // One swoop, where the biggest number gets swooped to the end
                if (pixels[j-1].value > pixels[j].value) 
                    pixels[j-1].swap(pixels[j]);
            }
            t--;
        }


    } else {
        throw "Invalid Criteria";
    }
}
