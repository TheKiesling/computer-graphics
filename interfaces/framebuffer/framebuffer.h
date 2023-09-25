#pragma once
#include "color.h"
#include <SDL2/SDL.h>

struct Framebuffer {
    Color clearColor;
    Color currentColor;
    
    Framebuffer()
    : clearColor(Color(0, 0, 0)),
        currentColor(Color(255, 255, 255)) {
            clear();
        }

    void clear() {
        for (int i = 0; i < FRAMEBUFFER_SIZE; i++) {
            framebuffer[i] = clearColor;
        }
    }

    void setColor(const Color& color) {
        currentColor = color;
    }



    void renderBuffer(SDL_Renderer* renderer) {
        SDL_Texture* texture = SDL_CreateTexture(
            renderer, 
            SDL_PIXELFORMAT_RGB24,
            SDL_TEXTUREACCESS_STREAMING,
            WINDOW_WIDTH, 
            WINDOW_HEIGHT
        );

        void* texturePixels;
        int pitch;
        SDL_LockTexture(texture, NULL, &texturePixels, &pitch);

        Uint32 format = SDL_PIXELFORMAT_RGB24;
        SDL_PixelFormat* mappingFormat = SDL_AllocFormat(format);

        Uint32* texturePixels32 = static_cast<Uint32*>(texturePixels);
        for (int y = 0; y < WINDOW_HEIGHT; y++) {
            for (int x = 0; x < WINDOW_WIDTH; x++) {
                int index = y * (pitch / sizeof(Uint32)) + x;
                const Color& color = framebuffer[y * WINDOW_WIDTH + x];
                texturePixels32[index] = SDL_MapRGBA(mappingFormat, color.r, color.g, color.b, 255);
            }
        }

        SDL_UnlockTexture(texture);
        SDL_Rect textureRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
        SDL_RenderCopy(renderer, texture, NULL, &textureRect);
        SDL_DestroyTexture(texture);

        SDL_RenderPresent(renderer);
    }

};
