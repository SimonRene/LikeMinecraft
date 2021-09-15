#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace GE {

	class Window {

	public:

		int initializeWindow(int width, int height);

		int clearWindow();

		int updateWindow();

		int destroyWindow();

		// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
		// ---------------------------------------------------------------------------------------------------------
		void processInput();

		void close();

		int shouldClose();

		void updateTime();

	private:

		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);


	private:
		bool m_windowReady = false;

		GLFWwindow* window = nullptr;



	};

}