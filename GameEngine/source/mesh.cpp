#include "../include/mesh.h"

#include "../include/shaderProgram.h"

namespace GE {
	TexturedMesh::TexturedVertex::TexturedVertex(glm::vec3 pos, glm::vec3 normal, glm::vec2 textureCoordinate) : Position(pos), Normal(normal), TextureCoordinate(textureCoordinate) {

	}

	TexturedMesh::TexturedMesh(){// : texture(".\\resource\\textures\\container.jpg"){
	}

	//TexturedMesh::TexturedMesh(std::vector<GE::TexturedMesh::TexturedVertex> vertices, std::vector<unsigned int> indices) { // : texture(".\\resource\\textures\\container.jpg") {

	//}

    unsigned int TexturedMesh::addVertex(glm::vec3 point, glm::vec3 normal, glm::vec2 textureCoordinate) {
        vertices.push_back({ point, normal, textureCoordinate });

        return (unsigned int) vertices.size() - 1;
    }

    void TexturedMesh::addTriangleToMesh(unsigned int vertex1, unsigned int vertex2, unsigned int vertex3) {
        indices.push_back(vertex1);
        indices.push_back(vertex2);
        indices.push_back(vertex3);
    }

	void TexturedMesh::draw(ShaderProgram* shader) {
        //shader->use();
        // bind textures on corresponding texture units
        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, texture.id());
        
        // draw mesh
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
	}

	void TexturedMesh::setupMesh() {
        // create buffers/arrays
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        // load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        // A great thing about structs is that their memory layout is sequential for all its items.
        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
        // again translates to 3/2 floats which translates to a byte array.
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GE::TexturedMesh::TexturedVertex), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        // set the vertex attribute pointers
        // vertex Positions
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GE::TexturedMesh::TexturedVertex), (void*)0);
        // vertex normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GE::TexturedMesh::TexturedVertex), (void*)offsetof(GE::TexturedMesh::TexturedVertex, Normal));
        // vertex texture coords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(GE::TexturedMesh::TexturedVertex), (void*)offsetof(GE::TexturedMesh::TexturedVertex, TextureCoordinate));

        glBindVertexArray(0);
	}



    /*
    
    
    void TexturedMesh::Draw(ShaderProgram& shader) {
        // bind appropriate textures
        unsigned int diffuseNr = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr = 1;
        unsigned int heightNr = 1;
        for (unsigned int i = 0; i < textures.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
            // retrieve texture number (the N in diffuse_textureN)
            string number;
            string name = textures[i].type;
            if (name == "texture_diffuse")
                number = std::to_string(diffuseNr++);
            else if (name == "texture_specular")
                number = std::to_string(specularNr++); // transfer unsigned int to stream
            else if (name == "texture_normal")
                number = std::to_string(normalNr++); // transfer unsigned int to stream
            else if (name == "texture_height")
                number = std::to_string(heightNr++); // transfer unsigned int to stream

            // now set the sampler to the correct texture unit
            glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i);
            // and finally bind the texture
            glBindTexture(GL_TEXTURE_2D, textures[i].id);
        }

        // draw mesh
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // always good practice to set everything back to defaults once configured.
        glActiveTexture(GL_TEXTURE0);
    }
    
    
    */
}
