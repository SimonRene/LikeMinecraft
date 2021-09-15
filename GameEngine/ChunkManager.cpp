#include "ChunkManager.h"

#include <noise/noise.h>

#include "noiseutils.h"

namespace GE {

	ChunkManager::ChunkManager(glm::vec3 cameraPosition) : m_cameraPosition(cameraPosition), m_cameraView({ 0.0f,0.0f,1.0f }), m_forceVisibilityUpdate(false), m_lastCurrentChunkX(1000), m_lastCurrentChunkY(1000), m_lastCurrentChunkZ(1000) {
		
	}

	void ChunkManager::update(glm::vec3 cameraPosition, glm::vec3 cameraView) {

		updateAsyncChunker();


		updateLoadList();

		updateSetupList();

		updateUnloadList();
		/*
		updateRebuildList();

		updateFlagsList();


		updateVisibilityList(cameraPosition);

		if (m_cameraPosition != cameraPosition || m_cameraView != cameraView) {

			//updateRenderList();

		}
		*/
		updateRenderList();

		m_vpChunkVisibilityList.clear();

		auto iterator = m_vpChunkRenderList.begin();

		for (iterator = m_vpChunkRenderList.begin(); iterator != m_vpChunkRenderList.end(); ++iterator) {
			(*iterator)->render();
		}

		m_vpChunkRenderList.clear();
		

		m_cameraPosition = cameraPosition;

		m_cameraView = cameraView;
		
	}



	bool ChunkManager::currentChunkChanged(int x, int y, int z) {
		if (x == m_lastCurrentChunkX && y == m_lastCurrentChunkY && z == m_lastCurrentChunkZ) {
			return false;
		}

		m_lastCurrentChunkX = x;
		m_lastCurrentChunkY = y;
		m_lastCurrentChunkZ = z;

		return true;
	}


	void ChunkManager::updateAsyncChunker() {

		int centerX = (m_cameraPosition.x < 0) ? (int)m_cameraPosition.x / Chunk::CHUNK_SIZE - 1 : (int)m_cameraPosition.x / Chunk::CHUNK_SIZE;
		int centerY = (m_cameraPosition.y < 0) ? (int)m_cameraPosition.y / Chunk::CHUNK_SIZE - 1 : (int)m_cameraPosition.y / Chunk::CHUNK_SIZE;
		int centerZ = (m_cameraPosition.z < 0) ? (int)m_cameraPosition.z / Chunk::CHUNK_SIZE - 1 : (int)m_cameraPosition.z / Chunk::CHUNK_SIZE;

		Chunk* currentChunk = getChunk(centerX, centerY, centerZ);

		bool chunkHasChanged = currentChunkChanged(centerX, centerY, centerZ);

		if (!chunkHasChanged)
		{
			for (auto i = m_chunks.begin(); i != m_chunks.end(); ++i) {
				m_vpChunkLoadList.push_back((*i).second);

				m_vpChunkSetupList.push_back((*i).second);

				m_vpChunkVisibilityList.push_back((*i).second);
				
			}
		}
		else {



			for (auto i = m_chunks.begin(); i != m_chunks.end(); ++i) {
				m_vpChunkUnloadList.insert((*i));
			}
			


			int x, y, z;

			for (int offsetX = -VIEW_DISTANCE; offsetX <= VIEW_DISTANCE; ++offsetX)
			{
				for (int offsetY = -VIEW_DISTANCE; offsetY <= VIEW_DISTANCE; ++offsetY)
				{
					for (int offsetZ = -VIEW_DISTANCE; offsetZ <= VIEW_DISTANCE; ++offsetZ)
					{
						x = centerX + offsetX;
						y = centerY + offsetY;
						z = centerZ + offsetZ;

						Chunk* chunk = getChunk(x, y, z);

						if (chunk == nullptr) {
							continue;
						}

						m_vpChunkLoadList.push_back(chunk);

						m_vpChunkSetupList.push_back(chunk);

						m_vpChunkVisibilityList.push_back(chunk);

						ChunkMap::iterator iterator = m_vpChunkUnloadList.find(getIndexOfChunk(x, y, z));

						if (iterator != m_vpChunkUnloadList.end())
							m_vpChunkUnloadList.erase(iterator);
							
					}
				}
			}

		}
	}


