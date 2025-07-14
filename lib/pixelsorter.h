#include <bits/std_thread.h>
#include <vector>
using std::vector;

using PIXEL_VALUE_TYPE = unsigned int;

struct Pixel {
    PIXEL_VALUE_TYPE r;
    PIXEL_VALUE_TYPE g;
    PIXEL_VALUE_TYPE b;
};

class Pixelsorter {
private:
    bool m_inverse;
public:
    Pixelsorter(bool inverse = false)
        : m_inverse(inverse)
    {}
    ~Pixelsorter() {}

    void sort_pixels(int w, int h, vector<Pixel>);
};

vector<Pixel> img_to_pixels(PIXEL_VALUE_TYPE* data, int size, int depth, int dimensions);
