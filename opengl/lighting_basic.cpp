#include "./headers/hello_common.h"
#include "./headers/camera.h"
#include "./headers/Shader.h"

void processInputMoveBasic(GLFWwindow *window);
void mouse_callback_basic(GLFWwindow* window, double xpos, double ypos);
void scroll_callback_basic(GLFWwindow* window, double xoffset, double yoffset);

//camera system
const glm::vec3 cameraPos = glm::vec3(0.0f, 1.5f, 3.0f);
const glm::vec3 cameraFront = glm::vec3(1.2f, 1.0f, -3.0f);
const glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

// lighting
const glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

Camera basicCamera(cameraPos);
float lastX_basic = SCR_WIDTH / 2.0f;
float lastY_basic = SCR_HEIGHT / 2.0f;
bool firstMouseBasic = true;

float deltaTime_basic = 0.0f;	// Time between current frame and last frame
float lastFrame_basic = 0.0f; // Time of last frame

int lighting_basic()
{
	GLFWwindow* window = prepareWindow("lighting_basic");
	if (!window) {
		return -1;
	}
	glfwSetCursorPosCallback(window, mouse_callback_basic);
	glfwSetScrollCallback(window, scroll_callback_basic);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	Shader basicShader("./shaders/light_basic.shader.vs", "./shaders/light_basic.shader.fs");
	Shader lampShader("./shaders/light_lamp.shader.vs", "./shaders/light_lamp.shader.fs");

	float cubeVertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	};

	unsigned int cubeVAO;
	glGenVertexArrays(1, &cubeVAO);
	glBindVertexArray(cubeVAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
	// set the vertex attributes 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
	unsigned int lampVAO;
	glGenVertexArrays(1, &lampVAO);
	glBindVertexArray(lampVAO);
	// we only need to bind to the VBO, the container's VBO's data already contains the correct data.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// set the vertex attributes (only position data for our lamp)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// render loop
// -----------
	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime_basic = currentFrame - lastFrame_basic;
		lastFrame_basic = currentFrame;

		processInputMoveBasic(window);

		// render
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		basicShader.use();
		basicShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
		basicShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
		basicShader.setVec3("lightPos", lightPos);
		basicShader.setVec3("viewPos", basicCamera.Position);

		//model = glm::rotate(model, glm::radians(20.0f), glm::vec3(1.0f, 1.0f, 0.0f));
		glm::mat4 projection = glm::perspective(glm::radians(basicCamera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = basicCamera.GetViewMatrix();
		basicShader.setMat4("view", view);
		basicShader.setMat4("projection", projection);

		glm::mat4 model = glm::mat4(1.0f);
		basicShader.setMat4("model", model);
		glBindVertexArray(cubeVAO);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(cubeVertices));

		lampShader.use();
		lampShader.setMat4("view", view);
		lampShader.setMat4("projection", projection);
		model = glm::mat4(1.0f);
		model = glm::translate(model, lightPos);
		model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
		lampShader.setMat4("model", model);

		glBindVertexArray(lampVAO);
		glDrawArrays(GL_TRIANGLES, 0, sizeof(cubeVertices));

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &cubeVAO);
	glDeleteVertexArrays(1, &lampVAO);
	glDeleteBuffers(1, &VBO);

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}


void processInputMoveBasic(GLFWwindow *window)
{
	processInput(window);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		basicCamera.ProcessKeyboard(FORWARD, deltaTime_basic);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		basicCamera.ProcessKeyboard(BACKWARD, deltaTime_basic);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		basicCamera.ProcessKeyboard(LEFT, deltaTime_basic);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		basicCamera.ProcessKeyboard(RIGHT, deltaTime_basic);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback_basic(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouseBasic)
	{
		lastX_basic = xpos;
		lastY_basic = ypos;
		firstMouseBasic = false;
	}

	float xoffset = xpos - lastX_basic;
	float yoffset = lastY_basic - ypos; // reversed since y-coordinates go from bottom to top

	lastX_basic = xpos;
	lastY_basic = ypos;

	basicCamera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback_basic(GLFWwindow* window, double xoffset, double yoffset)
{
	basicCamera.ProcessMouseScroll(yoffset);
}
