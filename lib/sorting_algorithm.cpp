#include <climits>
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
	int offset = -min_val;
	vector<stack<Pixel>> boxes {};
	// Create an empty stack for each value in the vector
	cout << "MaxV: " << max_val << " " << offset << endl;
	boxes.assign(max_val+offset+1, stack<Pixel>{});

	for (auto& p: pixels) {
		int i = p.value;
		boxes.at(i+offset).push(p.to_owned());
	}

	int i = 0;
	for (auto& st: boxes) {
		while (!st.empty()) {
			// cout << "From " << pixels[i] << " to " << st.top().to_ref() << endl;
			pixels[i++] = st.top();
			st.pop();
		}
	}

}
