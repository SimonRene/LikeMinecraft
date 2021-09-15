#pragma once

#include <iostream>

#include <map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "mesh.h"

namespace GE {

	class Renderer {

		

	public:

		Renderer();
		Renderer(ShaderProgram* shaderProgram);
		~Renderer();

		void setShader(ShaderProgram* shaderProgram);

		void createMesh(int* id);

		// adds a vertex at position "point" with "normal" and color "rgba"
		// returns the vertex id
		unsigned int addVertexToMesh(unsigned int mesh_id, glm::vec3 point, glm::vec3 normal, glm::vec2 textureCoordinate);

		// adds a triangle consisting of three vertex to the mesh with "mesh_id"
		void addTriangleToMesh(unsigned int mesh_id, unsigned int vertex1, unsigned int vertex2, unsigned int vertex3);


		void finishMesh(unsigned int mesh_id, int someValue /* = -1 */, unsigned int material_id);


		void pushMatrix();

		void popMatrix();


		void immediateColourAlpha(float r, float g, float b, float a);


		void setRenderMode(unsigned int render_mode);


		void translateWorldMatrix(float x, float y, float z);

		int getActiveViewPort();
		void renderMesh(unsigned int mesh_id);

		bool cubeInFrustum(/* TODO: Viewport, */int test, glm::vec3 chunkCenter, float sizeX, float sizeY, float sizeZ);

	private:
		
		std::map<unsigned int, TexturedMesh> m_meshes;


		ShaderProgram* m_shaderProgram = nullptr;

		unsigned int mesh_index = 0;


	};

}