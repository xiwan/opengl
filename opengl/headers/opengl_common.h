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

#include "./headers/camera.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void maxVertexCheck();
int loadTexture(const char* vertexPath);
GLFWwindow* prepareWindow(const char* windowTitle);

class GlobalConfig
{
public:

	Camera gCamera;

	float lastX;
	float lastY;
	float deltaTime;	// Time between current frame and last frame
	float lastFrame; // Time of last frame

	bool firstMouse;

	GlobalConfig(glm::vec3 cameraPos)
	{
		gCamera = Camera(cameraPos);

		lastX = (float)SCR_WIDTH / 2;
		lastY = (float)SCR_HEIGHT / 2;
		deltaTime = 0.0f;
		lastFrame = 0.0f; 	
		firstMouse = true;
		
	}

	float get_currentFrame() 
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		return currentFrame;
	};

	glm::mat4 get_view()
	{
		return gCamera.GetViewMatrix();
	}

	glm::mat4 get_perspective()
	{
		return glm::perspective(glm::radians(gCamera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	}

	void mouse_callback_simple(GLFWwindow *window, double xpos, double ypos)
	{
		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		float xoffset = xpos - lastX;
		float yoffset = lastY - ypos;
		lastX = xpos;
		lastY = ypos;

		gCamera.ProcessMouseMovement(xoffset, yoffset);
	};

	void scroll_callback_simple(GLFWwindow* window, double xoffset, double yoffset)
	{
		gCamera.ProcessMouseScroll(yoffset);
	}

	void process_keyboard_simple(GLFWwindow *window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			gCamera.ProcessKeyboard(FORWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			gCamera.ProcessKeyboard(BACKWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			gCamera.ProcessKeyboard(LEFT, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			gCamera.ProcessKeyboard(RIGHT, deltaTime);
	};

private:


};


#endif




