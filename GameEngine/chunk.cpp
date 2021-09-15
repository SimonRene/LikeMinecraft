#include "chunk.h"
#include "include/camera.h"
#include <string>

#include <glm/ext.hpp>

#include <noise/noise.h>

#include "noiseutils.h"

#include "ChunkManager.h"

std::string vecStr(glm::vec3 vec) {
	return ("(" + std::to_string(vec.x) + " , " + std::to_string(vec.y) + " , " + std::to_string(vec.z) + ")");
}

std::string vecStr(glm::vec2 vec) {
	return ("(" + std::to_string(vec.x) + " , " + std::to_string(vec.y) + ")");
}


namespace GE {



	Chunk::Chunk(int x, int y, int z, ChunkManager * chunkManager) : m_blocks(nullptr), m_meshID(-1), m_renderer(nullptr), m_loaded(false), m_dirty(false), m_setup(false), m_posX(x), m_posY(y), m_posZ(z), m_chunkManager(chunkManager) { // Create the blocks

		//std::cout << "(" << m_posX << ", " << m_posY << ", " << m_posZ << ")" << " instantiated" << std::endl;

	}


	Chunk::~Chunk() { // Delete the blocks
		if (m_loaded) {
			for (int i = 0; i < CHUNK_SIZE; ++i) {
				for (int j = 0; j < CHUNK_SIZE; ++j) {
					delete[] m_blocks[i][j];
				}
				delete[] m_blocks[i];
			}
			delete[] m_blocks;
		}
	}


