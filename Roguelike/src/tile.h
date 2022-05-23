#pragma once

#include "colors.h"

namespace yarl {
	struct tile_t {

		uint32_t character = ' ';
		color_t foreground = yarl::colors::WHITE;
		color_t background = yarl::colors::BLACK;


		tile_t() = default;

		tile_t(const uint32_t character, const color_t& foreground, const color_t& background) : character(character), foreground(foreground), background(background) {}

		constexpr bool operator==(const tile_t& rhs) const {
			return (character == rhs.character && foreground == rhs.foreground && background == rhs.background);
		}
		constexpr bool operator!=(const tile_t& rhs) const {
			return !(*this == rhs);
		}

	};

	const tile_t defaultTile = { ' ', yarl::colors::WHITE, yarl::colors::BLACK };
}