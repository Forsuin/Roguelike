#pragma once
#include <string>


namespace yarl {

	enum class ShaderType {
		VERTEX,
		FRAGMENT,
		GEOMETRY
	};

	class Shader {
	public:
		//shader program ID
		unsigned int ID;

		Shader();
		void add(const std::string& path, ShaderType type);
		void use();
		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;
	};
}

