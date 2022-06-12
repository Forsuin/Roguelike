#include <glad/glad.h>
#include <iostream>

#include "texture.h"
#include "stb_image.h"

//this may be a terrible fucking idea, but hey, it's not like this is going to be used by anyone else
yarl::Texture::Texture(const std::string& path, TextureFormat format)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	stbi_set_flip_vertically_on_load(true);

	int width, height, numChannels;
	
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &numChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, (GLint)format, width, height, 0, (GLenum)format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);
}

void yarl::Texture::setActive(TextureSlot slot)
{
	glActiveTexture((GLenum)slot);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void yarl::Texture::setTextureParameter(GLenum name, GLint parameter)
{
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexParameteri(GL_TEXTURE_2D, name, parameter);
}

