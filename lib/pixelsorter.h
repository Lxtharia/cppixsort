#pragma once
#include <bits/std_thread.h>
#include <vector>
#include "common.h"
#include "path_creator.h"
#include "sorting_algorithm.h"


class Pixelsorter {
private:
public:
	bool inverse;
	unique_ptr<PathCreator> pathing;
	unique_ptr<SortingAlgorithm> algo;
	unique_ptr<Criteria> sorting_criteria;

	Pixelsorter()
		:inverse(false)
		,algo(make_unique<BubbleSort>())
		,pathing(make_unique<LinePath>(LinePath::Direction::DOWN))
		,sorting_criteria(make_unique<Brightness>())
	{ }
	Pixelsorter(PathCreator& pathing, SortingAlgorithm& algo, Criteria sorting_criteria, bool inverse = false)
		:inverse(inverse)
		,pathing(make_unique<PathCreator>(pathing))
		,algo(make_unique<SortingAlgorithm>(algo))
		,sorting_criteria(make_unique<Criteria>(sorting_criteria))
	{}
	~Pixelsorter() {}
	Pixelsorter(Pixelsorter& sorter)
		:inverse(sorter.inverse)
	{
		// Make deep copy
		this->pathing = make_unique<PathCreator>(*sorter.pathing);
		this->algo = make_unique<SortingAlgorithm>(*sorter.algo);
		this->sorting_criteria = make_unique<Criteria>(*sorter.sorting_criteria);
	};

	void sort_pixels(int w, int h, Span);
};

