#include "gpsFunctions.cpp"

/*
THOUGHT PROCESS FOR PART 1: 
GPS Route Distance Calculator - 24.9 meters(Hint)

------- Part 1 Requirements/Assumptions: -------
- Implement an algorithm that calcs the total distance in meters of a route represented by gps coordinates
- Range of Lat = -90 to 90/Long = -180 to 180 decimal degree format
------- Functions we'll need: -------
- Conversions: radians, meters, and semicircles
- Reads a n-list number of coordinates in semi-circles
    - Research which algorithm is the most efficient for recursions vs. iterating: https://www.geeksforgeeks.org/difference-between-recursion-and-iteration/
    - Found info about algorithms here: https://docs.microsoft.com/en-us/cpp/standard-library/algorithm?view=msvc-170
    - Found some info about time efficient lambda functions: https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170
    - Learned more about efficient iterator loops through trial & error and comparing run times
        - Using const, for loops, auto, iterators, STL Containers, etc. 
- Subtract two points to find difference in lat & long 
    - Return sum of these distances from an n-list in meters
    - Learn how to utilize a vector of pairs and auto-iterators to access its members

ADDITIONAL THOUGHTS/NOTES FOR PART 1:
- Utilize the haversine formula or Great Distance formula to find exact distance between two points across a sphere
    - Take sum of each pair of pts & that should be our total distance
    - Subtraction of the negatives aren't being processed correctly - bits are overflowing, negatives aren't being handled 
    - 

THOUGHT PROCESS FOR PART 2:
Use the FIT SDK to decode the GPS coordinates from a FIT Activity File

------- Part 2 Requirements/Assumptions: -------
- The file is in FIT format
- Utilizing the pre-established libraries, read the coordinates as an input to the algorithm designed in part one
- Include a short write-up on how I solved the problem
- Download the FIT SDK file: https://developer.garmin.com/fit/overview/

Problem-Solving Process & Goals:
- Compile the decode example files provided
    - Need: A listener object that inherits FileIdMesgListener, DeveloperFieldDescriptionListener, RecordMesgListener
    - Error Handling for missing values to ignore and look at Field 8 & Value 8, assuming these are FileIDs
- Ensure compiler is running properly (had issues with this - Windows SDK 10 not installed, outdated VS files, etc.)
- Refer to documentation about utilizing the FIT_SDK:
- Refer to the Actvity.csv format in the example folder 
*/

int main(int argc, char* argv[]){
    // For part 2 implementation
    // std::fstream file; 

    // Sample GPS Coordinates in semicircles
    std::vector<std::pair<int, int>> route = {
        {476914587, -1254520202},
        {476914647, -1254520081},
        {476914726, -1254519979},
        {476914862, -1254529795},
        {476915068, -1254529544},
        {476915367, -1254529275},
        {476915725, -1254528926},
        {476916045, -1254528539},
        {476916311, -1254528154},
        {476916484, -1254527787},
    };

    printCoordinates(route);
    printf("\nStarting Calculations...\n");
    printf("\nTotal Distance: %d",calcRouteDistance(route));

    // printf("Preparing to read Activity.CSV File\n");
    // file.open(argv[1], std::ios::in | std::ios::binary);

    // if (!file.is_open())
    // {
    //     printf("Error opening files %s\n", argv[1]);
    //     return -1;
    // }
}