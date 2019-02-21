#include "./headers/Shader.h"
#include "./headers/hello_common.h"
#include "./headers/camera.h"


void processInputMoveFps(GLFWwindow *window);
void mouse_callback_fps(GLFWwindow* window, double xpos, double ypos);
void scroll_callback_fps(GLFWwindow* window, double xoffset, double yoffset);
glm::mat4 calculate_lookAt_matrix(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp);

//camera system
const glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
const glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
const glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

Camera fpsCamera(cameraPos);
float lastXpos = SCR_WIDTH / 2.0f;
float lastYpos = SCR_HEIGHT / 2.0f;
bool firstMouseEnter = true;

float deltaTime_fps = 0.0f;	// Time between current frame and last frame
float lastFrame_fps = 0.0f; // Time of last frame

int hello_camera_fps()
{
	GLFWwindow* window = prepareWindow("hello_camera_fps");
	if (!window) {
		return -1;
	}
	glfwSetCursorPosCallback(window, mouse_callback_fps);
	glfwSetScrollCallback(window, scroll_callback_fps);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	Shader textureShader("./shaders/3d.shader.vs", "./shaders/3d.shader.fs");

	glm::vec3 cubePositions[] = {
	  glm::vec3(0.0f,  0.0f,  0.0f),
	  glm::vec3(2.0f,  5.0f, -15.0f),
	  glm::vec3(-1.5f, -2.2f, -2.5f),
	  glm::vec3(-3.8f, -2.0f, -12.3f),
	  glm::vec3(2.4f, -0.4f, -3.5f),
	  glm::vec3(-1.7f,  3.0f, -7.5f),
	  glm::vec3(1.3f, -2.0f, -2.5f),
	  glm::vec3(1.5f,  2.0f, -2.5f),
	  glm::vec3(1.5f,  0.2f, -1.5f),
	  glm::vec3(-1.3f,  1.0f, -1.5f)
	};
	// Vertex input
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);

	unsigned int texture1, texture2;
	texture1 = loadTexture("./pics/container.jpg", GL_RGB, GL_RGB);
	texture2 = loadTexture("./pics/awesomeface.png", GL_RGBA, GL_RGBA);

	textureShader.use();
	textureShader.setInt("texture1", 0);
	textureShader.setInt("texture2", 1);

	glEnable(GL_DEPTH_TEST);

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime_fps = currentFrame - lastFrame_fps;
		lastFrame_fps = currentFrame;

		processInputMoveFps(window);

		// render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// bind textures on corresponding texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);

		textureShader.use();
		glBindVertexArray(VAO);

		glm::mat4 view = fpsCamera.GetViewMatrix();
		//glm::mat4 view = calculate_lookAt_matrix(cameraPos, cameraPos + cameraFront, cameraUp);
		glm::mat4 projection = glm::perspective(glm::radians(fpsCamera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

		textureShader.setMatrix4("view", glm::value_ptr(view));
		textureShader.setMatrix4("projection", glm::value_ptr(projection));

		for (unsigned int i = 0; i < 10; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 1.0f, 1.0f));

			textureShader.setMatrix4("model", glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, sizeof(cubeVertices));
		}

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
};

void processInputMoveFps(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		fpsCamera.ProcessKeyboard(FORWARD, deltaTime_fps);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		fpsCamera.ProcessKeyboard(BACKWARD, deltaTime_fps);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		fpsCamera.ProcessKeyboard(LEFT, deltaTime_fps);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		fpsCamera.ProcessKeyboard(RIGHT, deltaTime_fps);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback_fps(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouseEnter)
	{
		lastXpos = xpos;
		lastYpos = ypos;
		firstMouseEnter = false;
	}

	float xoffset = xpos - lastXpos;
	float yoffset = lastYpos - ypos; // reversed since y-coordinates go from bottom to top

	lastXpos = xpos;
	lastYpos = ypos;

	fpsCamera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback_fps(GLFWwindow* window, double xoffset, double yoffset)
{
	fpsCamera.ProcessMouseScroll(yoffset);
}


// Custom implementation of the LookAt function
glm::mat4 calculate_lookAt_matrix(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp)
{
	// 1. Position = known
	// 2. Calculate cameraDirection
	glm::vec3 zaxis = glm::normalize(position - target);
	// 3. Get positive right axis vector
	glm::vec3 xaxis = glm::normalize(glm::cross(glm::normalize(worldUp), zaxis));
	// 4. Calculate camera up vector
	glm::vec3 yaxis = glm::cross(zaxis, xaxis);

	// Create translation and rotation matrix
	// In glm we access elements as mat[col][row] due to column-major layout
	glm::mat4 translation; // Identity matrix by default
	translation[3][0] = -position.x; // Third column, first row
	translation[3][1] = -position.y;
	translation[3][2] = -position.z;
	glm::mat4 rotation;
	rotation[0][0] = xaxis.x; // First column, first row
	rotation[1][0] = xaxis.y;
	rotation[2][0] = xaxis.z;
	rotation[0][1] = yaxis.x; // First column, second row
	rotation[1][1] = yaxis.y;
	rotation[2][1] = yaxis.z;
	rotation[0][2] = zaxis.x; // First column, third row
	rotation[1][2] = zaxis.y;
	rotation[2][2] = zaxis.z;

	// Return lookAt matrix as combination of translation and rotation matrix
	return rotation * translation; // Remember to read from right to left (first translation then rotation)
}