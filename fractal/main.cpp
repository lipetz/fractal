/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dlipetz
 *
 * Created on December 20, 2016, 7:22 PM
 */

#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <memory>
#include <math.h>
//#include <fstream>
//#include "BitmapFileHeader.h" //took out, included in Bitmap.h
//#include "BitmapInfoHeader.h"

#include "FractalCreator.h"

using namespace std;

int main(int argc, char** argv) {

    cout << "Hello World!\n";

    int height = 600;

    FractalCreator fractalCreator(800, 600);
    fractalCreator.addZoom(Zoom(295, height - 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.calculateIterations();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap("test.bmp");

    cout << "finished" << endl;
    return 0;
}

