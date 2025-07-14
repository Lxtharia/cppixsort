#pragma once
#include <iostream>

using PIXEL_VALUE_TYPE = unsigned int;

class Pixel {
    using T = PIXEL_VALUE_TYPE;
public:
    T& r;
    T& g;
    T& b;
    // Value to store for comparison
    int value;
    Pixel(T& r, T& g, T& b, int value = 0)
        :r(r), g(g), b(b), value(value)
    {}
    bool operator==(Pixel& p) {
        return this->r == p.r
            && this->g == p.g
            && this->b == p.b
            ;
    };
    void swap(Pixel& pixel) {
        auto swap_ref = [](T&a, T&b){
            T temp = a;
            a = b;
            b = temp;
        };

        swap_ref(this->r, pixel.r);
        swap_ref(this->g, pixel.g);
        swap_ref(this->b, pixel.b);
        int temp = this->value;
        this->value = pixel.value;
        pixel.value = temp;
    }

};
