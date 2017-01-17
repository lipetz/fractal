/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fractalCreator.h
 * Author: dlipetz
 *
 * Created on January 6, 2017, 1:59 PM
 */

#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H
#include <string>
#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;

class FractalCreator {
public:
    FractalCreator(int width, int heigh);
    FractalCreator(const FractalCreator& orig);
    virtual ~FractalCreator();
    
    void calculateIterations();
    void calculateTotalIterations();
    void drawFractal();
    void writeBitmap(string name);
    void addZoom(const Zoom & zoom);
    
private:
    int m_width;
    int m_height;
    ZoomList  m_zoomList;
    unique_ptr<int[] > m_histogram;
    unique_ptr<int[] > m_fractal;
    Bitmap m_bitmap;
    int m_totalIterations;
    

};

#endif /* FRACTALCREATOR_H */

