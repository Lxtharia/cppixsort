#pragma once
#include "common.h"
#include <vector>

struct Criteria {
	virtual PIXEL_CHANNEL_TYPE calculate_value(Pixel&) = 0;
	PIXEL_CHANNEL_TYPE operator()(Pixel& p) { return this->calculate_value(p); }
};
struct Brightness : public Criteria {
	PIXEL_CHANNEL_TYPE calculate_value(Pixel& p) {
		return p.r + p.g + p.b;
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
