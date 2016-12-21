/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Zoom.h
 * Author: dlipetz
 *
 * Created on December 21, 2016, 3:50 PM
 */

#ifndef ZOOM_H
#define ZOOM_H

struct Zoom {
    int x{0};
    int y{0};
    double scale{0.0};
    Zoom(int x, int y , double scale): x(x), y(y), scale(scale){}
    
   

};

#endif /* ZOOM_H */

