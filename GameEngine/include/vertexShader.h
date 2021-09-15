#pragma once

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace GE {

	class VertexShader {

	public:

		VertexShader(std::string path);
		~VertexShader();


		unsigned int id();

	private:
		unsigned int m_id;


		GLFWwindow* window = nullptr;


		void checkCompileErrors(GLuint shader, std::string type);


	};

}