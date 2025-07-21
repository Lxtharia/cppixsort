#pragma once
#include "common.h"
#include <cmath>


struct Criteria {
	virtual PIXEL_VALUE_TYPE calculate_value(Pixel&) = 0;
	virtual PIXEL_VALUE_TYPE calculate_value(PixelMut& pm) {
		Pixel p = pm.to_owned(); return calculate_value(p);
	};
	PIXEL_VALUE_TYPE operator()(Pixel& p) { return this->calculate_value(p); }
};

struct Brightness : public Criteria {
	PIXEL_VALUE_TYPE calculate_value(Pixel& p) override {
		Pixel p_scaled = p.scale(8);
		return p_scaled.r + p_scaled.g + p_scaled.b;
	};
};

/*! Base class for the algorithm that is used to sort a span.

   The default implementation will leave the spans unaltered.
*/
class SortingAlgorithm {
public:
	// Default implementation does nothing
	virtual void sort_span(Span&) const {};
};

// BubbleSort inherits Algorithm
// Make inheritence public so we can upcast to SortingAlgorithm
class BubbleSort : public SortingAlgorithm {
public:
	// We explicitly override sort_span.
	// Override makes the compiler warn us if we accidentally overload a function with the same name
	virtual void sort_span(Span&) const override;
};

class MapSort : public SortingAlgorithm {
public:
	virtual void sort_span(Span&) const override;
};
