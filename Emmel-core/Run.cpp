#include <glad/glad.h>
#include <glfw3.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Shader.h"
#include "ShaderSource.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
glViewport(0, 0, width, height);
}

void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//Escape pressed
		glfwSetWindowShouldClose(window, true);
}


int main()
{
	/*
	Window Handling
	*/
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	GLFWwindow* window = glfwCreateWindow(800, 600, "Test Window", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/*
	Prereq info
	*/

	float vertices[6] =
	{
		//Position
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.0f, 0.5f
	};
	/*
	Init
	*/
	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);//position
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	Shader Program = Shader(source_vertex, source_fragment);

	Program.use();


	/*
	Render Loop
	*/
	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3); //Draw one triangle

		glfwSwapBuffers(window);
		glfwPollEvents();




	} //End render 

	glfwTerminate();
	return 0;
}

