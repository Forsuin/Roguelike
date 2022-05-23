#include "console.h"

yarl::tile_t& yarl::console::at(int x, int y)
{
	return tiles[getIndex(x, y)];
}

void yarl::console::set(int x, int y, const tile_t& to)
{
	tiles[getIndex(x, y)] = to;
}

void yarl::console::clear(const tile_t& to = defaultTile)
{
	for (auto t : tiles) {
		t = to;
	}
}

int yarl::console::size()
{
	return width * height;
}

int yarl::console::getIndex(int x, int y)
{
	return (width * y + x);
}
