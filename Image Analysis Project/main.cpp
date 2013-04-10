//
//  main.cpp
//  Image Analysis Project
//
//  Created by Fourure Damien on 10/04/13.
//  Copyright (c) 2013 Fourure Damien, Kong Win Chang Bryan, Tavernier Rémi. All rights reserved.
//

#include <iostream>

#include "bmp_image.h"

int main(int argc, const char * argv[])
{

    BMP_Image image(512,384);
    
    image.randomFill();
    
    
    std::string imageName = "image";
    image.save(imageName);
    return 0;
}

