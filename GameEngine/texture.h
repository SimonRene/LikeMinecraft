#pragma once

#include <string>

namespace GE {

	class Texture
	{

	public:

		Texture(std::string filePath);

		unsigned int id();


	private:
		unsigned int m_id;
		int m_width, m_height, m_nrChannels;

	};

}