#pragma once
#include <fstream>
#include "framebuffer.h"

struct Bitmap{
    Framebuffer framebuffer = Framebuffer();
    const std::string filename = "out.bmp";

    void render() {
        framebuffer.setClearColor(Color(0, 0, 0));
        framebuffer.clear();

        framebuffer.setCurrentColor(Color(100, 150, 100));
        framebuffer.point(Vertex2(100, 100));
        framebuffer.point(Vertex2(200, 200));
        framebuffer.drawLine(100, 100, 200, 200);
        std::vector<Vertex2> points = {Vertex2(100, 100), Vertex2(200, 200), Vertex2(150, 300)};
        framebuffer.drawPolygon(points);
        framebuffer.fillPolygon(points);
        renderBuffer();
    }

    void renderBuffer() {
        const int width = framebuffer.framebufferWidth;
        const int height = framebuffer.framebufferHeight;

        constexpr int BMP_HEADER_SIZE = 14;
        constexpr int DIB_HEADER_SIZE = 40;
        const int paddingSize = (4 - (width * 3) % 4) % 4;
        const int fileSize = BMP_HEADER_SIZE + DIB_HEADER_SIZE + (3 * width + paddingSize) * height;

        char bmpHeader[BMP_HEADER_SIZE] = {
            'B', 'M',
            static_cast<char>(fileSize), static_cast<char>(fileSize >> 8), static_cast<char>(fileSize >> 16), static_cast<char>(fileSize >> 24),
            0, 0, 0, 0,
            static_cast<char>(BMP_HEADER_SIZE + DIB_HEADER_SIZE), static_cast<char>((BMP_HEADER_SIZE + DIB_HEADER_SIZE) >> 8), static_cast<char>((BMP_HEADER_SIZE + DIB_HEADER_SIZE) >> 16), static_cast<char>((BMP_HEADER_SIZE + DIB_HEADER_SIZE) >> 24)
        };

        char dibHeader[DIB_HEADER_SIZE] = {
            static_cast<char>(DIB_HEADER_SIZE), static_cast<char>(DIB_HEADER_SIZE >> 8), static_cast<char>(DIB_HEADER_SIZE >> 16), static_cast<char>(DIB_HEADER_SIZE >> 24),
            static_cast<char>(width), static_cast<char>(width >> 8), static_cast<char>(width >> 16), static_cast<char>(width >> 24),
            static_cast<char>(height), static_cast<char>(height >> 8), static_cast<char>(height >> 16), static_cast<char>(height >> 24),
            1, 0,
            24, 0,
            0, 0, 0, 0,
            static_cast<char>((3 * width + paddingSize) * height), static_cast<char>(((3 * width + paddingSize) * height) >> 8), static_cast<char>(((3 * width + paddingSize) * height) >> 16), static_cast<char>(((3 * width + paddingSize) * height) >> 24),
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };

        std::ofstream file(filename, std::ios::binary);
        if (!file) {
            std::cerr << "Error al abrir el archivo " << filename << std::endl;
            return;
        }

        file.write(bmpHeader, BMP_HEADER_SIZE);
        file.write(dibHeader, DIB_HEADER_SIZE);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int index = y * width + x;
                Color color = framebuffer.framebuffer[index];
                file.write(reinterpret_cast<const char*>(&color.b), 1);
                file.write(reinterpret_cast<const char*>(&color.g), 1);
                file.write(reinterpret_cast<const char*>(&color.r), 1);
            }

            for (int i = 0; i < paddingSize; i++) {
                file.put(0);
            }
        }

        file.close();

        std::cout << "Archivo " << filename << " generado correctamente." << std::endl;
    }

};