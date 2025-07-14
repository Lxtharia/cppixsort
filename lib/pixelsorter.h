#include <bits/std_thread.h>
#include <vector>
using std::vector;

using PIXEL_VALUE_TYPE = unsigned int;

struct Pixel {
    PIXEL_VALUE_TYPE& r;
    PIXEL_VALUE_TYPE& g;
    PIXEL_VALUE_TYPE& b;
};

class SortingAlgorithm {
    private:
    public:
        void sort_span(vector<Pixel>);
};

class Pixelsorter {
private:
    bool inverse;
    SortingAlgorithm algo;
public:
    Pixelsorter(SortingAlgorithm algo, bool inverse = false)
        : inverse(inverse)
        , algo(algo)
    {}
    ~Pixelsorter() {}

    void sort_pixels(int w, int h, vector<Pixel>);
    friend void SortingAlgorithm::sort_span(vector<Pixel>);
};

