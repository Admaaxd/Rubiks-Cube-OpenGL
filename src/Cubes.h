#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Cubes
{
public:
	Cubes();
	~Cubes();

	void initialize();
	void Draw();
	void updateOpenGLBuffers();

private:
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	GLuint VAO = 0, VBO = 0, EBO = 0;
};