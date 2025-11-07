#include <IL/ilu.h>
#include <IL/ilut.h>

#include <cstring>
#include <iostream>

int main(int argc, const char** argv) {
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " img1.jpg img2.jpg" << std::endl;
        return -1;
    }

    ilInit();
    iluInit();
    std::cout << "Image Library Initialized" << std::endl;

    // Handle first image
    ILuint imageID1;
    ilGenImages(1, &imageID1);
    ilBindImage(imageID1);
    if(!ilLoadImage(argv[1])) {
        std::cerr << "Error: Failed to open the first image!" << std::endl;
        return -1;
    }

    // Get first image properties
    ILuint width1 = ilGetInteger(IL_IMAGE_WIDTH);
    ILuint height1 = ilGetInteger(IL_IMAGE_HEIGHT);
    ILuint bpp1 = ilGetInteger(IL_IMAGE_BPP);
    ILubyte* firstImage = ilGetData();

    // Handle second image
    ILuint imageID2;
    ilGenImages(1, &imageID2);
    ilBindImage(imageID2);
    if(!ilLoadImage(argv[2])) {
        ilDeleteImages(1, &imageID1);
        std::cerr << "Error: Failed to open the second image!" << std::endl;
        return -1;
    }

    // Get second image properties
    ILuint width2 = ilGetInteger(IL_IMAGE_WIDTH);
    ILuint height2 = ilGetInteger(IL_IMAGE_HEIGHT);
    ILuint bpp2 = ilGetInteger(IL_IMAGE_BPP);
    ILubyte* secondImage = ilGetData();

    // Check if images have the same dimensions and format
    if(width1 != width2 || height1 != height2 || bpp1 != bpp2) {
        std::cout << "Images have different dimensions or formats!"
                  << std::endl;
        std::cout << "Image 1: " << width1 << "x" << height1 << " (" << bpp1
                  << " bytes per pixel)" << std::endl;
        std::cout << "Image 2: " << width2 << "x" << height2 << " (" << bpp2
                  << " bytes per pixel)" << std::endl;
        ilDeleteImages(1, &imageID1);
        ilDeleteImages(1, &imageID2);
        return -1;
    }

    ILuint size = width1 * height1 * bpp1;
    if(memcmp(firstImage, secondImage, size) == 0) {
        std::cout << "The images are identical!" << std::endl;
    } else {
        std::cout << "The images are different!" << std::endl;
        // Count different pixels
        ILuint diffCount = 0;
        for(ILuint i = 0; i < size; i += bpp1) {
            bool pixelDiff = false;
            for(ILuint j = 0; j < bpp1; j++) {
                if(firstImage[i + j] != secondImage[i + j]) {
                    pixelDiff = true;
                    break;
                }
            }
            if(pixelDiff) diffCount++;
        }
        std::cout << "Number of different pixels: " << diffCount << std::endl;
    }

    // Clean up
    ilDeleteImages(1, &imageID1);
    ilDeleteImages(1, &imageID2);

    return 0;
}