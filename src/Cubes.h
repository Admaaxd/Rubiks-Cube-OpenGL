#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>

class Cubes
{
public:
	Cubes();
	~Cubes();

	void initialize3x3(const std::vector<glm::vec3>& faceColors);
	void Draw();
	void updateOpenGLBuffers();

private:
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	GLuint VAO = 0, VBO = 0, EBO = 0;
};