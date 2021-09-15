#include "TextureData.h"



namespace GE {

	const float TextureData::BLOCK_TEXTURE_SIZE = 1.0f / 16.0f;


	const TextureCoordinates TextureData::TYPE_DIRT = TextureCoordinates(	glm::vec2(2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE),
																			glm::vec2(2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE),
																			glm::vec2(2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE),
																			glm::vec2(2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE),
																			glm::vec2(2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE),
																			glm::vec2(2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE)
	);

	const TextureCoordinates TextureData::TYPE_GRASS = {	{ 0 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_STONE = {	{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_COBBLE = {	{ 0 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 0 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 0 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 0 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 0 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 0 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_WOOD = {		{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_BRICK = {	{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_TNT = {		{ 9 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 10 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 0 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_SAND = {		{ 2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 2 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_GOLD = {		{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 7 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_IRON = {		{ 6 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 6 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 6 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 6 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 6 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 6 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_DIAMOND = {	{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 8 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_BEDROCK = {	{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 1 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_GRAVEL = {	{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 3 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_TREE_TRUNK = {	{ 5 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 5 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 4 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 1 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_WORKBENCH = {	{ 11 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 2 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 11 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 2 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 11 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 3 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 11 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 3 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 12 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 3 * TextureData::BLOCK_TEXTURE_SIZE },
																{ 12 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 3 * TextureData::BLOCK_TEXTURE_SIZE }
	};

	const TextureCoordinates TextureData::TYPE_OVEN = {		{ 14 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 3 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 14 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 3 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 12 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 2 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 13 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 2 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 13 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 2 * TextureData::BLOCK_TEXTURE_SIZE },
															{ 13 * TextureData::BLOCK_TEXTURE_SIZE, 1 - 2 * TextureData::BLOCK_TEXTURE_SIZE }
	};

}
