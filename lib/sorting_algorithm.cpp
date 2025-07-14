#include <iostream>
#include <utility>
#include "sorting_algorithm.h"
using namespace std;

// Why is this possible? :sob:
void SortingAlgorithm::sort_span(vector<Pixel> data) const {
    for (Pixel p : data) {
        cout << "{ r: " << p.r << ", g: " << p.g << ", g: " << p.b << " }" << endl;
        if (p.r) p.r /= 2;
        if (p.g) p.g /= 2;
        if (p.b) p.b /= 2;
    }
};

void swap_pixels(Pixel a, Pixel b) {
}

// If we don't implement a sort_span, we get a "undefined reference to 'vtable for BubbleSort'" error
void BubbleSort::sort_span(std::vector<Pixel>) const {
    if (this->criteria == this->BRIGHTNESS) {

    } else {
        throw "Invalid Criteria";
    }
}
