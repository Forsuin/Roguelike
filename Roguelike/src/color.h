#pragma once

#include <cstdint>

namespace yarl {

	struct color_t {
		uint8_t r, g, b;

		color_t() = default;

		color_t(const int x) : r(x), g(x), b(x) {}

		color_t(const uint8_t x) : r(x), g(x), b(x) {}

		color_t(const int r, const int g, const int b) : r(r), g(g), b(b) {}

		color_t(const uint8_t r, const uint8_t g, const uint8_t b) : r(r), g(g), b(b) {}

		color_t operator+(const color_t& rhs) const {
			int red = r + rhs.r;
			int green = g + rhs.g;
			int blue = b + rhs.b;
			if (red > 255) red = 255;
			if (green > 255) green = 255;
			if (blue > 255) blue = 255;
			return { red, green, blue };
		}

		color_t operator+(const int rhs) const {
			int red = r + rhs;
			int green = r + rhs;
			int blue = r + rhs;
			if (red > 255) red = 255;
			if (green > 255) green = 255;
			if (blue > 255) blue = 255;
			return { red, green, blue };
		}

		color_t operator-(const color_t& rhs) const {
			int red = r - rhs.r;
			int green = g - rhs.g;
			int blue = b - rhs.b;
			if (red < 0) red = 0;
			if (green < 0) green = 0;
			if (blue < 0) blue = 0;
			return { red, green, blue };
		}

		color_t operator-(const int rhs) const {
			int red = r - rhs;
			int green = g - rhs;
			int blue = b - rhs;
			if (red < 0) red = 0;
			if (green < 0) green = 0;
			if (blue < 0) blue = 0;
			return { red, green, blue };
		}

		constexpr bool operator==(const color_t& rhs) const {
			return (r == rhs.r && g == rhs.g && b == rhs.b);
		}

		constexpr bool operator!=(const color_t& rhs) const {
			return !(*this == rhs);
		}
	};
}