	void ChunkManager::updateLoadList() {

		int lNumOfChunksLoaded = 0;

		ChunkList::iterator iterator;

		for (iterator = m_vpChunkLoadList.begin(); iterator != m_vpChunkLoadList.end() && (lNumOfChunksLoaded != ASYNC_NUM_CHUNKS_PER_FRAME); ++iterator) {

			Chunk* pChunk = (*iterator);

			if (pChunk->isLoaded() == false) {

				if (lNumOfChunksLoaded != ASYNC_NUM_CHUNKS_PER_FRAME) { // can be deleted -> already tested in for loop above
					
					pChunk->load(); // Increase the chunks loaded count

					lNumOfChunksLoaded++;

					m_forceVisibilityUpdate = true;


				}

			}

		} // Clear the load list (every frame)     

		m_vpChunkLoadList.clear();

	}


	void ChunkManager::updateSetupList() { // Setup any chunks that have not already been setup     

		ChunkList::iterator iterator;

		for (iterator = m_vpChunkSetupList.begin(); iterator != m_vpChunkSetupList.end(); ++iterator) {

			Chunk* pChunk = (*iterator);

			if (pChunk->isLoaded() && pChunk->isSetup() == false) {

				pChunk->setup();

				if (pChunk->isSetup()) { // Only force the visibility update if we actually setup the chunk, some chunks wait in the pre-setup stage... 

					m_forceVisibilityUpdate = true;

				}

			}

		} // Clear the setup list (every frame)    

		m_vpChunkSetupList.clear();

	}

	void ChunkManager::updateRebuildList() {

		// Rebuild any chunks that are in the rebuild chunk list     

		ChunkList::iterator iterator;

		int lNumRebuiltChunkThisFrame = 0;

		for (iterator = m_vpChunkRebuildList.begin(); iterator != m_vpChunkRebuildList.end() && (lNumRebuiltChunkThisFrame != ASYNC_NUM_CHUNKS_PER_FRAME); ++iterator) {

			Chunk* pChunk = (*iterator);

			if (pChunk->isLoaded() && pChunk->isSetup()) {

				if (lNumRebuiltChunkThisFrame != ASYNC_NUM_CHUNKS_PER_FRAME) {

					pChunk->rebuildMesh(); // If we rebuild a chunk, add it to the list of chunks that need their render flags updated                 

					// since we might now be empty or surrounded   

					m_vpChunkUpdateFlagsList.push_back(pChunk); // Also add our neighbours since they might now be surrounded too (If we have neighbours)                

					Chunk* pChunkXMinus = getChunk(pChunk->getX() - 1, pChunk->getY(), pChunk->getZ());

					Chunk* pChunkXPlus = getChunk(pChunk->getX() + 1, pChunk->getY(), pChunk->getZ());

					Chunk* pChunkYMinus = getChunk(pChunk->getX(), pChunk->getY() - 1, pChunk->getZ());

					Chunk* pChunkYPlus = getChunk(pChunk->getX(), pChunk->getY() + 1, pChunk->getZ());

					Chunk* pChunkZMinus = getChunk(pChunk->getX(), pChunk->getY(), pChunk->getZ() - 1);

					Chunk* pChunkZPlus = getChunk(pChunk->getX(), pChunk->getY(), pChunk->getZ() + 1);

					if (pChunkXMinus != nullptr) m_vpChunkUpdateFlagsList.push_back(pChunkXMinus);

					if (pChunkXPlus != nullptr) m_vpChunkUpdateFlagsList.push_back(pChunkXPlus);

					if (pChunkYMinus != nullptr) m_vpChunkUpdateFlagsList.push_back(pChunkYMinus);

					if (pChunkYPlus != nullptr) m_vpChunkUpdateFlagsList.push_back(pChunkYPlus);

					if (pChunkZMinus != nullptr) m_vpChunkUpdateFlagsList.push_back(pChunkZMinus);

					if (pChunkZPlus != nullptr) m_vpChunkUpdateFlagsList.push_back(pChunkZPlus); // Only rebuild a certain number of chunks per frame   

					lNumRebuiltChunkThisFrame++;

					m_forceVisibilityUpdate = true;

				}

			}

		}

		// Clear the rebuild list     

		m_vpChunkRebuildList.clear();

	}

	void ChunkManager::updateFlagsList() {
		// TODO
	}


	void ChunkManager::updateUnloadList() { // Unload any chunks

		ChunkMap::iterator iterator;

		for (iterator = m_vpChunkUnloadList.begin(); iterator != m_vpChunkUnloadList.end(); ++iterator) {

			Chunk* pChunk = (*iterator).second;

			if (pChunk->isLoaded()) {

				pChunk->unload();

				int index = (*iterator).first;

				if (index >= 0) {
					m_chunks.erase(m_chunks.find(index));
					delete pChunk;

					m_forceVisibilityUpdate = true;
				}


			}

		} // Clear the unload list (every frame)    

		m_vpChunkUnloadList.clear();

	}