	void Chunk::load() {
		// TODO: What is here supposed to be loaded?

		m_dirty = true;

		m_blocks = new Block * *[CHUNK_SIZE];

		for (int i = 0; i < CHUNK_SIZE; i++) {
			m_blocks[i] = new Block * [CHUNK_SIZE];

			for (int j = 0; j < CHUNK_SIZE; j++) {
				m_blocks[i][j] = new Block[CHUNK_SIZE];
			}
		}

		/*
		m_blocks[0][1][1].setActive(true);
		m_blocks[0][2][2].setActive(true);
		m_blocks[0][3][3].setActive(true);
		m_blocks[0][4][4].setActive(true);
		m_blocks[0][5][5].setActive(true);
		m_blocks[0][6][6].setActive(true);
		m_blocks[0][7][7].setActive(true);
		m_blocks[0][8][8].setActive(true);
		m_blocks[0][9][9].setActive(true);
		m_blocks[0][10][10].setActive(true);
		m_blocks[0][11][11].setActive(true);
		m_blocks[0][12][12].setActive(true);
		m_blocks[0][13][13].setActive(true);
		m_blocks[0][14][14].setActive(true);
		m_blocks[0][15][15].setActive(true);

		m_blocks[2][15][15].setActive(true);
		m_blocks[4][15][15].setActive(true);
		m_blocks[0][1][1].setBlockType(BlockType_Grass);
		m_blocks[0][2][2].setBlockType(BlockType_Dirt);
		m_blocks[0][3][3].setBlockType(BlockType_Water);
		m_blocks[0][4][4].setBlockType(BlockType_Stone);
		m_blocks[0][5][5].setBlockType(BlockType_Wood);
		m_blocks[0][6][6].setBlockType(BlockType_Sand);
		m_blocks[0][7][7].setBlockType(BlockType_Cobble);
		m_blocks[0][8][8].setBlockType(BlockType_Brick);
		m_blocks[0][9][9].setBlockType(BlockType_TNT);
		m_blocks[0][10][10].setBlockType(BlockType_Gold);
		m_blocks[0][11][11].setBlockType(BlockType_Iron);
		m_blocks[0][12][12].setBlockType(BlockType_Diamond);
		m_blocks[0][13][13].setBlockType(BlockType_Bedrock);
		m_blocks[0][14][14].setBlockType(BlockType_Gravel);
		m_blocks[0][15][15].setBlockType(BlockType_Tree_Trunk);

		m_blocks[2][15][15].setBlockType(BlockType_Workbench);
		m_blocks[4][15][15].setBlockType(BlockType_Oven);



		for (int i = 0; i < 100; ++i) {
			int x = std::rand() % CHUNK_SIZE;
			int y = std::rand() % CHUNK_SIZE;
			int z = std::rand() % CHUNK_SIZE;

			m_blocks[x][y][z].setActive(true);
		}

		*/

		//setup_Sphere();

		setup_Landscape();



		m_blocks[0][0][0].setActive(true);
		m_blocks[CHUNK_SIZE - 1][0][0].setActive(true);
		m_blocks[0][CHUNK_SIZE - 1][0].setActive(true);
		m_blocks[0][0][CHUNK_SIZE - 1].setActive(true);
		m_blocks[CHUNK_SIZE - 1][CHUNK_SIZE - 1][0].setActive(true);
		m_blocks[0][CHUNK_SIZE - 1][CHUNK_SIZE - 1].setActive(true);
		m_blocks[CHUNK_SIZE - 1][0][CHUNK_SIZE - 1].setActive(true);
		m_blocks[CHUNK_SIZE - 1][CHUNK_SIZE - 1][CHUNK_SIZE - 1].setActive(true);

		m_blocks[0][0][0].setBlockType(BlockType_Gold);
		m_blocks[CHUNK_SIZE - 1][0][0].setBlockType(BlockType_Gold);
		m_blocks[0][CHUNK_SIZE - 1][0].setBlockType(BlockType_Gold);
		m_blocks[0][0][CHUNK_SIZE - 1].setBlockType(BlockType_Gold);
		m_blocks[CHUNK_SIZE - 1][CHUNK_SIZE - 1][0].setBlockType(BlockType_Gold);
		m_blocks[0][CHUNK_SIZE - 1][CHUNK_SIZE - 1].setBlockType(BlockType_Gold);
		m_blocks[CHUNK_SIZE - 1][0][CHUNK_SIZE - 1].setBlockType(BlockType_Gold);
		m_blocks[CHUNK_SIZE - 1][CHUNK_SIZE - 1][CHUNK_SIZE - 1].setBlockType(BlockType_Gold);

		//m_blocks[0][1][1].setBlockType(BlockType_Grass);
		//m//_blocks[0][2][2].setBlockType(BlockType_Dirt);
		//m_blocks[0][3][3].setBlockType(BlockType_Water);
		//m_blocks[0][4][4].setBlockType(BlockType_Stone);



		m_loaded = true;

		//std::cout << "(" << m_posX << ", " << m_posY << ", " << m_posZ << ")" << " loaded" << std::endl;
	}


	void Chunk::render()

	{

		//m_renderer->PushMatrix();

		//m_renderer->ImmediateColourAlpha(1.0 f, 1.0 f, 1.0 f, 1.0 f);

		//m_renderer->SetRenderMode(RM_TEXTURED_LIGHTING);

		//float x = m_position.x;

		//float y = m_position.y;

		//float z = m_position.z;
		//m_renderer->translateWorldMatrix((float)m_posX, (float)m_posY , (float)m_posZ );
		m_renderer->translateWorldMatrix((float)(m_posX * CHUNK_SIZE), (float)m_posY * CHUNK_SIZE, (float)m_posZ * CHUNK_SIZE);
		//std::cout << "RENDER CHUNK" << std::endl;

		if (m_meshID != -1) {

			//std::cout << "rendering mesh: " << m_meshID << std::endl; 

			m_renderer->renderMesh(m_meshID);

			//std::cout << "RENDERED CHUNK" << std::endl;

		}

		//m_renderer->popMatrix();

	}

	void Chunk::deleteMesh(int * ID) {
		
	}

