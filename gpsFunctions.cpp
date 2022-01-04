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
# define EARTH_RADIUS       6378.388                    // Earth's radius in km
# define RADIANS            2147483648                  // Decimal format of PI_RADIANS
# define E_RADIUS_METER     6371000                     // Earth's radius in meters based from NASA's doc sheet
unsigned int PI_RADIANS =   0x80000000;                 // 180° == π*radians == 0x80000000 32 bit semicircles
// 1° = π/180 rad ≈ 0.01745


// Convert Semi-Circle to Radians
long semicirclesToRadians(int semicircles){
    return (semicircles * M_PI) / PI_RADIANS;
}


// Convert Semi-Circle to Degrees
double semicirclesToDegrees(int semicircles){
    return semicircles * (180.0 / PI_RADIANS);
}


// Convert Semi-Circle to Meters at the Equator
double semicirclesToMeters(int semicircles){
    return semicircles / SC_PER_METER;
}

// Need to think about calculating semicircles to meters on a globe perspective
// Long gets closers moving away from the equator - Look at calculating in terms of point of meridian & equator
// The farther north, or south, you are from the equator, the less distance you travel east <-> west for a given degree of longitude. 
// Extra step needed for solution to get a more accurate result.


// Calculates the spherical distance between a set of GPS pts utilizing
// dist = 6378.388 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1))
// and returns the sum in kilometers
int calcRouteDistance(std::vector<std::pair<int,int>> route){
    double c, sum = 0;
    signed long deltaLat, deltaLong, lat1, lat2, m_distance, radDeltaLong;
    int *lat1Ptr, *lat2Ptr, *long1Ptr, *long2Ptr;

    // Chose an iterator so that we could compare the indexes in our vector of pairs
    for (auto itr = route.begin(); itr != route.end(); itr++){

        // An iterator with deltaLat +1 starting index in our starting vector of pairs
        for (auto itr2 = route.begin() + 1; itr2 != route.end(); itr2++){
            if (itr->first == itr2->first){
                auto nextIndex = itr;
                --itr;

                deltaLat = (*nextIndex).first - (*itr).first;        // Delta Lat Value
                deltaLong = (*nextIndex).second - (*itr).second;     // Delta Long Value

                // Trying different ways to dereference the value of the iterator to manipulate
                lat1Ptr = &(*itr).first;
                lat2Ptr = &(*nextIndex).first;
                long1Ptr = &(*itr).second;
                long2Ptr = &(*nextIndex).second;

                // We need to consider point of meridian when moving away from the equator
                // dist = 6378.388 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon2 - lon1))
                lat1 = *lat1Ptr * (M_PI / PI_RADIANS);
                lat2 = *lat2Ptr * (M_PI / PI_RADIANS);
                radDeltaLong = deltaLong * M_PI / PI_RADIANS;

                m_distance = 6378.388 * acos(sin(lat2) * sin(lat1) + cos(lat2) * cos(lat1) * cos(radDeltaLong));
                sum += m_distance;

//                // The simple distance code below works but returns an int, want to test to return a more accurate dec-value (up to the tenths)
//                // Comment out lines 64-77 to see the simple distance calculator run below
//                c = sqrt(pow(deltaLat, 2) + pow(deltaLong, 2));
//                m_distance = c / SC_PER_METER;
//                sum += m_distance;
//                printf("A: %d\t B: %d\t C: %f \n", deltaLat, deltaLong, c);


                printf("A: %d\t B: %d\t SUM: %f \n", deltaLat, deltaLong, sum);
                itr++;
            }
        }
    }
    return sum * 1000.0;
}

// Print All Coordinates in: Lat then Long in semicircles 
void printCoordinates(const std::vector<std::pair<int,int>>& route){
    printf("\nDisplaying all coordinates in list\n");

    for (auto& coordinates : route){
        printf("Lat: %d Long: %d\n", coordinates.first, coordinates.second);
    }
}

// Print All Coordinates in: Lat then Long in degrees
// NEEDS REVIEW: NOT PRINTING BACK THE VALUES I WAS EXPECTING
void printInDegrees(std::vector<std::pair<int,int>>& route){
    printf("\nDisplaying coordinates in degrees...\n");
    double lat, lon;

    for (auto& coordinates : route){
        lat = semicirclesToDegrees(coordinates.first);
        lon = semicirclesToDegrees(coordinates.second);
        printf("Lat: %d Long: %d\n", lat, lon);
    }
}

// Depending on the command line options there are two formats of CSV, and one is a lot easier to work with than the other. 
// The online FIT CSV Tool docs has an example of exactly what you need to do to get the easier to work with CSV format, so read it carefully. 
// But modifying decode.cpp should be easier still.