	int ChunkManager::getIndexOfChunk(int x, int y, int z) {

		int worldX = x + Chunk::WORLD_SIZE / 2;
		int worldY = y + Chunk::WORLD_SIZE / 2;
		int worldZ = z + Chunk::WORLD_SIZE / 2;

		if (worldX < 0 || worldY < 0 || worldZ < 0 || worldX >= Chunk::WORLD_SIZE || worldY >= Chunk::WORLD_SIZE || worldZ >= Chunk::WORLD_SIZE) {
			//std::cerr << "ERROR: OUT OF WORLD BOUNDARIES - current chunk: (" << worldX << ", " << worldY << ", " << worldZ << ")" << "local coords (" << x << ", " << y << ", " << z << ")" << std::endl;
			return -1;
		}

		int index = worldX * (Chunk::WORLD_SIZE * Chunk::WORLD_SIZE) + worldY * Chunk::WORLD_SIZE + worldZ;

		return index;
	}

	void ChunkManager::updateVisibilityList(glm::vec3 cameraPosition) {
		// TODO: Update visibility list



	}

	void ChunkManager::updateRenderList() {

		// Clear the render list each frame BEFORE we do our tests to see what chunks should be rendered     

		m_vpChunkRenderList.clear();

		ChunkList::iterator iterator;

		for (iterator = m_vpChunkVisibilityList.begin(); iterator != m_vpChunkVisibilityList.end(); ++iterator) {

			Chunk* pChunk = (*iterator);

			if (pChunk != NULL) {

				if (pChunk->isLoaded() && pChunk->isSetup()) {

					if (pChunk->shouldRender()) // Early flags check so we don't always have to do the frustum check... 

					{// Check if this chunk is inside the camera frustum                    

						float c_offset = (Chunk::CHUNK_SIZE * Block::BLOCK_RENDER_SIZE) - Block::BLOCK_RENDER_SIZE;

						glm::vec3 chunkCenter = pChunk->getPosition() + glm::vec3(c_offset, c_offset, c_offset);

						float c_size = Chunk::CHUNK_SIZE * Block::BLOCK_RENDER_SIZE;

						if (m_renderer->cubeInFrustum(m_renderer->getActiveViewPort(), chunkCenter, c_size, c_size, c_size)) {

							m_vpChunkRenderList.push_back(pChunk);

						}
					}
				}
			}
		}
	}

	Chunk* ChunkManager::getChunkOfBlockCoordinate(int x, int y, int z) {


		int chunkX = (x >= 0) ? (x / Chunk::CHUNK_SIZE) : ((x / Chunk::CHUNK_SIZE) - 1);
		int chunkY = (y >= 0) ? (y / Chunk::CHUNK_SIZE) : ((y / Chunk::CHUNK_SIZE) - 1);
		int chunkZ = (z >= 0) ? (z / Chunk::CHUNK_SIZE) : ((z / Chunk::CHUNK_SIZE) - 1);
		

		return getChunk(chunkX, chunkY, chunkZ);
	}

	Chunk* ChunkManager::getChunk(int x, int y, int z) {
		

		int index = getIndexOfChunk(x, y, z);

		if (index < 0)
			return nullptr;

		if (m_chunks.find(index) == m_chunks.end()) {
			// chunk not found
			m_chunks.insert(std::pair<int,Chunk*>(index, createChunk(x, y, z)));
		}

		Chunk* test = m_chunks[index];

		//std::cout << "LOCAL POS: (" << x << " " << y << " " << z << ") CHUNK POS: (" << test->getX() << " " << test->getY() << " " << test->getZ() << ") WORLD POS: (" << worldX << " " << worldY << " " << worldZ << ")" << std::endl;

		return m_chunks[index];

	}

	Chunk* ChunkManager::createChunk(int x, int y, int z) {

		Chunk* chunk = new Chunk(x,y,z,this);

		chunk->setRenderer(m_renderer);
		
		return chunk;
	}

	void ChunkManager::setRenderer(Renderer* renderer) {
		m_renderer = renderer;
	}


	Texture* ChunkManager::getHeightMapTexture() {

		//Texture tex;

		utils::Image heightMap;


		for (int x = 0; x < Chunk::CHUNK_SIZE; x++) {

			for (int y = 0; y < Chunk::CHUNK_SIZE; y++) { // Use the noise library to get the height value of x, z             

				//float height = m_pChunkManager->GetNoiseValue(x, z);              

				// Use the height map texture to get the height value of x, z  

				float height = ((heightMap.GetValue(x, y).red * (Chunk::CHUNK_SIZE - 1)) * 1.0f) * 1.0f;


			}

		}

		return nullptr;

	}

}