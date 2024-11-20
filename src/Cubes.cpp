#include "Cubes.h"

Cubes::Cubes()
{
}

Cubes::~Cubes()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Cubes::initialize()
{
    vertices = {
        // Positions          // Colors
        // Back face
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // White
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // White
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // White
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // White

        // Front face
        -0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  // Green
         0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  // Green
         0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  // Green
        -0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  // Green

        // Left face
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // Red
        -0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // Red
        -0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  // Red
        -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  // Red

        // Bottom face
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,  // Yellow
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,  // Yellow
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f,  // Yellow
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f,  // Yellow

        // Top face
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // White
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // White
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,  // White
        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,  // White

        // Right face
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // White
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // White
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,  // White
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f   // White
    };

    indices = {
        // Back face
        0, 1, 2,
        2, 3, 0,
        // Front face
        4, 5, 6,
        6, 7, 4,
        // Left face
        8, 9, 10,
        10, 11, 8,
        // Bottom face
        12, 13, 14,
        14, 15, 12,
        // Top face
        16, 17, 18,
        18, 19, 16,
        // Right face
        20, 21, 22,
        22, 23, 20
    };

    updateOpenGLBuffers();
}

void Cubes::Draw()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Cubes::updateOpenGLBuffers()
{
    // Generate and bind VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate and bind VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    // Generate and bind EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Define vertex attribute layout
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    // Unbind VAO
    glBindVertexArray(0);
}
