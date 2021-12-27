#include <iostream>
#include <cmath>
#include <map>
#include <string>
using namespace std;

/* GPS Route Distance Calculator - 24.9 meters

Part 1 Requirements/Assumptions:
- Language: C++
- Implement an algorithm that calcs the total distance in meters of a route represented by gps coordinates
- Explain thought process to answer and why
- Range of Lat = -90 to 90/Long = -180 to 180 decimal degree format

Functions we'll need:
- Conversions: radians, meters, and semicircles
- Reads a n-list number of coordinates in semi-circles
- Subtract two points to find difference in lat & lon
- Get sum of these distances
- Convert semi-circles to meters
*/

class coordinates{
    int lat;
    int lon;

public:
    coordinates(int lat, int lon) : lat(lat), lon(lon) {}
    int getLat() const {return lat;}
    void setLat(int lat) {coordinates::lat = lat;}
    int getLon() const {return lon;}
    void setLon(int lon) {coordinates::lon = lon;}
};

// 180° == πradians == 0x80000000 32 bit semicircles
int PI_RADIANS = 0x80000000;

// Semicircles per meter at the equator
double SC_PER_METER = 107.173;

// Sample GPS Coordinates in semicircles
//map<string, int, string, int> route = {};
//var route = {
//    {lat:476914587, lon:-1254520202},
//    {lat:476914647, lon:-1254520081},
//    {lat:476914726, lon:-1254519979},
//    {lat:476914862, lon:-1254529795},
//    {lat:476915068, lon:-1254529544},
//    {lat:476915367, lon:-1254529275},
//    {lat:476915725, lon:-1254528926},
//    {lat:476916045, lon:-1254528539},
//    {lat:476916311, lon:-1254528154},
//    {lat:476916484, lon:-1254527787}
//    };

//void createRoute()

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

// Find differences in n-list set of GPS coordinates
//double calcDiff(map<int, int> listCoords){
//    int length = listCoords.length();
//
//}

int main(){
    int lat = 476914587;
    int lon = -1254520202;

    cout << semicirclesToDegrees(lat);
    cout << semicirclesToDegrees(lon);
}