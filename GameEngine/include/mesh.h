#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "../texture.h"



namespace GE {

	enum MeshType {
		COLORED_MESH,
		TEXTURED_MESH
	};

	class ShaderProgram;



	class Mesh {
	public:

		virtual void draw(ShaderProgram* shader) = 0;
		virtual void setupMesh() = 0;

	protected:
		unsigned int VAO, VBO, EBO;

		std::vector<unsigned int> indices;
	};

	class TexturedMesh : public Mesh {
	public:

		struct TexturedVertex {
			TexturedVertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 textureCoordinate);

			glm::vec3 Position;
			glm::vec3 Normal;
			glm::vec2 TextureCoordinate;
		};

	public:

		// mesh data

		TexturedMesh();
		//TexturedMesh(std::vector<TexturedVertex> vertices, std::vector<unsigned int> indices);

		void draw(ShaderProgram* shader);

		void setupMesh();

		unsigned int addVertex(glm::vec3 point, glm::vec3 normal, glm::vec2 textureCoordinate);
		void addTriangleToMesh(unsigned int vertex1, unsigned int vertex2, unsigned int vertex3);

	private:
		std::vector<TexturedVertex> vertices;

		//Texture texture;


	};
	/*
	class TexturedMesh : public Mesh {
	public:

		struct TextureVertex {
			TextureVertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 texureCoordinate);

			glm::vec3 Position;
			glm::vec3 Normal;
			glm::vec2 TeturexCoordinates;
		};


		// mesh data
		std::vector<TextureVertex> vertices;
		std::vector<Texture>       textures;

		TexturedMesh(std::vector<TextureVertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
		void Draw(ShaderProgram& shader);


	private:



	};
	*/
}