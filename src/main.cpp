#include <iostream>
#include <vector>
#include "cmdline.h"
#include "lib/common.h"
#include "lib/path_creator.h"
#include "lib/pixelsorter.h"
#include "lib/sorting_algorithm.h"
#include <CImg.h>

using namespace std;
using cimg_library::CImg;

vector<PixelMut> img_to_pixels(CImg<PIXEL_CHANNEL_TYPE>& image);

int main (int argc, char *argv[]) {
	// Create sorter manually

	// Creating sorter with some defaults
	cmdline_args args {};
	args.pixelsorter = std::move( Pixelsorter { new LinePath(PathCreator::DOWN), new MapSort(), new Brightness, true});
	parse_arguments(argc, argv, args);


	cout << "Opening image..." << endl;
	CImg<PIXEL_CHANNEL_TYPE> image(args.input_filename.c_str());

	cout << "Extracting pixels..." << endl;
	auto pixels = img_to_pixels(image);
	// debug
	// for (Pixel p : pixels) {
	//	   cout << "{ r: " << p.r << ", g: " << p.g << ", g: " << p.b << " }" << endl;
	// }

	cout << "Sorting image..." << endl;
	args.pixelsorter.sort_pixels(image.width(), image.height(), pixels);

	cout << "Saving image..." << endl;

	// Save it to sorted.png
	image.save_imagemagick_external(args.output_filename.c_str());

	return 0;
}


/*! Return the Pixels of the image as a vector. Changing the pixel values will manipulate the image.
*/
vector<PixelMut> img_to_pixels(CImg<PIXEL_CHANNEL_TYPE>& image) {
	PIXEL_CHANNEL_TYPE* data = image.data();
	int size = image.size();
	int depth = image.depth();
	int spectrum = image.spectrum();

	vector<PixelMut> vec {};
	if (data == nullptr) return vec;
	// Data is stored like this: R1R2R3R4...G1G2G3G4...B1B2B3B4...
	// Size is w*h*dep*spec
	int offset = size/(depth*spectrum);
	for (int i = 0; i < offset; i++) {
		PIXEL_CHANNEL_TYPE& r = data[i];
		PIXEL_CHANNEL_TYPE& g = data[offset+i];
		PIXEL_CHANNEL_TYPE& b = data[2*offset+i];
		vec.push_back(PixelMut{ r,g,b });
	}
	return vec;
}
