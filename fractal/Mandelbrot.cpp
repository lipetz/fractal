/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mandelbrot.cpp
 * Author: dlipetz
 * 
 * Created on December 21, 2016, 9:29 AM
 */
#include <complex>
#include "Mandelbrot.h"

using namespace std;

Mandelbrot::Mandelbrot() {
}

Mandelbrot::Mandelbrot(const Mandelbrot& orig) {
}

Mandelbrot::~Mandelbrot() {
}

int Mandelbrot::getIterations(double x, double y){
    
    complex<double>  z = 0;
    complex<double>  c(x,y); //starting 
    
    int iterations = 0;
    
    while(iterations < MAX_ITERATIONS){
        z = z*z + c;
        
        if(abs(z) > 2 ){ //if exceeds 2, goes to infinity and not in the mandelbrot set
            break;
        }
        iterations++;
    }
    return iterations;
}
