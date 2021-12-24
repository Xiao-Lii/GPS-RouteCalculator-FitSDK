/* GPS Route Distance Calculator - 24.9 meters 

Part 1 Requirements/Assumptions:
- Can be done in any language
- GPS Coordinates are provide in semicircles
- Semicircles can be converted to degrees, radians, or left as semicircles
- Implement an algorithm that calcs the total distance in meters of a route
- Explain thought process and why
*/

// 180° == πradians == 0x80000000 32 bit semicircles
const PI_RADIANS = 0x80000000;

// Semicircles per meter at the equator 
const SC_PER_METER = 107.173;

// Sample GPS Coordinates in semicircles
var coordinates = [
    {lat:476914587, lon:-1254520202},
    {lat:476914647, lon:-1254520081},
    {lat:476914726, lon:-1254519979},
    {lat:476914862, lon:-1254529795},
    {lat:476915068, lon:-1254529544},
    {lat:476915367, lon:-1254529275},
    {lat:476915725, lon:-1254528926},
    {lat:476916045, lon:-1254528539},
    {lat:476916311, lon:-1254528154},
    {lat:476916484, lon:-1254527787},
];

// Helper Functions
function semicirclesToRadians(semicircles){
    return (semicircles * Math.PI) / PI_RADIANS;
}

function semicirclesToDegrees(semicircles){
    return semicircles * (180 / PI_RADIANS);
}