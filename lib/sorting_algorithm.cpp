#include <climits>
#include <map>
#include <stack>
#include "sorting_algorithm.h"
using namespace std;

void BubbleSort::sort_span(Span& pixels) const {
	// If we don't implement a sort_span, we get a "undefined reference to 'vtable for BubbleSort'" error

	int t = pixels.size();
	for (int i = 0; i < pixels.size(); i ++) { // Swoops this many times
		for (int j = 1; j < t; j ++) { // One swoop, where the biggest number gets swooped to the end
			if (pixels[j-1].value > pixels[j].value) 
				pixels[j-1].swap(pixels[j]);
		}
		t--;
	}
}

void MapSort::sort_span(Span& pixels) const {
	PIXEL_VALUE_TYPE max_val = INT_MIN;
	PIXEL_VALUE_TYPE min_val = INT_MAX;
	for (auto& p: pixels) {
		if (p.value > max_val)
			max_val = p.value;
		if (p.value < min_val)
			min_val = p.value;
	}
	PIXEL_VALUE_TYPE offset = -min_val;
	map<PIXEL_VALUE_TYPE, stack<Pixel>> boxes = {};
	// Create an empty stack for each value in the vector

	for (const auto& p: pixels) {
		int i = p.value;
		boxes[i+offset].push(p.to_owned());
	}

	int i = 0;
	for (auto& [val, st]: boxes) {
		while (!st.empty()) {
			pixels[i++] = st.top();
			st.pop();
		}
	}

}
