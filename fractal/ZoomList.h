/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ZoomList.h
 * Author: dlipetz
 *
 * Created on December 21, 2016, 3:54 PM
 */

#ifndef ZOOMLIST_H
#define ZOOMLIST_H
#include <vector>
#include <utility>
#include "Zoom.h"

class ZoomList {
public:
    ZoomList(int width, int height);
    void add(const Zoom & zoom);
    std::pair<double, double> doZoom(int x, int y);
private:
    double m_xCenter{0.0};
    double m_yCenter{0.0};
    double m_scale{1.0};
    
    int m_width{0};
    int m_height{0};
    std::vector<Zoom> m_zooms;

};

#endif /* ZOOMLIST_H */

