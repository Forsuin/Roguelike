#pragma once
#include <string>


namespace yarl {

	enum class Axis {
		S,
		T,
		BOTH
	};

	enum class WrapMode {
		REPEAT,
		MIRRORED_REPEAT,
		CLAMP_TO_EDGE,
		CLAMP_TO_BORDER
	};

	enum class FilteringMode {
		NEAREST,
		LINEAR,
		NEAREST_MIPMAP_NEAREST,
		LINEAR_MIPMAP_NEAREST,
		NEAREST_MIPMAP_LINEAR,
		LINEAR_MIPMAP_LINEAR
	};

	enum class Filter {
		MIN,
		MAG
	};

	//can be casted straight to a GLint
	enum class TextureFormat {
		RGB = 0x1907,
		RGBA = 0x1908
	};

	enum class TextureSlot {
		TEXTURE0  = 0x84C0,
		TEXTURE1  = 0x84C1,
		TEXTURE2  = 0x84C2,
		TEXTURE3  = 0x84C3,
		TEXTURE4  = 0x84C4,
		TEXTURE5  = 0x84C5,
		TEXTURE6  = 0x84C6,
		TEXTURE7  = 0x84C7,
		TEXTURE8  = 0x84C8,
		TEXTURE9  = 0x84C9,
		TEXTURE10 = 0x84CA,
		TEXTURE11 = 0x84CB,
		TEXTURE12 = 0x84CC,
		TEXTURE13 = 0x84CD,
		TEXTURE14 = 0x84CE,
		TEXTURE15 = 0x84CF,
		TEXTURE16 = 0x84D0,
		TEXTURE17 = 0x84D1,
		TEXTURE18 = 0x84D2,
		TEXTURE19 = 0x84D3,
		TEXTURE20 = 0x84D4,
		TEXTURE21 = 0x84D5,
		TEXTURE22 = 0x84D6,
		TEXTURE23 = 0x84D7,
		TEXTURE24 = 0x84D8,
		TEXTURE25 = 0x84D9,
		TEXTURE26 = 0x84DA,
		TEXTURE27 = 0x84DB,
		TEXTURE28 = 0x84DC,
		TEXTURE29 = 0x84DD,
		TEXTURE30 = 0x84DE,
		TEXTURE31 = 0x84DF
	};

	//2D texture
	class Texture
	{
	public:
		unsigned int ID;

		Texture(const std::string& path, TextureFormat format);

		//Binds texture to specified texture slot
		void setActive(TextureSlot slot);

		void setTextureParameter(GLenum name, GLint parameter);
	};
}

