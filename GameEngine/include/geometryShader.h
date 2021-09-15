#pragma once


#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace GE {

class GeometryShader
{

public:
    GeometryShader(std::string path);
    ~GeometryShader();
    unsigned int id();


private:
    unsigned int m_id;


    GLFWwindow* window = nullptr;


    void checkCompileErrors(GLuint shader, std::string type);
    


};

    
}