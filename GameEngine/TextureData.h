#pragma once

#include <glm/glm.hpp>

namespace GE {

	class TextureCoordinates {
	public:
		glm::vec2 top;
		glm::vec2 bottom;
		glm::vec2 front;
		glm::vec2 back;
		glm::vec2 left;
		glm::vec2 right;

		TextureCoordinates(glm::vec2 t, glm::vec2 bo, glm::vec2 f, glm::vec2 ba, glm::vec2 l, glm::vec2 r) : top(t), bottom(bo), front(f), back(ba), left(l), right(r) {}
	};

	class TextureData {
	public:


		static const float BLOCK_TEXTURE_SIZE;

		static const TextureCoordinates TYPE_DIRT;
		static const TextureCoordinates TYPE_GRASS;
		static const TextureCoordinates TYPE_STONE;
		static const TextureCoordinates TYPE_COBBLE;
		static const TextureCoordinates TYPE_WOOD;
		static const TextureCoordinates TYPE_BRICK;
		static const TextureCoordinates TYPE_TNT;
		static const TextureCoordinates TYPE_SAND;
		static const TextureCoordinates TYPE_GOLD;
		static const TextureCoordinates TYPE_IRON;
		static const TextureCoordinates TYPE_DIAMOND;
		static const TextureCoordinates TYPE_BEDROCK;
		static const TextureCoordinates TYPE_GRAVEL;
		static const TextureCoordinates TYPE_TREE_TRUNK;
		static const TextureCoordinates TYPE_WORKBENCH;
		static const TextureCoordinates TYPE_OVEN;
		
	};

	

}
