#pragma once
#include "common.h"
#include <vector>

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
    // No default implementation for sort_span. This makes the class abstract
    virtual void sort_span(std::vector<Pixel>) const = 0;
};

// BubbleSort inherits Algorithm
// Make inheritence public so we can upcast to SortingAlgorithm
class BubbleSort : public SortingAlgorithm {
public:
    BubbleSort(SortingAlgorithm::Criteria criteria)
        : SortingAlgorithm(criteria) {}  // probably equivalent to calling super() in java
    // We explicitly override sort_span.
    // Override makes the compiler warn us if we accidentally overload a function with the same name
    virtual void sort_span(std::vector<Pixel>) const override;
};
