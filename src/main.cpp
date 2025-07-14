#include <iostream>
#include <vector>
#include "lib/pixelsorter.h"
#include <CImg.h>

using std::cout, std::endl;
using cimg_library::CImg;

vector<Pixel> img_to_pixels(CImg<PIXEL_VALUE_TYPE>& image);

int main (int argc, char *argv[]) {
	std::cout << "Hello World!" << std::endl;

    // Creating sorter
	Pixelsorter sorter{
        SortingAlgorithm{}
    };

    cout << "Opening image..." << endl;
    CImg<PIXEL_VALUE_TYPE> image("res/pixeltest.png");

    cout << "Extracting pixels..." << endl;
    auto pixels = img_to_pixels(image);
    // debug
    // for (Pixel p : pixels) {
    //     cout << "{ r: " << p.r << ", g: " << p.g << ", g: " << p.b << " }" << endl;
    // }

    cout << "Sorting image..." << endl;
	sorter.sort_pixels(image.width(), image.height(), pixels);

    cout << "Saving image..." << endl;

	// Save it to sorted.png
    image.save_imagemagick_external("sorted.png");

	return 0;
}


/*! Return the Pixels of the image as mutable vector
*/
vector<Pixel> img_to_pixels(CImg<PIXEL_VALUE_TYPE>& image) {
    PIXEL_VALUE_TYPE* data = image.data();
    int size = image.size();
    int depth = image.depth();
    int spectrum = image.spectrum();

    vector<Pixel> vec {};
    if (data == nullptr) return vec;
    // Data is stored like this: R1R2R3R4...G1G2G3G4...B1B2B3B4...
    // Size is w*h*dep*spec
    int offset = size/(depth*spectrum);
    for (int i = 0; i < offset; i++) {
        PIXEL_VALUE_TYPE& r = data[i];
        PIXEL_VALUE_TYPE& g = data[offset+i];
        PIXEL_VALUE_TYPE& b = data[2*offset+i];
        vec.push_back(Pixel{
                r,g,b
            });
    }
    return vec;
}
