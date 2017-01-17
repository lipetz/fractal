/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fractalCreator.cpp
 * Author: dlipetz
 * 
 * Created on January 6, 2017, 1:59 PM
 */

#include "FractalCreator.h"
#include <iostream>
#include <memory>
#include <math.h>
#include "ZoomList.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
using namespace std;

FractalCreator::FractalCreator(const FractalCreator& orig) {
}

FractalCreator::~FractalCreator() {
}

FractalCreator::FractalCreator(int width, int height) :
m_width(width), m_height(height),
m_histogram(new int[Mandelbrot::MAX_ITERATIONS ]() /*initialize all to 0*/),
m_fractal(new int[m_width * m_height]() /*initialize all to 0*/),
m_bitmap(m_width, m_height),
m_zoomList(m_width, m_height),
m_totalIterations(0){
    m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}

void FractalCreator::calculateIterations() {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            //bitmap.setPixel(x, y, 255, 255, 0);
            //Need same scaling factor, so make div by HEIGHT for both.
            //+ or - shifts the direction.  Multiplying stretches
            pair<double, double> coords = m_zoomList.doZoom(x, y);
            int iterations = Mandelbrot::getIterations(coords.first, coords.second);

            m_fractal[(y * m_width) + x] = iterations; //stores the numbers of iterations per pixel.
            if (iterations != Mandelbrot::MAX_ITERATIONS)
                m_histogram[iterations]++;
        }
    }
}
void FractalCreator::calculateTotalIterations(){
    m_totalIterations = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        m_totalIterations += m_histogram[i];
    }
}
void FractalCreator::drawFractal() {

    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            int iterations = m_fractal[(y * m_width) + x];
            //uint8_t color = (uint8_t) (256 * (double) iterations / Mandelbrot::MAX_ITERATIONS);

            double hue = 0.0;
            for (int i = 0; i <= iterations; i++) {
                hue += ((double) m_histogram[i]) / m_totalIterations;
            }

            uint8_t red = 0;
            //uint8_t green = pow(255, hue);
            uint8_t green = hue * 255;
            uint8_t blue = 0;

            m_bitmap.setPixel(x, y, red, green, blue);


        }
    }
}

void FractalCreator::writeBitmap(std::string name) {
    m_bitmap.write(name);
}

void FractalCreator::addZoom(const Zoom & zoom) {
    m_zoomList.add(zoom);
}

