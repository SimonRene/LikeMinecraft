#include "../include/geometryShader.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace GE {

GeometryShader::GeometryShader(std::string path)
{
    std::ifstream geometryShaderFile;
    geometryShaderFile.open(path);

    std::string line;

    std::stringstream geometryShaderStringStream;
    std::string geometryShaderString;

    if (geometryShaderFile.is_open())
    {
        while (std::getline(geometryShaderFile, line))
        {
            geometryShaderStringStream << line << "\n";
        }

        geometryShaderString = geometryShaderStringStream.str();

        geometryShaderFile.close();
    
        const char *c_str = geometryShaderString.c_str();

        // build and compile our shader program
        // ------------------------------------
        // geometry shader
        m_id = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(m_id, 1, &c_str, NULL);
        glCompileShader(m_id);
        
        // check for shader compile errors
        checkCompileErrors(m_id, "GEOMETRY");

    }
    else {
        std::cerr << "ERROR::SHADER::GEOMETRY::FILE_NOT_FOUND at path: " << path << "\n";

        throw std::invalid_argument("ERROR::SHADER::GEOMETRY::FILE_NOT_FOUND at path " + path);
    }
}

GeometryShader::~GeometryShader()
{
    glDeleteShader(m_id);
}


unsigned int GeometryShader::id() {
    return m_id;
}





// utility function for checking shader compilation/linking errors.
// ------------------------------------------------------------------------
void GeometryShader::checkCompileErrors(GLuint shader, std::string type)
{
    (void)type;
    GLint success;
    GLchar infoLog[1024];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        std::cout << "ERROR::GEOMETRY_SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
    }
    
}

}