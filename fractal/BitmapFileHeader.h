/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BitmapFileHeader.h
 * Author: dlipetz
 *
 * Created on December 20, 2016, 7:28 PM
 * This is the file header for all bitmaps.
 * Need to start with 2 characters B and M, then the filesize to be set later and then reseved and then an offset to be set later.
 */

#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>

using namespace std;

#pragma pack(push, 2)
struct BitmapFileHeader {
	char header[2] { 'B', 'M' };
	int32_t fileSize;
	int32_t reserved { 0 };
	int32_t dataOffset;
};
#pragma pack(pop)
#endif /* BITMAPFILEHEADER_H */

