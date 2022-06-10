#include <glad/glad.h>
#include <fstream>
#include <iostream>

#include "shader.h"

yarl::Shader::Shader()
{
	ID = glCreateProgram();
}

void yarl::Shader::add(const std::string& path, ShaderType type)
{
	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cout << "Could not open file at: " << path << std::endl;
	}

	std::string source((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

	const char* shaderCode = source.c_str();

	unsigned int shader;
	int success;
	char infoLog[512];

	switch (type)
	{
	case yarl::ShaderType::VERTEX:
		shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(shader, 1, &shaderCode, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR: Vertex Shader compilation failed\n" << infoLog << std::endl;
		}
		break;
	case yarl::ShaderType::FRAGMENT:
		shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(shader, 1, &shaderCode, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR: Fragment Shader compilation failed\n" << infoLog << std::endl;
		}
		break;
	case yarl::ShaderType::GEOMETRY:
		shader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(shader, 1, &shaderCode, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "ERROR: Geometry Shader compilation failed\n" << infoLog << std::endl;
		}
		break;
	default:
		std::cout << "Invalid ShaderType, skipping linking phase\n" << std::endl;
		return;
		
	}

	glAttachShader(ID, shader);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR: Shader Program linking failed\n" << infoLog << std::endl;
	}

	glDeleteShader(shader);
}

void yarl::Shader::use()
{
	glUseProgram(ID);
}

void yarl::Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void yarl::Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void yarl::Shader::setFloat(const std::string& name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
