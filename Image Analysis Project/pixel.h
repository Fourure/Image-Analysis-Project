//
//  pixel.h
//  Image Analysis Project
//
//  Created by Fourure Damien on 10/04/13.
//  Copyright (c) 2013 Fourure Damien, Kong Win Chang Bryan, Tavernier Rémi. All rights reserved.
//

#ifndef Image_Analysis_Project_pixel_h
#define Image_Analysis_Project_pixel_h

struct pixel {
    int R;
    int G;
    int B;
    int Alpha;
    
    int& operator[] (int i) {
        switch(i) {
            case 0:
                return R;
                break;
                
            case 1:
                return G;
                break;
                
            case 2:
                return B;
                break;
                
            case 3:
            default:
                return Alpha;
                break;
        }
    }
};

#endif
