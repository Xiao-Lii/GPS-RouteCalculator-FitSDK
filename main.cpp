#include "gpsFunctions.cpp"
#include "listener.cpp"
#include "fit_decode.hpp"
#include "fit_mesg_broadcaster.hpp"
#include "fit_developer_field_description.hpp"

/*
 * || ------- THOUGHT PROCESS FOR PART 2: ------- ||
Use the FIT SDK to decode the GPS coordinates from a FIT Activity File

------- Part 2 Requirements/Assumptions: -------
- The file is in FIT format
- Utilizing the pre-established libraries, read the coordinates as an input to the algorithm designed in part one
- Include a short write-up on how I solved the problem
- Download the FIT SDK file: https://developer.garmin.com/fit/overview/

------- Problem-Solving Process & Goals: -------
- Compile the decode example files provided
    - Need: A listener object that inherits FileIdMesgListener, DeveloperFieldDescriptionListener, RecordMesgListener
    - Error Handling for missing values to ignore and look at Field 8 & Value 8, assuming these are FileIDs
- Ensure compiler is running properly (had issues with this - Windows SDK 10 not installed, outdated VS files, etc.)
- Refer to documentation about utilizing the FIT_SDK:
- Refer to the Actvity.csv format in the example folder

|| ------- ADDITIONAL THOUGHTS/NOTES FOR PART 2: ------- ||
- GPS data will be stored in the RecordMessage
- Review Online SDK Tool to
  */

int main(int argc, char* argv[]){
    // PART 2 VARIABLES
//    fit::Decode decode;
//    // decode.SkipHeader();       // Use on streams with no header and footer (stream contains FIT defn and data messages only)
//    // decode.IncompleteStream(); // This suppresses exceptions with unexpected eof (also incorrect crc)
//    fit::MesgBroadcaster mesgBroadcaster;
//    Listener listener;
//    std::fstream file;

    // Sample GPS Coordinates in semicircles
    std::vector<std::pair<int, int>> route = {
        {476914587, -1254520202},
        {476914647, -1254520081},
        {476914726, -1254519979},
        {476914862, -1254519795},
        {476915068, -1254519544},
        {476915367, -1254519275},
        {476915725, -1254518926},
        {476916045, -1254518539},
        {476916311, -1254518154},
        {476916484, -1254517787},
    };

    printCoordinates(route);
    printf("\nTotal Distance: %.2f",calcRouteDistance(route));
//    printInDegrees(route);

    // PART 2 IMPLEMENTATION - TESTING
//    printf("FIT Decode Example Application\n");
//
//    if (argc != 2)
//    {
//        printf("Usage: decode.exe <filename>\n");
//        return -1;
//    }
//
//    file.open(argv[1], std::ios::in | std::ios::binary);
//
//    if (!file.is_open())
//    {
//        printf("Error opening file %s\n", argv[1]);
//        return -1;
//    }
//
//    if (!decode.CheckIntegrity(file))
//    {
//        printf("FIT file integrity failed.\nAttempting to decode...\n");
//    }
//
//    mesgBroadcaster.AddListener((fit::RecordMesgListener&)listener);
//    mesgBroadcaster.AddListener((fit::MesgListener &)listener);
//
//    try
//    {
//        decode.Read(&file, &mesgBroadcaster, &mesgBroadcaster, &listener);
//    }
//    catch (const fit::RuntimeException& e)
//    {
//        printf("Exception decoding file: %s\n", e.what());
//        return -1;
//    }
//
//    printf("Decoded FIT file %s.\n", argv[1]);
}