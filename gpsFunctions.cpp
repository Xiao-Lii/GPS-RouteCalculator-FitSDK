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
# define EARTH_RADIUS_M     6371000                     // Earth's radius in meters based from NASA's doc sheet
# define DEG_TO_RADIAN_CONV     0.01745                     // Decimal format 1° = π/180 rad ≈ 0.01745
unsigned int PI_RADIANS =   0x80000000;                 // 180° == π*radians == 0x80000000 32 bit semicircles



// Convert Semi-Circle to Radians
double semicirclesToRadians(int semicircles){
    return semicircles * (M_PI / PI_RADIANS);
}


// Convert Semi-Circle to Degrees
double semicirclesToDegrees(int semicircles){
    return semicircles * (180.0 / PI_RADIANS);
}


// Convert Semi-Circle to Meters at the Equator
double semicirclesToMeters(int semicircles){
    return semicircles / SC_PER_METER;
}


// Calculates the spherical distance between a set of GPS pts and returns the sum in m
double calcRouteDistance(std::vector<std::pair<int,int>> route){
    double c, sum = 0;
    double deltaLat, deltaLong, dx, lat, m_distance;

    // Iterate to compare pairs of coordinates
    for (auto itr = route.begin(); itr != route.end(); itr++){

        // Start at next index of our pairs of coordinates
        for (auto itr2 = route.begin() + 1; itr2 != route.end(); itr2++){
            if (itr->first == itr2->first){
                auto nextIndex = itr;
                --itr;

                deltaLat = (*nextIndex).first - (*itr).first;       // Delta Lat Value
                deltaLong = (*nextIndex).second - (*itr).second;    // Delta Long Value
                lat = (nextIndex->first + itr->first) / 2;

                // Calc dx(long) according to our latitude value from the meridian
                dx = cos(semicirclesToRadians(lat)) * deltaLong;

                c = sqrt(pow(deltaLat, 2) + pow(dx, 2));
                m_distance = c / SC_PER_METER;
                sum += m_distance;

//                printf(" LAT: %.f\t LONG: %.f\t DIST: %.2f\t SUM: %.2f \n", deltaLat, deltaLong, m_distance, sum);
                itr++;
            }
        }
    }
    return sum;
}

// Print All Coordinates in: Lat then Long in semicircles 
void printCoordinates(const std::vector<std::pair<int,int>>& route){
    printf("\nDisplaying all coordinates(semicircles):\n");

    for (auto& coordinates : route){
        printf("Lat: %d\t Long: %d\n", coordinates.first, coordinates.second);
    }
}

// Print All Coordinates in: Lat then Long in degrees
// NEEDS REVIEW: NOT PRINTING BACK THE VALUES I WAS EXPECTING
void printInDegrees(std::vector<std::pair<int,int>>& route){
    printf("\nDisplaying all coordinates(degrees):\n");
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