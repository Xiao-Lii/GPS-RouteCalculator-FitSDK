#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdio>

// #include "cpp/fit_decode.hpp"
// #include "cpp/fit_mesg_broadcaster.hpp"
// #include "cpp/fit_developer_field_description.hpp"

# define SC_PER_METER       107.173                     // Semicircles per meter at the equator
# define M_PI               3.14159265358979323846      // Pi decimal format
# define E_RADIUS_METER     6371000                     // Earth's radius in meters based from NASA's doc sheet 
unsigned int PI_RADIANS =   0x80000000;                 // 180° == πradians == 0x80000000 32 bit semicircles


// Convert Semi-Circle to Radians
double semicirclesToRadians(int semicircles){
    return ((semicircles * M_PI) / PI_RADIANS);
}


// Convert Semi-Circle to Degrees
double semicirclesToDegrees(int semicircles){
    return semicircles * (180.0 / PI_RADIANS);
}


// Convert Semi-Circle to Meters at the Equator
double semicirclesToMeters(int semicircles){
    return semicircles * (180.0 / PI_RADIANS);
}

// Need to think about calculating semicircles to meters on a globe persepctive 
// Long gets closers moving away from the equator - Look at calculating in terms of point of meridian & equator
// The farther north, or south, you are from the equator, the less distance you travel east <-> west for a given degree of longitude. 
// Extra step needed for solution to get a more accurate result.


// Calcs the spherical distance between GPS pts utilizing 
// dist = 6378.388 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1))
// and returns the sum in meters 
int calcRouteDistance(std::vector<std::pair<int,int>> route){
    double c, test, testSum = 0;
    signed long deltaLat, deltaLong, lat1, lat2, long1, long2, m;
    int sum = 0;

    // Chose an iterator so that we could compare the indexes in our vector of pairs
    for (auto itr = route.begin(); itr != route.end(); itr++){

        // An iterator with deltaLat +1 starting index in our starting vector of pairs
        for (auto itr2 = route.begin() + 1; itr2 != route.end(); itr2++){
            if (itr->first == itr2->first){
                auto nextIndex = itr;
                --itr;

                lat1 = semicirclesToRadians(itr->first);
                lat2 = semicirclesToRadians(nextIndex->first);
                printf("LAT1: %l LAT2: %l\n", lat1, lat2);

                deltaLat = (*nextIndex).first - (*itr).first;                                       // Delta Lat Value
                deltaLong = (*nextIndex).second - (*itr).second;     // Delta Long Value

                // The Great Distance Formula in Radians
                // D = R(PI/180) * ACOS[SIN(LAT1) * SIN(LAT2) + COS(LAT2) * COS(LAT1) * COS(LAT2-LAT1)]
                test = (E_RADIUS_METER/PI_RADIANS) * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(
                        semicirclesToRadians(deltaLong)));
                testSum += test;
//                a = (pow(sin(deltaLat/2), 2));

                // We need to consider point of meridian when moving away from the equator
                c = sqrt(pow(deltaLat, 2) + pow(deltaLong, 2));
                m = c / SC_PER_METER;
                sum += m;

                // Need to double check math and iteration, math doesn't seem right
                // Getting deltaLat total distance of 118 meters but I'm sure I missed something
                printf("A: %d\t B: %d\t C: %f \tM: %f\n", deltaLat, deltaLong, c, m);
                itr++;
            }
        }
    }
    printf("TEST SUM: %d\n", testSum);
    return sum;
}

// Print All Coordinates in: Lat then Long in semicircles 
void printCoordinates(const std::vector<std::pair<int,int>>& route){
    for (auto& coordinates : route){
        printf("Lat: %d Long: %d\n", coordinates.first, coordinates.second);
    }
}

// Depending on the command line options there are two formats of CSV, and one is a lot easier to work with than the other. 
// The online FIT CSV Tool docs has an example of exactly what you need to do to get the easier to work with CSV format, so read it carefully. 
// But modifying decode.cpp should be easier still.