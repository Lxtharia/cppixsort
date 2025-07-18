#pragma once
#include "common.h"
#include <vector>

/*! Base class for the algorithm that is used to sort a span.

   The default implementation will leave the spans unaltered.
*/
class SortingAlgorithm {
public:
	enum Criteria {
		BRIGHTNESS,
	};
protected:
	Criteria criteria;
public:
	SortingAlgorithm(Criteria criteria)
		: criteria(criteria) {}
	// Default implementation does nothing
	virtual void sort_span(Span&) const {};
};

#define SUPER(classname) classname(Criteria criteria) : SortingAlgorithm(criteria) {}

// BubbleSort inherits Algorithm
// Make inheritence public so we can upcast to SortingAlgorithm
class BubbleSort : public SortingAlgorithm {
public:
	SUPER(BubbleSort)
	// We explicitly override sort_span.
	// Override makes the compiler warn us if we accidentally overload a function with the same name
	virtual void sort_span(Span&) const override;
};

class MapSort : public SortingAlgorithm {
public:
	SUPER(MapSort)
	virtual void sort_span(Span&) const override;
};