	void Chunk::createMesh() {

		m_renderer->createMesh(&m_meshID);

		for (int x = 0; x < CHUNK_SIZE; x++) {

			for (int y = 0; y < CHUNK_SIZE; y++) {

				for (int z = 0; z < CHUNK_SIZE; z++) {

					if (m_blocks[x][y][z].isActive() == false) { // Don't create triangle data for inactive blocks

						continue;

					}

					//createCube(x, y, z, m_blocks[x][y][z].getTextureCoordinates());

					createCube(x, y, z, m_blocks[x][y][z].getTextureCoordinates());

				}

			}

		}

		m_renderer->finishMesh(m_meshID, -1, 1 /* m_pChunkManager->GetMaterialID() */);
	}

	void Chunk::createCube(int x, int y, int z, const TextureCoordinates& textureData) {

		
		float textureSize = TextureData::BLOCK_TEXTURE_SIZE;


		x = x * Block::BLOCK_RENDER_SIZE;
		y = y * Block::BLOCK_RENDER_SIZE;
		z = z * Block::BLOCK_RENDER_SIZE;

		glm::vec3 p1(x,								y,								z);

		glm::vec3 p2(x + Block::BLOCK_RENDER_SIZE,	y,								z);

		glm::vec3 p3(x + Block::BLOCK_RENDER_SIZE,	y + Block::BLOCK_RENDER_SIZE,	z);

		glm::vec3 p4(x,								y + Block::BLOCK_RENDER_SIZE,	z);

		glm::vec3 p5(x + Block::BLOCK_RENDER_SIZE,	y,								z + Block::BLOCK_RENDER_SIZE);

		glm::vec3 p6(x,								y,								z + Block::BLOCK_RENDER_SIZE);

		glm::vec3 p7(x,								y + Block::BLOCK_RENDER_SIZE,	z + Block::BLOCK_RENDER_SIZE);

		glm::vec3 p8(x + Block::BLOCK_RENDER_SIZE,	y + Block::BLOCK_RENDER_SIZE,	z + Block::BLOCK_RENDER_SIZE);

		glm::vec3 n1;

		unsigned int v1;

		unsigned int v2;

		unsigned int v3;

		unsigned int v4;

		unsigned int v5;

		unsigned int v6;

		unsigned int v7;

		unsigned int v8;

		    
		glm::vec2 off1(textureSize, -textureSize);
		glm::vec2 off2(0.0f, -textureSize);
		glm::vec2 off3(0.0f, 0.0f);
		glm::vec2 off4(textureSize, 0.0f);

		// Front 
		n1 = glm::vec3(0.0f, 0.0f, -1.0f);

		if (isVisibleThrough(x,y,z-1)) {

			v1 = m_renderer->addVertexToMesh(m_meshID, p1, n1, textureData.front + off1);

			v2 = m_renderer->addVertexToMesh(m_meshID, p2, n1, textureData.front + off2);

			v3 = m_renderer->addVertexToMesh(m_meshID, p3, n1, textureData.front + off3);

			v4 = m_renderer->addVertexToMesh(m_meshID, p4, n1, textureData.front + off4);

			m_renderer->addTriangleToMesh(m_meshID, v1, v2, v3);

			m_renderer->addTriangleToMesh(m_meshID, v1, v3, v4);      
		}

		// Back 
		n1 = glm::vec3(0.0f, 0.0f, 1.0f);

		if (isVisibleThrough(x, y, z+1)) {

			v5 = m_renderer->addVertexToMesh(m_meshID, p5, n1, textureData.back + off1);

			v6 = m_renderer->addVertexToMesh(m_meshID, p6, n1, textureData.back + off2);

			v7 = m_renderer->addVertexToMesh(m_meshID, p7, n1, textureData.back + off3);

			v8 = m_renderer->addVertexToMesh(m_meshID, p8, n1, textureData.back + off4);

			m_renderer->addTriangleToMesh(m_meshID, v5, v6, v7);

			m_renderer->addTriangleToMesh(m_meshID, v5, v7, v8);     
		}

		// Right    
		n1 = glm::vec3(1.0f, 0.0f, 0.0f);

		if (isVisibleThrough(x+1, y, z)) {

			v2 = m_renderer->addVertexToMesh(m_meshID, p2, n1, textureData.right + off1);

			v5 = m_renderer->addVertexToMesh(m_meshID, p5, n1, textureData.right + off2);

			v8 = m_renderer->addVertexToMesh(m_meshID, p8, n1, textureData.right + off3);

			v3 = m_renderer->addVertexToMesh(m_meshID, p3, n1, textureData.right + off4);

			m_renderer->addTriangleToMesh(m_meshID, v2, v5, v8);

			m_renderer->addTriangleToMesh(m_meshID, v2, v8, v3);   

		}

		// Left   
		n1 = glm::vec3(-1.0f, 0.0f, 0.0f);

		if (isVisibleThrough(x-1, y, z)) {

			v6 = m_renderer->addVertexToMesh(m_meshID, p6, n1, textureData.left + off1);

			v1 = m_renderer->addVertexToMesh(m_meshID, p1, n1, textureData.left + off2);

			v4 = m_renderer->addVertexToMesh(m_meshID, p4, n1, textureData.left + off3);

			v7 = m_renderer->addVertexToMesh(m_meshID, p7, n1, textureData.left + off4);

			m_renderer->addTriangleToMesh(m_meshID, v6, v1, v4);

			m_renderer->addTriangleToMesh(m_meshID, v6, v4, v7);    

		}

		// Top 
		n1 = glm::vec3(0.0f, 1.0f, 0.0f);

		if (isVisibleThrough(x, y+1, z)) {

			v4 = m_renderer->addVertexToMesh(m_meshID, p4, n1, textureData.top + off1);

			v3 = m_renderer->addVertexToMesh(m_meshID, p3, n1, textureData.top + off2);

			v8 = m_renderer->addVertexToMesh(m_meshID, p8, n1, textureData.top + off3);

			v7 = m_renderer->addVertexToMesh(m_meshID, p7, n1, textureData.top + off4);

			m_renderer->addTriangleToMesh(m_meshID, v4, v3, v8);

			m_renderer->addTriangleToMesh(m_meshID, v4, v8, v7);     

		}

		// Bottom 
		n1 = glm::vec3(0.0f, -1.0f, 0.0f);

		if (isVisibleThrough(x, y-1, z)) {

			v6 = m_renderer->addVertexToMesh(m_meshID, p6, n1, textureData.bottom + off1);

			v5 = m_renderer->addVertexToMesh(m_meshID, p5, n1, textureData.bottom + off2);

			v2 = m_renderer->addVertexToMesh(m_meshID, p2, n1, textureData.bottom + off3);

			v1 = m_renderer->addVertexToMesh(m_meshID, p1, n1, textureData.bottom + off4);

			m_renderer->addTriangleToMesh(m_meshID, v6, v5, v2);

			m_renderer->addTriangleToMesh(m_meshID, v6, v2, v1);
		}

		//std::cout << "Generated Mesh " << " X: " << m_posX << " Y: " << m_posY << std::endl;
	}

