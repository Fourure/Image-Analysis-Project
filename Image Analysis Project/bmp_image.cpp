//
//  bmp_image.cpp
//  Image Analysis Project
//
//  Created by Fourure Damien on 10/04/13.
//  Copyright (c) 2013 Fourure Damien, Kong Win Chang Bryan, Tavernier Rémi. All rights reserved.
//
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "bmp_image.h"

BMP_Image::BMP_Image(const int width, const int height): width(width), height(height){
    picture = new pixel*[width];
    
    for (int i=0; i<width ; ++i) {
        picture[i] = new pixel[height];
    }
}

BMP_Image::~BMP_Image(){
    for (int i=0; i<width ; ++i) {
        delete [] picture[i];
    }
    
    delete [] picture;
}

pixel& BMP_Image::operator() (const int x,const int y){
    return picture[x][y];
}

pixel BMP_Image::operator() (const int x,const int y) const{
    return picture[x][y];
}

void BMP_Image::setColor(pixel& color){
    for (int x=0; x<width; ++x) {
        for (int y=0; y<height; ++y) {
            picture[x][y] = color;
        }
    }
}

void BMP_Image::randomFill(){
    srand((unsigned int)time(NULL));
    
    for (int x=0; x<width; ++x) {
        for (int y=0; y<height; ++y) {
            for (int c=0; c<4; ++c) {
                picture[x][y][c] = rand()%256;
            }
        }
    }
}

void BMP_Image::save(std::string& fileName){
    
    fileName += ".ppm";
    
    FILE *f = std::fopen(fileName.c_str(), "w");
    
    fprintf(f, "P3\n%d %d\n%d\n", width, height, 255);
    for (int x=0; x<width; ++x)
    {
        for (int y=0; y<height ; ++y) {
            fprintf(f, "%d %d %d ", picture[x][y][0],picture[x][y][1],picture[x][y][2]);
        }
    }
    fclose(f);
    
    printf("%s save\n",fileName.c_str());
}
