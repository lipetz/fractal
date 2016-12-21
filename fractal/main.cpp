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
//#include <fstream>
//#include "BitmapFileHeader.h" //took out, included in Bitmap.h
//#include "BitmapInfoHeader.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
using namespace std;

int main(int argc, char** argv) {

    cout << "Hello World!\n";

    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    double min = 99999999;
    double max = -99999999;

    //unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS+1]() /*initialize all to 0*/ ); //Plus 1 because max = 1000, and increment the iterations in the while, so can be max, so need max+1
    unique_ptr<int[] > histogram(new int[Mandelbrot::MAX_ITERATIONS ]() /*initialize all to 0*/); //Take out the +1 because don't want to store the ones that are on the max-iterations  Will check when put in
    unique_ptr<int[] > fractal(new int[WIDTH * HEIGHT]() /*initialize all to 0*/); //Storing info for all pixels


    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            //bitmap.setPixel(x, y, 255, 255, 0);
            //Need same scaling factor, so make div by HEIGHT for both.
            //+ or - shifts the direction.  Multiplying stretches
            //double xFractal = (x - WIDTH/2 - 200) * 2.0/WIDTH ; // we want a range between -1 and +1
            double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
            //double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT ;
            double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            fractal[(y * WIDTH) + x] = iterations; //stores the numbers of iterations per pixel.
            if (iterations != Mandelbrot::MAX_ITERATIONS)
                histogram[iterations]++;
        }
    }

    int totalIterations = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        totalIterations += histogram[i];
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int iterations = fractal[(y * WIDTH) + x];
            //uint8_t color = (uint8_t) (256 * (double) iterations / Mandelbrot::MAX_ITERATIONS);

            double hue = 0.0;
            for (int i = 0; i <= iterations; i++) {
                hue += ((double) histogram[i]) / totalIterations;
            }

            uint8_t red = 0;
            uint8_t green = hue*255;
            uint8_t blue = 0;
            
            bitmap.setPixel(x, y, red, green, blue);

 
        }
    }





    /*
        cout << min << ", " << max << endl;

        int sum = 0;
        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
            sum += histogram[i];
            cout << histogram[i] << " ";
        }
        cout << "\nsum: " << sum << " ; " << WIDTH * HEIGHT << endl;
     */

    bitmap.write("test.bmp");

    cout << "finished" << endl;
    return 0;
}

