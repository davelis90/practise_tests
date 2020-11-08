#include <iostream>
#include <cmath>

// Calculate distance of path segment
float distance (float x_start, float y_start, float x_end, float y_end)
{
    return sqrt(pow((x_end - x_start), 2) + pow((y_end - y_start), 2));
}

// float array_distance (float path[][2] , int rows)
// {
//   float total_distance = 0;
  
//   // loop through all the elements and calculate the distance
  
//   for (int i = 0; i < (rows -1); i++)
//   {
//       total_distance += distance(path[i][0], path[i][1], path[i+1][0], path[i+1][1]);
//     //   std::cout << "i = " << i << std::endl;
//   }
  
//   return total_distance;
// }

// Calculate if the path can be completed based on the battery_percentage of the robot and the travelled distance
bool complete_path(float path[][2] , int rows, float battery_percentage)
{
    // It is assumed that the robot needs 1% of its battery to complete a distance of 0.2 m.
    // Here the distance that the robot has enough battery to travel is calculated, based on the above assumption.
    float distance_capacity = 0.2 * battery_percentage * 100;
    
     // Loop through all the 2D points of the path and calculate the distance of each segment. Then subtract each distance from the distance_capacity
    for (int i = 0; i < (rows -1); i++)
    {
        distance_capacity -= distance(path[i][0], path[i][1], path[i+1][0], path[i+1][1]);
        // if the distance_capacity becomes negative, that means the robot is out of battery. Hence it cannot complete the path
        // In that case return 0 (Failure)
        if (distance_capacity < 0) return 0;
    }
    // if the distance can be covered, return 1 (Success)
    return 1;
}

int main()
{

  float path [][2] = {
      {0.00359, -0.0013},   {0.00608, -0.00281},  {0.00756, -0.0027},
      {0.00842, -0.00307},  {0.00849, -0.0037},   {0.00846, -0.00387},
      {0.00829, -0.00379},  {0.0084, -0.00388},   {0.00846, -0.00409},
      {0.0138, -0.00347},   {0.0698, -0.00098},   {0.11151, -0.00745},
      {0.167, -0.01404},    {0.32572, -0.05356},  {0.41797, -0.07953},
      {0.52867, -0.11505},  {0.61002, -0.13945},  {0.63633, -0.14954},
      {0.70933, -0.18835},  {0.7191, -0.19822},   {0.72701, -0.20117},
      {0.731, -0.20424},    {0.73371, -0.20805},  {0.77746, -0.2621},
      {0.86029, -0.34734},  {0.88373, -0.37565},  {0.90413, -0.40655},
      {0.92189, -0.43795},  {0.93867, -0.47125},  {0.95337, -0.50479},
      {0.96615, -0.54003},  {0.97729, -0.57518},  {0.98669, -0.60948},
      {0.9944, -0.64442},   {0.99963, -0.67999},  {1.00244, -0.71709},
      {1.00327, -0.75302},  {0.99907, -0.78939},  {0.99464, -0.8237},
      {0.98722, -0.86223},  {0.97558, -0.90511},  {0.96147, -0.94947},
      {0.94402, -0.99336},  {0.92286, -1.03964},  {0.89779, -1.08594},
      {0.8698, -1.13096},   {0.73009, -1.33175},  {0.59053, -1.5304},
      {0.46166, -1.7128},   {0.30239, -1.93285},  {0.25147, -1.99011},
      {0.19826, -2.04254},  {0.14275, -2.09163},  {0.08663, -2.13425},
      {0.03116, -2.17209},  {-0.0238, -2.20402},  {-0.07864, -2.23286},
      {-0.1318, -2.25636},  {-0.1825, -2.27552},  {-0.23171, -2.29113},
      {-0.27795, -2.30206}, {-0.32673, -2.31054}, {-0.37225, -2.31536},
      {-0.41574, -2.31996}, {-0.45496, -2.32042}, {-0.48902, -2.31757},
      {-0.52496, -2.3164},  {-0.55811, -2.31102}, {-0.77049, -2.25292},
      {-0.99, -2.19669},    {-1.19266, -2.14085}, {-1.23428, -2.12438},
      {-1.27377, -2.10614}, {-1.31327, -2.08351}, {-1.39679, -2.03016},
      {-1.48345, -1.95929}, {-1.52353, -1.91628}, {-1.66757, -1.77012},
      {-1.83468, -1.60606}, {-2.01648, -1.41688}, {-2.18845, -1.20596},
      {-2.35403, -0.99207}, {-2.44666, -0.84068}, {-2.48383, -0.76261},
      {-2.51504, -0.68854}, {-2.53995, -0.61543}, {-2.56026, -0.54313},
      {-2.57583, -0.47095}, {-2.58632, -0.40214}, {-2.5929, -0.33388},
      {-2.59584, -0.2669},  {-2.5965, -0.20323},  {-2.59088, -0.13817},
      {-2.58415, -0.07689}, {-2.57404, -0.0163},  {-2.55813, 0.04199},
      {-2.5374, 0.10109},   {-2.51245, 0.15825},  {-2.48738, 0.21222},
      {-2.45803, 0.26488},  {-2.42471, 0.314},    {-2.38647, 0.36297},
      {-2.3471, 0.40819},   {-2.30357, 0.45124},  {-2.1598, 0.59651},
      {-1.99623, 0.75884},  {-1.84116, 0.91525},  {-1.68546, 1.07255},
      {-1.57778, 1.17373}};
      
  int rows =  sizeof path / sizeof path[0];
  float battery_percentage;

  battery_percentage = 20./100;
  std::cout << "Can the robot complete the path with " << battery_percentage*100 <<"% battery? " << std::endl;
  if (complete_path(path , rows, battery_percentage))  std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  battery_percentage = 80./100;
  std::cout << "Can the robot complete the path with " << battery_percentage*100 <<"% battery? " << std::endl;
  if (complete_path(path , rows, battery_percentage))  std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  battery_percentage = 50./100;
  std::cout << "Can the robot complete the path with " << battery_percentage*100 <<"% battery? " << std::endl;
  if (complete_path(path , rows, battery_percentage))  std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}

