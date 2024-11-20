#include "Cubes.h"

Cubes::Cubes() {}

Cubes::~Cubes()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Cubes::initialize3x3(const std::vector<glm::vec3>& faceColors) {
    if (faceColors.size() != 6) return;

    vertices = {
        // Positions          // Colors
        // Back face
        -0.5f, -0.5f, -0.5f, faceColors[0].r, faceColors[0].g, faceColors[0].b,  // Bottom-left
         0.5f, -0.5f, -0.5f, faceColors[0].r, faceColors[0].g, faceColors[0].b,  // Bottom-right
         0.5f,  0.5f, -0.5f, faceColors[0].r, faceColors[0].g, faceColors[0].b,  // Top-right
        -0.5f,  0.5f, -0.5f, faceColors[0].r, faceColors[0].g, faceColors[0].b,  // Top-left

        // Front face
        -0.5f, -0.5f,  0.5f, faceColors[1].r, faceColors[1].g, faceColors[1].b,  // Bottom-left
         0.5f, -0.5f,  0.5f, faceColors[1].r, faceColors[1].g, faceColors[1].b,  // Bottom-right
         0.5f,  0.5f,  0.5f, faceColors[1].r, faceColors[1].g, faceColors[1].b,  // Top-right
        -0.5f,  0.5f,  0.5f, faceColors[1].r, faceColors[1].g, faceColors[1].b,  // Top-left

        // Left face
        -0.5f, -0.5f, -0.5f, faceColors[2].r, faceColors[2].g, faceColors[2].b,  // Bottom-left
        -0.5f,  0.5f, -0.5f, faceColors[2].r, faceColors[2].g, faceColors[2].b,  // Top-left
        -0.5f,  0.5f,  0.5f, faceColors[2].r, faceColors[2].g, faceColors[2].b,  // Top-right
        -0.5f, -0.5f,  0.5f, faceColors[2].r, faceColors[2].g, faceColors[2].b,  // Bottom-right

        // Right face
         0.5f, -0.5f, -0.5f, faceColors[3].r, faceColors[3].g, faceColors[3].b,  // Bottom-left
         0.5f,  0.5f, -0.5f, faceColors[3].r, faceColors[3].g, faceColors[3].b,  // Top-left
         0.5f,  0.5f,  0.5f, faceColors[3].r, faceColors[3].g, faceColors[3].b,  // Top-right
         0.5f, -0.5f,  0.5f, faceColors[3].r, faceColors[3].g, faceColors[3].b,  // Bottom-right

         // Bottom face
         -0.5f, -0.5f, -0.5f, faceColors[4].r, faceColors[4].g, faceColors[4].b,  // Bottom-left
          0.5f, -0.5f, -0.5f, faceColors[4].r, faceColors[4].g, faceColors[4].b,  // Bottom-right
          0.5f, -0.5f,  0.5f, faceColors[4].r, faceColors[4].g, faceColors[4].b,  // Top-right
         -0.5f, -0.5f,  0.5f, faceColors[4].r, faceColors[4].g, faceColors[4].b,  // Top-left

         // Top face
         -0.5f,  0.5f, -0.5f, faceColors[5].r, faceColors[5].g, faceColors[5].b,  // Bottom-left
          0.5f,  0.5f, -0.5f, faceColors[5].r, faceColors[5].g, faceColors[5].b,  // Bottom-right
          0.5f,  0.5f,  0.5f, faceColors[5].r, faceColors[5].g, faceColors[5].b,  // Top-right
         -0.5f,  0.5f,  0.5f, faceColors[5].r, faceColors[5].g, faceColors[5].b   // Top-left
    };

    indices = {
        // Back face
        0, 1, 2, 2, 3, 0,
        // Front face
        4, 5, 6, 6, 7, 4,
        // Left face
        8, 9, 10, 10, 11, 8,
        // Right face
        12, 13, 14, 14, 15, 12,
        // Bottom face
        16, 17, 18, 18, 19, 16,
        // Top face
        20, 21, 22, 22, 23, 20
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
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}
