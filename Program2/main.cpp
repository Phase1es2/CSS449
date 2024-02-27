/*
 * @Author: Hao Yang
 * @Date: 2023-04-17 16:23:23
 * @LastEditTime: 2023-04-28 23:29:54
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /CSS449/Program2/main.cpp
 */

// The closest pair of points problem is base on divide-and-conquer algorithm
// We need pre-sort the points based on their x-coordinates.
// If the number of points is less equal to 3, use the brute-force
// method to find the minimum distance between the points. Otherwise, divide the
// set of points into two halves. Recursively find the smallest distances in
// both sub lists. The minimum distance between the two halves will be the
// minimum of the smallest distances found in the left and right sub list. To
// account for the points near the dividing line, find the points within the
// minimum distance found so far from the dividing line and store them in a
// separate list. Sort the points in the strip by their y-coordinates. Iterate
// through the points in the strip and compare the distance between each point
// and its next 7 neighbors. If distances are less than the previouds minimum
// distance, update the minimum distance. Return minimum distance as result.
// the code require to handle 1000 input
// the code need to print the output with 4 decimal place after point.
// The algorithm must run in O(n log n) time. 
// The file should be hardcoded to the name program2data.txt


#include "PointSet.h"

int main() {
  PointSet pointSet("program2data.txt");
  double result = pointSet.closestPair();
  return 0;
}
