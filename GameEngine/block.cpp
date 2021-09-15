#include "block.h"


namespace GE {

	const float Block::BLOCK_RENDER_SIZE = 1.0f;
	

	

	Block::Block() {
		m_active = false;
		m_blockType = BlockType::BlockType_Default;
	}

	Block::~Block() {

	}

	bool Block::isActive() {
		return m_active;
	}

	void Block::setActive(bool active) {
		m_active = active;
	}

	void Block::setBlockType(BlockType blockType) {
		m_blockType = blockType;
	}

	const TextureCoordinates& Block::getTextureCoordinates() {

		glm::vec2 textureOrigin(0.0f, 1.0f);

		switch (m_blockType) {
		case BlockType::BlockType_Default:
			return TextureData::TYPE_DIRT;
			break;
		case BlockType::BlockType_Dirt:
			return TextureData::TYPE_DIRT;
			break;
		case BlockType::BlockType_Grass:
			return TextureData::TYPE_GRASS;
			break;
		case BlockType::BlockType_Sand:
			return TextureData::TYPE_SAND;
			break;
		case BlockType::BlockType_Stone:
			return TextureData::TYPE_STONE;
			break;
		case BlockType::BlockType_Water:
			return TextureData::TYPE_DIRT;
			break;
		case BlockType::BlockType_Wood:
			return TextureData::TYPE_WOOD;
			break;
		case BlockType::BlockType_Cobble:
			return TextureData::TYPE_COBBLE;
			break;
		case BlockType::BlockType_Brick:
			return TextureData::TYPE_BRICK;
			break;
		case BlockType::BlockType_TNT:
			return TextureData::TYPE_TNT;
			break;
		case BlockType::BlockType_Gold:
			return TextureData::TYPE_GOLD;
			break;
		case BlockType::BlockType_Iron:
			return TextureData::TYPE_IRON;
			break;
		case BlockType::BlockType_Diamond:
			return TextureData::TYPE_DIAMOND;
			break;
		case BlockType::BlockType_Bedrock:
			return TextureData::TYPE_BEDROCK;
			break;
		case BlockType::BlockType_Gravel:
			return TextureData::TYPE_GRAVEL;
			break;
		case BlockType::BlockType_Tree_Trunk:
			return TextureData::TYPE_TREE_TRUNK;
			break;
		case BlockType::BlockType_Workbench:
			return TextureData::TYPE_WORKBENCH;
			break;
		case BlockType::BlockType_Oven:
			return TextureData::TYPE_OVEN;
			break;
		}
		
	}


	


}
