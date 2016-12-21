/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BitmapInfoHeader.h
 * Author: dlipetz
 *
 * Created on December 20, 2016, 7:26 PM
 * This has the information needed for the Bitmap File header
 * int32 is 4B, the total size is 40B of the struct/header
 */

#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H
#include <cstdint>

using namespace std;

#pragma pack(push,2)

struct BitmapInfoHeader {
	int32_t headerSize{40};
	int32_t width;
	int32_t height;
	int16_t planes{1};
	int16_t bitsPerPixel{24};
	int32_t compression{0};
	int32_t dataSize{0};
	int32_t horizontalResolution{2400};
	int32_t verticalResolution{2400};
	int32_t colors{0};
	int32_t importantColors{0};
};
#pragma pack(pop)


#endif /* BITMAPINFOHEADER_H */

