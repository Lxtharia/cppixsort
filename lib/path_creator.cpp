#include "common.h"
#include "path_creator.h"


vector<Span> LinePath::create_spans(int width, int height, Span& pixels) const {
	cout << "Creating spans: LINE(" << this->direction << ")" << endl;
	vector<Span> spans {};

	// For every column, sort the row
	int primary = width;
	int secondary = height;
	bool reverse = false;
	bool index_in_order = true;
	if (this->direction == Direction::DOWN || this->direction == Direction::UP) {
		// For every row, sort the columns
		primary = height;
		secondary = width;
		index_in_order = false;
	} else {
		// DEBUG
		// cout << "For every column, sort the row" << endl;
	}
	if (this->direction == Direction::DOWN || this->direction == Direction::RIGHT) {
		reverse = !reverse;
	}

	for (int a = 0; a < secondary; a++) {
		Span span {};
		for (int b = reverse?(primary-1):0
		    ;reverse?(b > 0):(b < primary)
		    ;b += reverse?-1:1
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

