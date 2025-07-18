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
		,pathing(make_unique<LinePath>(LinePath::Direction::DOWN))
		,algo(make_unique<BubbleSort>())
		,sorting_criteria(make_unique<Brightness>())
	{ }
	Pixelsorter(PathCreator* pathing, SortingAlgorithm* algo, Criteria* sorting_criteria, bool inverse = false)
		:inverse(inverse)
		,pathing(unique_ptr<PathCreator>(pathing))
		,algo(unique_ptr<SortingAlgorithm>(algo))
		,sorting_criteria(unique_ptr<Criteria>(sorting_criteria))
	{}

	void sort_pixels(int w, int h, Span);
};