	bool Chunk::isVisibleThrough(int x, int y, int z) {

		// TODO OPTIMIZATION test for chunk border visibility -> currently always render chunk border
		if (x < 0 || x >= CHUNK_SIZE)
			return true;
		if (y < 0 || y >= CHUNK_SIZE)
			return true;
		if (z < 0 || z >= CHUNK_SIZE)
			return true;

		if (!m_blocks[x][y][z].isActive())
			return true;

		// TODO test for transparency

		return false;
		
	}

	void Chunk::rebuildMesh() {
		// TODO: rebuild mesh
	}


	void Chunk::update(float dt) {

		//if (m_dirty) {
		//	createMesh();
		//}
		
	}

	void Chunk::setRenderer(Renderer* renderer) {
		m_renderer = renderer;
	}


	void Chunk::setup() {
		// TODO: What is here supposed to be setup?

		createMesh();

		m_setup = true;

		//std::cout << "(" << m_posX << ", " << m_posY << ", " << m_posZ << ")" << " setup" << std::endl;
	}

	void Chunk::unload() {
		if (m_loaded) {
			for (int i = 0; i < CHUNK_SIZE; ++i) {
				for (int j = 0; j < CHUNK_SIZE; ++j) {
					delete[] m_blocks[i][j];
				}
				delete[] m_blocks[i];
			}
			delete[] m_blocks;

			m_loaded = false;

			//std::cout << "(" << m_posX << ", " << m_posY << ", " << m_posZ << ")" << " unloaded" << std::endl;
		}
	}


