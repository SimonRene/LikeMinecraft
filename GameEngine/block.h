#pragma once

#include "TextureData.h"
#include "include/renderer.h"

namespace GE {


	enum BlockType {

		BlockType_Default = 0,
		BlockType_Grass,
		BlockType_Dirt,
		BlockType_Water,
		BlockType_Stone,
		BlockType_Wood,
		BlockType_Sand,
		BlockType_Cobble,
		BlockType_Brick,
		BlockType_TNT,
		BlockType_Gold,
		BlockType_Iron,
		BlockType_Diamond,
		BlockType_Bedrock,
		BlockType_Gravel,
		BlockType_Tree_Trunk,
		BlockType_Workbench,
		BlockType_Oven
	};

	/*
	DIRT;
	GRASS;
	STONE;
	COBBLE;
	WOOD;
	BRICK;
	TNT;
	SAND;
	GOLD;
	IRON;
	DIAMOND;
	BEDROCK;
	GRAVEL;
	TREE_TRUNK;
	WORKBENCH;
	OVEN;
	*/


	class Block {

	public:
		Block();

		~Block();

		bool isActive();
		void setActive(bool active);

		void setBlockType(BlockType blockType);

		const TextureCoordinates& getTextureCoordinates();

		static const float BLOCK_RENDER_SIZE;
		

		

	private:
		bool m_active;
		BlockType m_blockType;
	};

	

}
