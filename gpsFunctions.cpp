#include <fstream>
#include <iostream>
#include <utility>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <iterator>


// #include "cpp/fit_decode.hpp"
// #include "cpp/fit_mesg_broadcaster.hpp"
// #include "cpp/fit_developer_field_description.hpp"

# define SC_PER_METER    107.173;                   // Semicircles per meter at the equator
# define M_PI           3.14159265358979323846      // Pi decimal format

// 180° == πradians == 0x80000000 32 bit semicircles
unsigned int PI_RADIANS = 0x80000000;


// Convert Semi-Circle to Radians
double semicirclesToRadians(int semicircles){
    return ((semicircles * M_PI) / PI_RADIANS);
}


// Convert Semi-Circle to Degrees
double semicirclesToDegrees(int semicircles){
    return semicircles * (180 / PI_RADIANS);
}


// Convert Semi-Circle to Meters at the Equator
double semicirclesToMeters(int semicircles){
    return semicircles * (180 / PI_RADIANS);
}


// Calcs distance between GPS pts then provides total route distance in meters
int calcRouteDistance(std::vector<std::pair<int,int>> route){
    double sum = 0;
    int a, b;
    double c, m;

    // Chose an iterator so that we could compare the indexes in our vector of pairs
    for (auto itr = route.begin(); itr != route.end(); itr++){
        //printf("Lat: %d Long: %d\n", itr->first, itr->second);

        // An iterator with a +1 index in our starting vector of pairs
        for (auto itr2 = route.begin() + 1; itr2 != route.end(); itr2++){
            if (itr->first == itr2->first){
                auto nextIndex = itr;
                --itr;
                a = abs((*nextIndex).first) - (*itr).first;
                b = abs((*nextIndex).second) - abs((*itr).second);
                c = sqrt(pow(abs(a), 2) + pow(abs(b),2)); 
                m = c / SC_PER_METER;
                sum += m;

                // Need to double check math and iteration, math doesn't seem right
                // Getting a total distance of 118 meters but I'm sure I missed something 
                printf("A: %d B: %d C: %d M: %d\n", a, b, c, m);
                itr++;
            }
        }
    }
    return sum;
}


// Print All Coordinates in: Lat then Long in semicircles 
void printCoordinates(std::vector<std::pair<int,int>> route){
    for (auto& coordinates : route){
        printf("Lat: %d Long: %d\n", coordinates.first, coordinates.second);
    }
}