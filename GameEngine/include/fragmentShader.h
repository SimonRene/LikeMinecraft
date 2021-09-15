#pragma once

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace GE {

	class FragmentShader {

	public:

		FragmentShader(std::string path);
		~FragmentShader();

		unsigned int id();



	private:
		unsigned int m_id;


		GLFWwindow* window = nullptr;

		void checkCompileErrors(GLuint shader, std::string type);

	};

}