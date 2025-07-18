#pragma once
#include <vector>
#include <iostream>

using PIXEL_CHANNEL_TYPE = unsigned int;
using PIXEL_VALUE_TYPE = int;

class Pixel {
	using T = PIXEL_CHANNEL_TYPE;
public:
	T& r;
	T& g;
	T& b;
	// Value to store for comparison
	int value;
	Pixel(T& r, T& g, T& b, int value = 0)
		:r(r), g(g), b(b), value(value)
	{}
	Pixel& operator=(Pixel& p) {
		this->r = p.r;
		this->g = p.g;
		this->b = p.b;
		this->value = p.value;

		return *this;
	}

	bool operator==(Pixel& p) {
		return this->r == p.r
			&& this->g == p.g
			&& this->b == p.b
			;
	};
	void swap(Pixel& pixel) {
		auto swap_ref = [](T&a, T&b){
			T temp = a;
			a = b;
			b = temp;
		};

		swap_ref(this->r, pixel.r);
		swap_ref(this->g, pixel.g);
		swap_ref(this->b, pixel.b);
		int temp = this->value;
		this->value = pixel.value;
		pixel.value = temp;
	}

};

using Span = std::vector<Pixel>;

