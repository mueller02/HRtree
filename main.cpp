#include "gallery.h"
#include "rtree.h"
#include "historicalRtree.h"
#include <iostream>
#include <stdio.h>


struct Rect
{
    Rect()  {}

    Rect(double a_minX, double a_minY, double a_maxX, double a_maxY)
    {
        min[0] = a_minX;
        min[1] = a_minY;

        max[0] = a_maxX;
        max[1] = a_maxY;
    }


    double min[2];
    double max[2];
};

struct Rect rects[] =
        {
                Rect(0, 0, 2, 2), // xmin, ymin, xmax, ymax (for 2 dimensional RTree)
                Rect(5, 5, 7, 7),
                Rect(8, 5, 9, 6),
                Rect(7, 1, 9, 2),
        };

int nrects = sizeof(rects) / sizeof(rects[0]);

Rect search_rect(0, 0, INT_MAX, INT_MAX); // search will find above rects that this one overlaps


bool MySearchCallback(int id, void* arg)
{
    printf("Hit data rect %d\n", id);
    return true; // keep going
}


void main()
{
    gallery allImages;
    clock_t start, end;

    RTree<photo*, double, 2, float> tree1;
    //historicalRtree HRTree;
/*
    for(photo* img : allImages.gal){
        start = clock();
        double cord[2];
        cord[0] = img->xcord;
        cord[1] = img ->ycord;
        tree1.Insert(cord, cord, img);
        end = clock();
        double total = (double)(end - start) / CLOCKS_PER_SEC;
        printf("insert time: %le", total);
        cout << endl;
    }
    for(photo* img : allImages.gal){
        start = clock();
        double cord[2];
        cord[0] = img->xcord;
        cord[1] = img ->ycord;
        tree1.Insert(cord, cord, img);
        end = clock();
        double total = (double)(end - start) / CLOCKS_PER_SEC;
        printf("insert time2: %le", total);
        cout << endl;
    }


    int nhits;
    nhits = tree1.Search(search_rect.min, search_rect.max,
                         reinterpret_cast<bool (*)(photo *, void *)>(MySearchCallback), NULL);
    end = clock();
    double total = (double)(end - start) / CLOCKS_PER_SEC;
    printf("sort time: %le", total);
    //cout << HRTree.Search(allImages.gal[rand() % allImages.gal.size()]);
*/
    ////INSERT AT CURRENT TIME



    int index = 0;
    historicalRtree HRTree;
    for(photo* img:allImages.gal){
        start = clock();
        cout << "  ";
        HRTree.insertCurrent(img);
        end = clock();
        cout << " ";
        double total = (double)(end - start) / CLOCKS_PER_SEC;
        if(index % 10 == 0){
            printf("%le", total);
            cout <<"\n";
        }
        index++;
    }
/*
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
    vector<RTree<photo*, double, 2, float>> HRTree= {tree1,tree2,tree3,tree4,tree5,tree6,tree7,tree8,tree9,tree10,tree11,tree12,tree13,tree14,tree15,tree16,tree17};

    double cord[2];
    cord[0] = allImages.gal[0]->xcord;
    cord[1] = allImages.gal[0] ->ycord;
    HRTree[0].Insert(cord, cord, allImages.gal[0]);

    time_t currtime = allImages.gal[0]->dateTime;
    cout << currtime << endl;

    int currentIndex = 0;

    for(int i = 1; i < allImages.gal.size(); i++)
    {
        cout << "i: " << i << endl;
       if(difftime(allImages.gal[i]->dateTime, currtime) < 3600){
           double cord[2];
            cord[0] = allImages.gal[i]->xcord;
            cord[1] = allImages.gal[i] ->ycord;
            HRTree[currentIndex].Insert(cord, cord, allImages.gal[i]);
       }else{
           cout << "else" << i << endl;

           currtime +=3600;
           currentIndex++;


           //RTree<photo*, double, 2, float> temp;
           //tree = temp;
           double cord[2];
           cord[0] = allImages.gal[0]->xcord;
           cord[1] = allImages.gal[0] ->ycord;
           HRTree[currentIndex].Insert(cord, cord, allImages.gal[i]);

           //HRTree.push_back(tree);
       }
         // Note, all values including zero are fine in this version
        //printf("true/false: %d", tree.IsNull(iter));
    }

    //int nhits = tree.Search(search_rect.min, search_rect.max, MySearchCallback, NULL);

    //printf("Search resulted in %d hits\n", nhits);
    cout << "noo";
    // Iterator test
    int itIndex = 0;
    RTree<photo*, double, 2, float>::Iterator it;
    for( HRTree[0].GetFirst(it);
         !HRTree[0].IsNull(it);
         HRTree[0].GetNext(it) )
    {
        photo* value = HRTree[0].GetAt(it);

        double boundsMin[2] = {0,0};
        double boundsMax[2] = {0,0};
        it.GetBounds(boundsMin, boundsMax);
        printf("it[%d] %d = (%d,%d,%d,%d)\n", itIndex++, value, boundsMin[0], boundsMin[1], boundsMax[0], boundsMax[1]);
    }

    // Iterator test, alternate syntax
    itIndex = 0;
    HRTree[0].GetFirst(it);
    while( !it.IsNull() )
    {
        photo* value = *it;
        ++it;
        printf("it[%d] %d\n", itIndex++, value);
    }

    getchar(); // Wait for keypress on exit so we can read console output

    // Output:
    //
    // nrects = 4
    // Hit data rect 1
    // Hit data rect 2
    // Search resulted in 2 hits
    // it[0] 0 = (0,0,2,2)
    // it[1] 1 = (5,5,7,7)
    // it[2] 2 = (8,5,9,6)
    // it[3] 3 = (7,1,9,2)
    // it[0] 0
    // it[1] 1
    // it[2] 2
    // it[3] 3
*/
}