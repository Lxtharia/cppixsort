#pragma once
#include <limits>
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
	T a = std::numeric_limits<T>::max();
	PIXEL_VALUE_TYPE value;

	Pixel(T& r, T& g, T& b, T& a, int value = 0)
		:r(r), g(g), b(b), a(a), value(value)
	{}

	bool operator==(Pixel& p) {
		return this->r == p.r
			&& this->g == p.g
			&& this->b == p.b
			&& this->a == p.a;
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
	T& a;
	// Value to store for comparison
	PIXEL_VALUE_TYPE value;
	PixelMut(T& r, T& g, T& b, T& a, int value = 0)
		:r(r), g(g), b(b), a(a), value(value)
	{}
	PixelMut& operator=(const Pixel& p) {
		this->r = p.r;
		this->g = p.g;
		this->b = p.b;
		this->a = p.a;
		this->value = p.value;
		return *this;
	}
	PixelMut& operator=(const PixelMut& p) {
		this->r = p.r;
		this->g = p.g;
		this->b = p.b;
		this->a = p.a;
		this->value = p.value;
		return *this;
	}
	Pixel to_owned() const {
		return Pixel(r,g,b,a,value);
	}

	bool operator==(const PixelMut& p) {
		return this->r == p.r
			&& this->g == p.g
			&& this->b == p.b
			&& this->a == p.a;
			;
	};
	void swap(PixelMut& pixel) {
		auto swap_ref = [](auto&a, auto&b){
			T temp = a;
			a = b;
			b = temp;
		};

		swap_ref(this->r, pixel.r);
		swap_ref(this->g, pixel.g);
		swap_ref(this->b, pixel.b);
		swap_ref(this->a, pixel.a);
		int temp = this->value;
		this->value = pixel.value;
		pixel.value = temp;
	}

};

inline std::ostream& operator<<(std::ostream& os, const PixelMut& px) {
	os << "Pixel[" << px.r << ", " << px.g << ", " << px.b << ", " << px.a <<", (" << px.value << ")]";
	return os;
}

using Span = std::vector<PixelMut>;

inline PixelMut Pixel::to_ref() {
		return PixelMut{r,g,b,a,value};
}
