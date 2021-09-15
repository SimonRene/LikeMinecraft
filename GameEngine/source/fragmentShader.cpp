#include "../include/fragmentShader.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace GE {


FragmentShader::FragmentShader(std::string path) {

    std::ifstream fragmentShaderFile;
    fragmentShaderFile.open(path);

    std::string line;

    std::stringstream fragmentShaderStringStream;
    std::string fragmentShaderString;

    if (fragmentShaderFile.is_open())
    {
        while (std::getline(fragmentShaderFile, line))
        {
            fragmentShaderStringStream << line << "\n";
        }

        fragmentShaderString = fragmentShaderStringStream.str();

        fragmentShaderFile.close();
    
        const char *c_str = fragmentShaderString.c_str();

        //std::cout << "FRAGMENT: " << fragmentShaderString << std::endl;

        // build and compile our shader program
        // ------------------------------------
        // vertex shader
        m_id = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(m_id, 1, &c_str, NULL);
        glCompileShader(m_id);

        // check for shader compile errors
        checkCompileErrors(m_id, "FRAGMENT");

    }
    else {
        std::cerr << "ERROR::SHADER::FRAGMENT::FILE_NOT_FOUND at path: " << path << "\n";
        
        throw std::invalid_argument("ERROR::SHADER::FRAGMENT::FILE_NOT_FOUND at path " + path);
    }
}


FragmentShader::~FragmentShader() {
    glDeleteShader(m_id);
}


unsigned int FragmentShader::id() {
    return m_id;
}




// utility function for checking shader compilation/linking errors.
// ------------------------------------------------------------------------
void FragmentShader::checkCompileErrors(GLuint shader, std::string type)
{
    (void)type;
    GLint success;
    GLchar infoLog[1024];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        std::cout << "ERROR::FRAGMENT_SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
    }
}

}