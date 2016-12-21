/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bitmap.cpp
 * Author: dlipetz
 * 
 * Created on December 21, 2016, 8:09 AM
 */

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;

Bitmap::Bitmap(int width, int height)
: m_width(width), m_height(height),
m_pPixels(new uint8_t[width*height * 3]{} /*defaults to 0s*/) //*3 because every width/height needs 3 for the RGB
{

}

Bitmap::Bitmap(const Bitmap& orig) {
}

Bitmap::~Bitmap() {
}

bool Bitmap::write(string filename) {
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof (BitmapFileHeader) +
            sizeof (BitmapInfoHeader) +
            (m_width * m_height * 3); //data = width * height *3
    fileHeader.dataOffset = sizeof (BitmapFileHeader) + sizeof (BitmapInfoHeader);

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    ofstream file;
    file.open(filename.c_str(), ios::out | ios::binary);
    if (!file) { //if can't open it, return false
        return false;
    }

    file.write(reinterpret_cast<char*> (&fileHeader), sizeof (BitmapFileHeader));
    file.write(reinterpret_cast<char*> (&infoHeader), sizeof (BitmapInfoHeader));
    file.write(reinterpret_cast<char*> (m_pPixels.get()), m_width * m_height * 3);
    //the .get() gets the raw pointer that can be casted to something different.


    file.close();
    if (!file) { //check if doesn't exist at end for whatever reason.
        return false;
    }
    return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t *pPixel = m_pPixels.get();
    
    pPixel += (3* y * m_width) + (3* x); //multiply by m_width to move ahead the right amount of bytes.
    
    //The bitmap is in bigendian so backwards.
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

