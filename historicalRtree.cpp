//
// Created by andym on 7/10/2020.
//

#include "historicalRtree.h"
#include "photo.h"
#include "gallery.h"

void historicalRtree::populate(gallery g) {
    int save_Index=0;
    double min[2] = {1.0,2.0};
    double max[2] = {1.0,2.0};

        RTree<photo*,double,2,double> tempTree;
        int counter = 0;
        RTree<photo*, double, 2, double>::Iterator it;
        for(photo* p : g.gal){
            cout << counter << " ";
            counter++;
            min[0] = p->xcord;
            min[1] = p->ycord;
            max[0] = p->xcord;
            max[1] = p->ycord;
            tempTree.Insert(min, max, p);
            tempTree.GetFirst(it);
            cout << tempTree.Count() << endl;

        }

        cout << "done" ;

}
/*
int historicalRtree::Search(photo* target) {
    time_t timeWeWant = target->dateTime;
    int index = (timeWeWant-timeStart)/timeWindowSize;
    double cordMin[2], cordMax[2];

    cordMin[0] = 0;
    cordMin[1] = 0;
    cordMax[0] = INT_MAX;
    cordMax[1] = INT_MAX;
    struct Rect rectangle;
    rectangle.
    bool MySearchCallback;
    int found;
    return HRTree[index].Search(cordMin, cordMax, NULL, NULL);
}
*/
void historicalRtree::insertCurrent(photo* pic) {
    //cout << "i: " << i << endl;
    if(difftime(pic->dateTime, currentTime) < 3600){
        double cord[2];
        cord[0] = pic->xcord;
        cord[1] = pic ->ycord;
        HRTree[currentIndex].Insert(cord, cord, pic);
    }else{
       // cout << "else" << endl;

        currentTime +=3600;
        currentIndex++;


        //RTree<photo*, double, 2, float> temp;
        //tree = temp;
        double cord[2];
        cord[0] = pic ->xcord;
        cord[1] = pic ->ycord;
        HRTree[currentIndex].Insert(cord, cord, pic);

        //HRTree.push_back(tree);
    }
    // Note, all values including zero are fine in this version
    //printf("true/false: %d", tree.IsNull(iter));
}

