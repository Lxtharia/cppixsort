#include <iostream>
#include <vector>
#include "lib/pixelsorter.h"

using std::cout, std::endl;

int main (int argc, char *argv[]) {
	std::cout << "Hello World!" << std::endl;
	// Include test.png

	// Sort it
	// TODO
	Pixelsorter sorter{};

	std::vector<int> pixels = { 1,2,3,4 };
	sorter.sort(10, 10, pixels);
	Pixel p = {255, 120, 100};
	cout << "{ r: " << p.r << ", g: " << p.g << ", g: " << p.b << " }" << endl;

	// Save it to sorted-test.png

	return 0;
}
