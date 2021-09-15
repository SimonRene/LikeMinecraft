#include "../include/vertexShader.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace GE {


VertexShader::VertexShader(std::string path) {

    std::ifstream vertexShaderFile;
    vertexShaderFile.open(path);

    std::string line;

    std::stringstream vertexShaderStringStream;
    std::string vertexShaderString;

    if (vertexShaderFile.is_open())
    {
        while (std::getline(vertexShaderFile, line))
        {
            vertexShaderStringStream << line << "\n";
        }

        vertexShaderString = vertexShaderStringStream.str();

        vertexShaderFile.close();
    
        const char *c_str = vertexShaderString.c_str();

        //std::cout << "VERTEX: " << vertexShaderString << std::endl;

        // build and compile our shader program
        // ------------------------------------
        // vertex shader
        m_id = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(m_id, 1, &c_str, NULL);
        glCompileShader(m_id);
        
        // check for shader compile errors
        checkCompileErrors(m_id, "VERTEX");

    }
    else {
        std::cerr << "ERROR::SHADER::VERTEX::FILE_NOT_FOUND at path: " << path << "\n";

        throw std::invalid_argument("ERROR::SHADER::VERTEX::FILE_NOT_FOUND at path " + path);
    }
}


VertexShader::~VertexShader() {
    glDeleteShader(m_id);
}

unsigned int VertexShader::id() {
    return m_id;
}




// utility function for checking shader compilation/linking errors.
// ------------------------------------------------------------------------
void VertexShader::checkCompileErrors(GLuint shader, std::string type)
{
    (void)type;
    GLint success;
    GLchar infoLog[1024];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        std::cout << "ERROR::VERTEX_SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
    }
    
}

}