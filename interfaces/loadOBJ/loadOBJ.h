#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "face.h"
#include "vertex3.h"

bool loadOBJ(const std::string& path, std::vector<glm::vec3>& out_vertices, std::vector<Face>& out_faces) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << path << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v") {  // Vertex
            glm::vec3 vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            out_vertices.push_back(vertex);
        } else if (type == "f") {  // Face
            Face face;
            int vertexIndex;
            while (iss >> vertexIndex) {
                std::array<int, 3> vertexData;
                vertexData[0] = vertexIndex - 1;  // Adjust to 0-based indexing
                if (iss.peek() == '/') {
                    iss.ignore();  // Skip the '/'
                    if (iss.peek() != '/') {
                        iss >> vertexData[1];  // Texture coordinates
                    }
                    if (iss.peek() == '/') {
                        iss.ignore();  // Skip the second '/'
                        iss >> vertexData[2];  // Normal coordinates
                    }
                }
                face.vertexIndices.push_back(vertexData);
            }
            out_faces.push_back(face);
        }
    }

    file.close();
    return true;
}