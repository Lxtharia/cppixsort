#include <climits>
#include <stack>
#include "sorting_algorithm.h"
using namespace std;

void BubbleSort::sort_span(Span& pixels) const {
	// If we don't implement a sort_span, we get a "undefined reference to 'vtable for BubbleSort'" error
	if (pixels.size() <= 1) return;

	if (this->criteria == this->BRIGHTNESS) {
		int t = pixels.size();
		for (int i = 0; i < pixels.size(); i ++) { // Swoops this many times
			for (int j = 1; j < t; j ++) { // One swoop, where the biggest number gets swooped to the end
				if (pixels[j-1].value > pixels[j].value) 
					pixels[j-1].swap(pixels[j]);
			}
			t--;
		}


	} else {
		throw "Invalid Criteria";
	}
}

void MapSort::sort_span(Span& pixels) const {
	int max_val = INT_MIN;
	int min_val = INT_MAX;
	for (auto& p: pixels) {
		if (p.value > max_val)
			max_val = p.value;
		if (p.value < min_val)
			min_val = p.value;
	}
	int offset = -min_val;
	vector<stack<Pixel>> boxes {};
	// Create vectors for each value
	for (int i = 0; i <= max_val+offset; i++) {
		boxes.push_back({});
	}

	for (auto& p: pixels) {
		int i = p.value;
		boxes.at(i+offset).push(p);
	}

	int i = 0;
	for (auto& box: boxes) {
		while (!box.empty()) {
			pixels[i++] = box.top();
			box.pop();
		}
	}

}
