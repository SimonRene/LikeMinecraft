#include "../include/renderer.h"

#include <glm/ext.hpp>

#include "../include/shaderProgram.h"

namespace GE {


	Renderer::Renderer() : m_shaderProgram(nullptr) {}

	Renderer::Renderer(ShaderProgram* shaderProgram) : m_shaderProgram(shaderProgram) {}

	Renderer::~Renderer() {
		delete m_shaderProgram;
	}

	void Renderer::setShader(ShaderProgram* shaderProgram) {
		m_shaderProgram = shaderProgram;
	}

	void Renderer::createMesh(int* id) {

		// delete mesh?
		auto test = m_meshes.find(*id);

		if (test != m_meshes.end()) {
			//(*test).second;
			m_meshes.erase(*id);
		}

		TexturedMesh mesh;
		
		m_meshes.insert(std::pair<unsigned int, TexturedMesh>(++mesh_index, mesh));

		(*id) = (int)mesh_index;
			
	}

	unsigned int Renderer::addVertexToMesh(unsigned int mesh_id, glm::vec3 point, glm::vec3 normal, glm::vec2 textureCoordinate) {
		return m_meshes[mesh_id].addVertex(point, normal, textureCoordinate);
	}

	void Renderer::addTriangleToMesh(unsigned int mesh_id, unsigned int vertex1, unsigned int vertex2, unsigned int vertex3) {
		m_meshes[mesh_id].addTriangleToMesh(vertex1, vertex2, vertex3);
	}


	void Renderer::finishMesh(unsigned int mesh_id, int someValue, unsigned int material_id) {
		m_meshes[mesh_id].setupMesh();
	}

	void Renderer::pushMatrix() {

	}

	void Renderer::popMatrix() {

	}

	void Renderer::immediateColourAlpha(float r, float g, float b, float a) {

	}

	void Renderer::setRenderMode(unsigned int render_mode) {

	}

	void Renderer::translateWorldMatrix(float x, float y, float z) {
		glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		model = glm::translate(model, glm::vec3(x,y,z));

		m_shaderProgram->setMat4("model", model);
	}

	void Renderer::renderMesh(unsigned int mesh_id) {

		//if (m_meshes.find(mesh_id) != m_meshes.end()) {
		//	std::cout << "MESH FOUND" << std::endl;
		//}


		m_meshes[mesh_id].draw(m_shaderProgram);
	}


	int Renderer::getActiveViewPort() {
		// TODO
		return 0;
	}

	bool Renderer::cubeInFrustum(/* TODO: Viewport, */int test, glm::vec3 chunkCenter, float sizeX, float sizeY, float sizeZ) {
		// TODO
		return true;
	}
}