#include "../include/vao.h"

#include <glad/glad.h>

namespace GE {


VAO::VAO(/* args */)
{
    glGenVertexArrays(1, &m_id);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &m_id);
}


int VAO::bind() {
    glBindVertexArray(m_id);

    return GL_TRUE;
}

}