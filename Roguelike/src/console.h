#pragma once
#include <vector>

#include "tile.h"

namespace yarl {

	class console
	{
	public:

		console(const yarl::tile_t& tile = yarl::defaultTile, const int width = 80, const int height = 24) : tiles(std::vector<yarl::tile_t>(width * height, tile)), width(width), height(height) {}

		yarl::tile_t& at(int x, int y);
		void set(int x, int y, const tile_t& to);
		void clear(const tile_t& to = defaultTile);
		int size();
	public:
		uint16_t width;
		uint16_t height;


	private:
		std::vector<yarl::tile_t> tiles;

		int getIndex(int x, int y);
	};
}

