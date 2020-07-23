//
// Created by andym on 7/9/2020.
//

#include "photo.h"
#include <string>
#include<stdio.h>
#include <sstream>
#include <ctime>
#include <iostream>

using namespace std;

void photo::setDateTime(string date, string time) {

    struct tm timeStruct;
    stringstream ss(date);

    int year = 0;
    ss >> year;
    year -= 1900;

    timeStruct.tm_year = year;
    int month = 0;
    ss >> month;
    month -= 1;

    timeStruct.tm_mon = month;
    ss >> timeStruct.tm_mday;


    ss.str("");
    stringstream s(time);

    int hour = 0;
    int minute = 0;
    int second = 0;

    s >> hour;
    timeStruct.tm_hour = hour;


    s >> minute ;


    timeStruct.tm_min = minute;


    s >> timeStruct.tm_sec;

    dateTime = mktime(&timeStruct);
}
