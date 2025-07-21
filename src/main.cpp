#include <iostream>
#include <vector>
#include "cmdline.h"
#include "lib/common.h"
#include "lib/path_creator.h"
#include "lib/pixelsorter.h"
#include "lib/sorting_algorithm.h"
#include <ImageMagick-7/Magick++.h>

using namespace std;
using namespace Magick;

vector<PixelMut> img_to_pixels(Pixels&);

int main (int argc, char *argv[]) {
	// Create sorter manually

	// Creating sorter with some defaults
	cmdline_args args {};

	args.pixelsorter = std::move( Pixelsorter { new LinePath(PathCreator::DOWN), new MapSort(), new Brightness, true});
	parse_arguments(argc, argv, args);


	cout << "Opening image..." << endl;
	// CImg<PIXEL_CHANNEL_TYPE> image(args.input_filename.c_str());
	Image image {};
	image.read(args.input_filename.c_str());
	int width = image.columns();
	int height = image.rows();

	// cout << "Magick uses Quantum Depth of:" << MAGICKCORE_QUANTUM_DEPTH << endl;

	cout << "Extracting pixels..." << endl;
	image.modifyImage();
	Pixels px_view(image);

	Quantum* quantums = px_view.get(0, 0, image.columns(), image.rows());
	vector<PixelMut> pixels {};
	for (int i = 0; i < width*height; i++) {
		PIXEL_CHANNEL_TYPE& r = *(PIXEL_CHANNEL_TYPE*)quantums++;
		PIXEL_CHANNEL_TYPE& g = *(PIXEL_CHANNEL_TYPE*)quantums++;
		PIXEL_CHANNEL_TYPE& b = *(PIXEL_CHANNEL_TYPE*)quantums++;
		pixels.push_back(PixelMut{ r,g,b });
		quantums++;
	}
	// debug
	// for (Pixel p : pixels) {
	//	   cout << "{ r: " << p.r << ", g: " << p.g << ", g: " << p.b << " }" << endl;
	// }

	cout << "Sorting image..." << endl;
	args.pixelsorter.sort_pixels(width, height, pixels);
	px_view.sync();

	cout << "Saving image..." << endl;

	// Save it to sorted.png
	image.write(args.output_filename.c_str());

	return 0;
}


/*! Return the Pixels of the image as a vector. Changing the pixel values will manipulate the image.
*/
vector<PixelMut> img_to_pixels(Pixels& image) {
}
