//
// Created by andym on 7/9/2020.
//

#ifndef RTREETEMPLATE_GALLERY_H
#define RTREETEMPLATE_GALLERY_H

#include "photo.h"
#include <array>
#include <iostream>
#include <fstream>
#include <vector>

class gallery {
public:
    vector<photo*> gal;

    gallery(){
        ifstream in;
        in.open("GoldenData.txt");

        for(int i = 0; i<1000; i++){
            vector<string> arr;
            for(int j = 0; j < 8; j++){
                string temp = "";
                getline(in, temp);
                arr.push_back(temp);
            }
            photo *pic = new photo(arr);
            gal.push_back(pic);
            string blankLine = "";
            getline(in, blankLine);


        }
        in.close();
    }
    bool MySearchCallback(int id, void* arg)
    {
        printf("Hit data rect %d\n", id);
        return true; // keep going
    }




    void toString();
    void putInRtree();
};


#endif //RTREETEMPLATE_GALLERY_H
