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
	SortingAlgorithm algo;
	PathCreator pathing;

	Pixelsorter()
		:inverse(false)
		,algo(SortingAlgorithm(SortingAlgorithm::Criteria::BRIGHTNESS))
		,pathing(PathCreator())
	{
	}
	Pixelsorter(PathCreator& pathing, SortingAlgorithm& algo, bool inverse = false)
		:inverse(inverse)
		,pathing(pathing)
		,algo(algo)
	{}
	~Pixelsorter() {}
	Pixelsorter(Pixelsorter& sorter)
		:inverse(sorter.inverse)
		,algo(sorter.algo)
		,pathing(sorter.pathing)
	{};

	void sort_pixels(int w, int h, Span);
};

