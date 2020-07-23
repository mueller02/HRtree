//
// Created by andym on 7/10/2020.
//

#include "gallery.h"
#include "rtree.h"

void gallery::toString(){
    for(int i = 0; i < 1000; i++){
        cout << gal[i]->photo_id << " " << gal[i]->photo_filepath << " " << gal[i]->outside << " " << gal[i]->nodeID << " " << gal[i]->Longitude << " " << gal[i]->Latitude;
    }

}

void gallery::putInRtree(){
    RTree<photo*, double, 2, double> myRtree;        //maybe no star on photo
    double min[2];
    double max[2];
    //myRtree.Insert(min, max, gal[0]);

    for(photo* pictures : gal){
        min[0] = pictures->xcord;
        min[1] = pictures->ycord;
        max[0] = pictures->xcord;
        max[1] = pictures->ycord;
        myRtree.Insert(min, max, gal[0]);
        cout << pictures->photo_id << "\n";
    }

}