#pragma once
#include <vector>
#include <iostream>

using PIXEL_CHANNEL_TYPE = unsigned int;
using PIXEL_VALUE_TYPE = int;

struct PixelMut;

struct Pixel {
	using T = PIXEL_CHANNEL_TYPE;
	T r;
	T g;
	T b;
	int value = 0;

	Pixel(T& r, T& g, T& b, int value = 0)
		:r(r), g(g), b(b), value(value)
	{}

	bool operator==(Pixel& p) {
		return this->r == p.r
			&& this->g == p.g
			&& this->b == p.b
			;
	};
	PixelMut to_ref();
};

/* Class that holds mutable references to pixeldata.
*/
struct PixelMut {
	using T = PIXEL_CHANNEL_TYPE;
	T& r;
	T& g;
	T& b;
	// Value to store for comparison
	int value;
	PixelMut(T& r, T& g, T& b, int value = 0)
		:r(r), g(g), b(b), value(value)
	{}
	PixelMut& operator=(Pixel& p) {
		this->r = p.r;
		this->g = p.g;
		this->b = p.b;
		this->value = p.value;
		return *this;
	}
	PixelMut& operator=(PixelMut& p) {
		this->r = p.r;
		this->g = p.g;
		this->b = p.b;
		this->value = p.value;
		return *this;
	}
	Pixel to_owned() {
		return Pixel(r,g,b,value);
	}

	bool operator==(PixelMut& p) {
		return this->r == p.r
			&& this->g == p.g
			&& this->b == p.b
			;
	};
	void swap(PixelMut& pixel) {
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

inline std::ostream& operator<<(std::ostream& os, const PixelMut& px) {
	os << "Pixel[" << px.r << ", " << px.g << ", " << px.b << ", (" << px.value << ")]";
	return os;
}

using Span = std::vector<PixelMut>;

inline PixelMut Pixel::to_ref() {
		return PixelMut{r,g,b,value};
}
