/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bitmap.h
 * Author: dlipetz
 *
 * Created on December 21, 2016, 8:09 AM
 */

#ifndef BITMAP_H
#define BITMAP_H
#include <string>
#include <cstdint>
#include<memory>
using namespace std;

class Bitmap {
public:
    Bitmap(){}
    Bitmap(int width, int height);
    Bitmap(const Bitmap& orig);
    virtual ~Bitmap();
    bool write(string filename); //returns bool for error if file problem.
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr};//chunk of memory for the 
};

#endif /* BITMAP_H */

