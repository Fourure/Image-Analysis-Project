//
//  bmp_image.h
//  Image Analysis Project
//
//  Created by Fourure Damien on 10/04/13.
//  Copyright (c) 2013 Fourure Damien, Kong Win Chang Bryan, Tavernier Rémi. All rights reserved.
//

#ifndef __Image_Analysis_Project__bmp_image__
#define __Image_Analysis_Project__bmp_image__

#include <iostream>

#include "pixel.h"

class BMP_Image {
protected:
    int width;
    int height;
    pixel** picture;
    
public:
    BMP_Image(const int width, const int height);
    BMP_Image(const std::string& imageFileName);
    ~BMP_Image();
    
    pixel& operator() (const int x,const int y);
    pixel operator() (const int x,const int y) const;
    
    void setColor(pixel& color);
    void randomFill();
    
    void save(std::string& fileName);
};

#endif /* defined(__Image_Analysis_Project__bmp_image__) */
