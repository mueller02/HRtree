//
// Created by andym on 7/9/2020.
//

#ifndef RTREETEMPLATE_PHOTO_H
#define RTREETEMPLATE_PHOTO_H
#include <string>
#include<stdio.h>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

class photo{
public:

    int photo_id;
    string photo_filepath;
    bool outside;
    long nodeID;
    double Longitude;
    double Latitude;
    double xcord;
    double ycord;
    time_t dateTime;

public:
    void setDateTime(string date, string time);

    photo(vector<string> data){
        photo_id = stoi(data[0]);
        photo_filepath = data[1];
        data[2] == "false" ? outside = false : outside=true;
        nodeID = stoll(data[3]);
        Longitude = stod(data[4]);
        Latitude = stod(data[5]);
        double LAT = (Latitude*3.14159)/180;
        double LON = (Longitude*3.14159)/180;
        xcord = 6371*sin(LAT)*sin(LON);
        ycord = 6371*cos(LAT);
        setDateTime(data[6],data[7]);


    }

};
#endif //RTREETEMPLATE_PHOTO_H
//
// Created by andym on 7/9/2020.
//
