#pragma once


#include "block.h"

namespace GE {


	class ChunkManager;
	

	class Chunk {

	public:

		Chunk(int x, int y, int z, ChunkManager * chunkManager);
		~Chunk();

		void update(float dt);

		void setRenderer(Renderer* renderer);

		void render();

		void createMesh();

		void rebuildMesh();

		void load();
		void setup();
		void unload();

		bool isLoaded();
		bool isSetup();

		bool shouldRender();

		int getX();
		int getY();
		int getZ();

		glm::vec3 getPosition();

		static const int CHUNK_SIZE = 32;
		static const int WORLD_SIZE = 256;


		void setup_Sphere();

		void setup_Landscape();

	private: // The blocks data

		void deleteMesh(int * ID);

		void createCube(int x, int y, int z, const TextureCoordinates& textureData);

		bool isVisibleThrough(int x, int y, int z);

		Block*** m_blocks;

		Renderer* m_renderer;

		int m_meshID;

		bool m_dirty;

		bool m_loaded;
		bool m_setup;


		int m_posX;
		int m_posY;
		int m_posZ;

		ChunkManager* m_chunkManager;
	};

}