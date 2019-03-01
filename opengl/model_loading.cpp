#include "./headers/shader.h"
#include "./headers/opengl_common.h"
#include "./headers/model.h"

// lighting
extern glm::vec3 lightPos;

//camera system
extern glm::vec3 cameraPos;
extern glm::vec3 cameraFront;
extern glm::vec3 cameraUp;

extern GlobalConfig gConfig;

extern void processInput(GLFWwindow *window);
extern void mouse_callback(GLFWwindow* window, double xpos, double ypos);
extern void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

int model_loading() 
{
	GLFWwindow* window = prepareWindow("lighting_maps");
	if (!window) {
		return -1;
	}
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	// build and compile shaders
	// -------------------------
	Shader modelShader("./shaders/model_loading.shader.vs", "./shaders/model_loading.shader.fs");

	// load models
	// -----------
	Model nanoModel("./models/nanosuit/nanosuit.obj");

	// draw in wireframe
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = gConfig.get_currentFrame();
		processInput(window);
		// render
		// ------
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		modelShader.use();

		// view/projection transformations
		glm::mat4 view = gConfig.get_view();
		glm::mat4 projection = gConfig.get_perspective();
		modelShader.setMat4("view", view);
		modelShader.setMat4("projection", projection);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down
		modelShader.setMat4("model", model);
		nanoModel.Draw(modelShader);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
};