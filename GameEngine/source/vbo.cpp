#include "../include/vbo.h"

#include <glad/glad.h>

namespace GE {

VBO::VBO(/* args */)
{
    glGenBuffers(1, &m_id);

    bind();
}

VBO::~VBO()
{
    glDeleteBuffers(1, &m_id);
}


int VBO::bind() {

    glBindBuffer(GL_ARRAY_BUFFER, m_id);

    return GL_TRUE;
}

}