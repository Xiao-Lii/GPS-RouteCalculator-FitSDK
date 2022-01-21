# Garmin Fit: GPS Route Distance Calculator
The FIT protocols were written and provided by Garmin found under the cpp folder, anything outside this folder was developed by me. My program can:
1. Take an N-list number of GPS coordinates and return the total distance in meters - accounting for Earth's spherical shape and the changes in longitude according to the meridian. 
   1. A static list of latitude and longitude coordinates in semicircles.
2. Decode a FIT file - Incorporate Garmin's functions for decoding a FIT file - The data protocol that stores user profiles, activity data, workouts, etc.  
3. Creates a listener that reads an N-list number of coordinates from within the FIT file and returns the total distance of a route in meters

### Reasoning / Notes:
- Formulas that provide more accuracy in terms of calculating distance:
  - <b>Vincenty Formula</b>: Extremely accurate in calculating distances, but computationally intensive = slow & higher battery drainage
  - <b>Haversine / Great Circle Distance formula</b>: Very accurate in calculating distances, not as intensive = better runtime & less battery drainage than Vincenty, but overkill/unnecessary for coordinates over short distances
- Semicircles are an efficient way to represent coordinates with a high precision using 32 bits. 
  - A signed 32bit integer has a range of -2,147,483,648 to 2,147,483,648 or <b>4,294,967,295</b> total values. 
  - Divide that by the circumference of the earth in meters and you get ~107 semicircles per meter. That is 1 centimeter resolution anywhere on the planet. 
  - A float32 would not be as precise. A float64 (aka double) is twice the storage amount, and some microprocessors might not support them.

