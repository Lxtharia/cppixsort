#include "common.h"
#include "path_creator.h"


vector<Span> LinePath::create_spans(int width, int height, Span& pixels) const {
	cout << "Creating spans: LINE(" << this->direction << ")" << endl;
	vector<Span> spans {};

	// Sort along width (row)
	int main_axis = width;
	int cross_axis = height;
	bool reverse = false;
	bool index_in_order = true;
	if (this->direction == Direction::DOWN || this->direction == Direction::UP) {
		// Sort along height (columns)
		main_axis = height;
		cross_axis = width;
		index_in_order = false;
	}
	if (this->direction == Direction::DOWN || this->direction == Direction::RIGHT) {
		reverse = !reverse;
	}

	for (int a = 0; a < cross_axis; a++) {
		Span span {};
		for (int b = reverse?(main_axis-1) : 0
		    ;        reverse?    (b >= 0) : (b < main_axis)
		    ;b +=    reverse?         -1 : 1
		) {
			int index = (index_in_order)
			            ? a * width + b
			            : b * width + a;
			span.push_back(pixels[index]);
			// cout << index << " | ";
		}
		spans.push_back(span);
	}
	return spans;
}

