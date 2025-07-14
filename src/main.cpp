#include <iostream>
#include <vector>
#include "lib/pixelsorter.h"
#include <CImg.h>

using std::cout, std::endl;
using cimg_library::CImg;

int main (int argc, char *argv[]) {
	std::cout << "Hello World!" << std::endl;

    // Creating sorter
	Pixelsorter sorter{};

    cout << "Opening image..." << endl;
    CImg<PIXEL_VALUE_TYPE> image("res/pixeltest.png");

    cout << "Extracting pixels..." << endl;
    auto pixels = img_to_pixels(image.data(), image.size(), image.depth(), image.spectrum());

    cout << "Sorting image..." << endl;
	sorter.sort_pixels(10, 10, pixels);

    cout << "Saving image..." << endl;

	// Save it to sorted.png
    image.save_imagemagick_external("sorted.png");

	return 0;
}
