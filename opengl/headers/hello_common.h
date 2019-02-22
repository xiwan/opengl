#pragma once
#ifndef HELLO_COMMON
#define HELLO_COMMON

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void processInput(GLFWwindow *window);
	void maxVertexCheck();
	int loadTexture(const char* vertexPath, GLint internalformat, GLenum format);
	GLFWwindow* prepareWindow(const char* windowTitle);

	// settings
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;


#endif




