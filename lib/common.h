#pragma once

using PIXEL_VALUE_TYPE = unsigned int;

struct Pixel {
    PIXEL_VALUE_TYPE& r;
    PIXEL_VALUE_TYPE& g;
    PIXEL_VALUE_TYPE& b;
};
