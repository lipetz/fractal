/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ZoomList.cpp
 * Author: dlipetz
 * 
 * Created on December 21, 2016, 3:54 PM
 */

#include "ZoomList.h"
#include <utility>
//#include <iostream>
using namespace std;

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height) {
}

void ZoomList::add(const Zoom & zoom){
    m_zooms.push_back(zoom);
    
    m_xCenter += (zoom.x - m_width/2) * m_scale   ;
    m_yCenter += (zoom.y - m_height/2) * m_scale  ;
    
    m_scale *= zoom.scale;
    
    //cout << m_xCenter << ", " << m_yCenter << ", " << m_scale << endl;
}

std::pair<double, double> ZoomList::doZoom(int x, int y){
    double xFractal = (x - m_width/2)* m_scale + m_xCenter;
    double yFractal = (y - m_height/2)* m_scale + m_yCenter;
    return std::pair<double, double> (xFractal,yFractal);
}
