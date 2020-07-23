//
// Created by andym on 7/10/2020.
//

#ifndef RTREE_HISTORICALRTREE_H
#define RTREE_HISTORICALRTREE_H

#include "photo.h"
#include "RTree.h"
#include "gallery.h"
#include "time.h"




class historicalRtree{
public:
//    vector<nodeOfHRTree> HRtree;
    vector<RTree<photo*, double, 2, float>> HRTree;
    int timeWindowSize = 3600; //inseconds
    int timeStart = 1592373600;
    int currentIndex;
    int currentTime;

    historicalRtree(){
        RTree<photo*, double, 2, float> tree1;
        RTree<photo*, double, 2, float> tree2;
        RTree<photo*, double, 2, float> tree3;
        RTree<photo*, double, 2, float> tree4;
        RTree<photo*, double, 2, float> tree5;
        RTree<photo*, double, 2, float> tree6;
        RTree<photo*, double, 2, float> tree7;
        RTree<photo*, double, 2, float> tree8;
        RTree<photo*, double, 2, float> tree9;
        RTree<photo*, double, 2, float> tree10;
        RTree<photo*, double, 2, float> tree11;
        RTree<photo*, double, 2, float> tree12;
        RTree<photo*, double, 2, float> tree13;
        RTree<photo*, double, 2, float> tree14;
        RTree<photo*, double, 2, float> tree15;
        RTree<photo*, double, 2, float> tree16;
        RTree<photo*, double, 2, float> tree17;
        HRTree= {tree1,tree2,tree3,tree4,tree5,tree6,tree7,tree8,tree9,tree10,tree11,tree12,tree13,tree14,tree15,tree16,tree17};
        currentTime = timeStart;
        currentIndex = 0;
    }

    void populate(gallery g);
    void insertCurrent(photo* pic);
    int Search(photo* target);
    bool callback(int id, void* arg)
    {
        printf("Hit data rect %d\n", id);
        return true; // keep going
    }


};
#endif //RTREE_HISTORICALRTREE_H
