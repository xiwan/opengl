#include "./headers/Shader.h"
#include "./headers/hello_common.h"
#include "./headers/camera.h"

void processInputMoveColor(GLFWwindow *window);
void mouse_callback_color(GLFWwindow* window, double xpos, double ypos);
void scroll_callback_color(GLFWwindow* window, double xoffset, double yoffset);

//camera system
const glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 5.0f);
const glm::vec3 cameraFront = glm::vec3(1.2f, 1.0f, -3.0f);
const glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

// lighting
const glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

Camera colorCamera(cameraPos);
float lastX_color = SCR_WIDTH / 2.0f;
float lastY_color = SCR_HEIGHT / 2.0f;
bool firstMouseColor = true;

float deltaTime_color = 0.0f;	// Time between current frame and last frame
float lastFrame_color = 0.0f; // Time of last frame

int lighting_color()
{
	GLFWwindow* window = prepareWindow("hello_camera_fps");
	if (!window) {
		return -1;
	}

	glfwSetCursorPosCallback(window, mouse_callback_color);
	glfwSetScrollCallback(window, scroll_callback_color);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	Shader cubeShader("./shaders/light_cube.shader.vs", "./shaders/light_cube.shader.fs");
	Shader sourceShader("./shaders/light_cube.shader.vs", "./shaders/light_source.shader.fs");

	const float cubeVertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	// first, configure the cube's VAO (and VBO)
	unsigned int cubeVAO;
	glGenVertexArrays(1, &cubeVAO);
	glBindVertexArray(cubeVAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
	// set the vertex attributes 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(2);

	// second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
	unsigned int lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	// we only need to bind to the VBO, the container's VBO's data already contains the correct data.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// set the vertex attributes (only position data for our lamp)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime_color = currentFrame - lastFrame_color;
		lastFrame_color = currentFrame;

		processInputMoveColor(window);

		// render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cubeShader.use();
		cubeShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
		cubeShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		model = glm::rotate(model, glm::radians(20.0f), glm::vec3(1.0f, 1.0f, 0.0f));
		view = colorCamera.GetViewMatrix();
		projection = glm::perspective(glm::radians(colorCamera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

		cubeShader.setMat4("view", view);
		cubeShader.setMat4("projection", projection);
		cubeShader.setMat4("model", model);
		glBindVertexArray(cubeVAO);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(cubeVertices));

		sourceShader.use();
		sourceShader.setMat4("view", view);
		sourceShader.setMat4("projection", projection);
		model = glm::mat4(1.0f);
		model = glm::translate(model, lightPos);
		model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
		sourceShader.setMat4("model", model);
		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(cubeVertices));

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &cubeVAO);
	glDeleteVertexArrays(1, &lightVAO);
	glDeleteBuffers(1, &VBO);

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

void processInputMoveColor(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		colorCamera.ProcessKeyboard(FORWARD, deltaTime_color);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		colorCamera.ProcessKeyboard(BACKWARD, deltaTime_color);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		colorCamera.ProcessKeyboard(LEFT, deltaTime_color);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		colorCamera.ProcessKeyboard(RIGHT, deltaTime_color);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback_color(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouseColor)
	{
		lastX_color = xpos;
		lastY_color = ypos;
		firstMouseColor = false;
	}

	float xoffset = xpos - lastX_color;
	float yoffset = lastY_color - ypos; // reversed since y-coordinates go from bottom to top

	lastX_color = xpos;
	lastY_color = ypos;

	colorCamera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback_color(GLFWwindow* window, double xoffset, double yoffset)
{
	colorCamera.ProcessMouseScroll(yoffset);
}
