#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "texture.h"
#include "stb_image.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	float vertices[] = {
		// positions          // colors           // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	yarl::Shader shader;
	shader.add("resources/shaders/shader.vs", yarl::ShaderType::VERTEX);
	shader.add("resources/shaders/shader.fs", yarl::ShaderType::FRAGMENT);
	

	unsigned int vertexBuffer, vertexArray, elementBuffer;

	glGenVertexArrays(1, &vertexArray);
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &elementBuffer);

	glBindVertexArray(vertexArray);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//texture attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);


	yarl::Texture texture1("resources/textures/container.jpg", yarl::TextureFormat::RGB);

	texture1.setTextureParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	texture1.setTextureParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
	texture1.setTextureParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	texture1.setTextureParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	yarl::Texture texture2("resources/textures/awesomeface.png", yarl::TextureFormat::RGBA);

	texture1.setTextureParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	texture1.setTextureParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
	texture1.setTextureParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	texture1.setTextureParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	shader.use();
	shader.setInt("texture1", 0);
	shader.setInt("texture2", 1);

	//render loop
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		texture1.setActive(yarl::TextureSlot::TEXTURE0);
		texture2.setActive(yarl::TextureSlot::TEXTURE1);

		shader.use();
		glBindVertexArray(vertexArray);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}

