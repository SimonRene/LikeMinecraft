#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <glm/glm.hpp>

//#include <noise/noise.h>

#include "chunk.h"

#include "texture.h"

#define ASYNC_NUM_CHUNKS_PER_FRAME 4

namespace GE {

	typedef std::unordered_map<int, Chunk*> ChunkMap;
	typedef std::vector<Chunk*> ChunkList;

	class ChunkManager
	{

	public:
		ChunkManager(glm::vec3 cameraPosition);

		void update(glm::vec3 cameraPosition, glm::vec3 cameraView);

		void setRenderer(Renderer* renderer);

		Texture* getHeightMapTexture();

		static const int VIEW_DISTANCE = 3;

	private:
		void updateAsyncChunker();

		void updateLoadList();

		void updateSetupList();

		void updateRebuildList();

		void updateFlagsList();

		void updateUnloadList();

		void updateVisibilityList(glm::vec3 cameraPosition);

		void updateRenderList();

		Chunk* createChunk(int x, int y, int z);

		Chunk* getChunkOfBlockCoordinate(int x, int y, int z);

		Chunk* getChunk(int x, int y, int z);

		bool currentChunkChanged(int x, int y, int z);

		int getIndexOfChunk(int x, int y, int z);

		Renderer* m_renderer;

		glm::vec3 m_cameraPosition;
		glm::vec3 m_cameraView;

		ChunkMap m_chunks;

		ChunkList m_vpChunkLoadList;
		ChunkList m_vpChunkSetupList;
		ChunkList m_vpChunkRebuildList;
		ChunkList m_vpChunkUpdateFlagsList;
		ChunkMap m_vpChunkUnloadList;
		ChunkList m_vpChunkVisibilityList;
		ChunkList m_vpChunkRenderList;

		bool m_forceVisibilityUpdate;

		int m_lastCurrentChunkX;
		int m_lastCurrentChunkY;
		int m_lastCurrentChunkZ;

	};

}

