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
	unique_ptr<SortingAlgorithm> algo;
	unique_ptr<PathCreator> pathing;

	Pixelsorter()
		:inverse(false)
		,algo(make_unique<BubbleSort>(SortingAlgorithm::Criteria::BRIGHTNESS))
		,pathing(make_unique<LinePath>(LinePath::Direction::DOWN))
	{ }
	Pixelsorter(PathCreator& pathing, SortingAlgorithm& algo, bool inverse = false)
		:inverse(inverse)
		,pathing(make_unique<PathCreator>(pathing))
		,algo(make_unique<SortingAlgorithm>(algo))
	{}
	~Pixelsorter() {}
	Pixelsorter(Pixelsorter& sorter)
		:inverse(sorter.inverse)
	{
		// Make deep copy
		this->pathing = make_unique<PathCreator>(*sorter.pathing);
		this->algo = make_unique<SortingAlgorithm>(*sorter.algo);
	};

	void sort_pixels(int w, int h, Span);
};