	bool Chunk::isLoaded() {
		return m_loaded;
	}

	bool Chunk::isSetup() {
		return m_setup;
	}

	bool Chunk::shouldRender() {
		return true;
	}

	
	int Chunk::getX() {
		return m_posX;
	}

	int Chunk::getY() {
		return m_posY;
	}

	int Chunk::getZ() {
		return m_posZ;
	}

	glm::vec3 Chunk::getPosition() {
		return { (float)m_posX, (float)m_posY, (float)m_posZ, };
	}



	void Chunk::setup_Landscape() {
		

		module::Perlin myModule;

		utils::NoiseMap heightMap;
		utils::NoiseMapBuilderPlane heightMapBuilder;
		heightMapBuilder.SetSourceModule(myModule);
		heightMapBuilder.SetDestNoiseMap(heightMap);

		heightMapBuilder.SetDestSize(CHUNK_SIZE, CHUNK_SIZE);

		heightMapBuilder.SetBounds(m_posX, (double)m_posX+1, m_posZ, (double)m_posZ+1);
		
		heightMapBuilder.Build();

		utils::RendererImage renderer;
		utils::Image image;
		renderer.SetSourceNoiseMap(heightMap);
		renderer.SetDestImage(image);

		renderer.Render();


		//noise::module::Perlin myModule;

		for (int x = 0; x < CHUNK_SIZE; x++) {

			for (int z = 0; z < CHUNK_SIZE; z++) { // Use the noise library to get the height value of x, z             

			  //float height = m_pChunkManager->GetNoiseValue(x, z);              

			  // Use the height map texture to get the height value of x, z  
				float height = 0.0f;
				if (m_posY == 0) {
					height = ((((float)image.GetValue(x,z).red / 255.0f) * (CHUNK_SIZE - 1)) * 1.0f) * 1.0f;
				}
				else if (m_posY < 0) {
					height = CHUNK_SIZE;
				}

				//float height = (myModule.GetValue(x, z, 0.5) * (CHUNK_SIZE - 1) * 1.0f) * 1.0f;

				//std::cout << "noise height " << height << std::endl;

				for (int y = 0; y < height && y < CHUNK_SIZE; y++) {

					m_blocks[x][y][z].setActive(true);

					m_blocks[x][y][z].setBlockType(BlockType_Grass);

				}
			}
		}
		


	}


	void Chunk::setup_Sphere() {

		for (int z = 0; z < CHUNK_SIZE; z++) {

			for (int y = 0; y < CHUNK_SIZE; y++) {

				for (int x = 0; x < CHUNK_SIZE; x++) {

					if (sqrt((float)(x - CHUNK_SIZE / 2) * (x - CHUNK_SIZE / 2) + (y - CHUNK_SIZE / 2) * (y - CHUNK_SIZE / 2) + (z - CHUNK_SIZE / 2) * (z - CHUNK_SIZE / 2)) <= CHUNK_SIZE / 2) {

						m_blocks[x][y][z].setActive(true);

						m_blocks[x][y][z].setBlockType(BlockType_Grass);

					}

				}

			}

		}

	}

}