#include "../include/ebo.h"

#include <glad/glad.h>

namespace GE {




EBO::EBO(/* args */)
{
    glGenBuffers(1, &m_id);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &m_id);
}


int EBO::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);

    return GL_TRUE;
}

}