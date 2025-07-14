#include <bits/std_thread.h>
#include <vector>
#include "common.h"
#include "sorting_algorithm.h"

class Pixelsorter {
private:
    bool inverse;
    SortingAlgorithm& algo;
public:
    Pixelsorter(SortingAlgorithm& algo, bool inverse = false)
        : inverse(inverse)
        , algo(algo)
    {}
    ~Pixelsorter() {}

    void sort_pixels(int w, int h, std::vector<Pixel>);
};

