/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mandelbrot.h
 * Author: dlipetz
 *
 * Created on December 21, 2016, 9:29 AM
 */

#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 1000; //could be 1000, just an arbitrary limit
public:
    Mandelbrot();
    Mandelbrot(const Mandelbrot& orig);
    virtual ~Mandelbrot();


    static int getIterations(double x, double y);

private:


};

#endif /* MANDELBROT_H */

