/*
 * @Author: Hao Yang
 * @Date: 2023-04-17 17:06:21
 * @LastEditTime: 2023-05-06 11:16:30
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /CSS449/Program2/PointSet.cpp
 */

#include "PointSet.h"
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <fstream>
#include <iostream>

/**
 * @brief Constructor for PointSet class.
 *
 * @param file The name of the input file containing point coordinates.
 */
PointSet::PointSet(const std::string& fileName) {
  // open the input file
  std::ifstream in(fileName);
  int n;
  // read the first line number of points
  in >> n;
  // read the x and y coordiantes of the points and store them in the vector
  while(n --){
    double x, y;
    in >> x >> y;
    points.emplace_back(x, y);
  }
  // Sort the points by their x-corrdiante
  std::sort(points.begin(), points.end(),
            [](const Point& p1, const Point& p2) { return p1.x < p2.x; });
}

/**
 * @brief Function to find the closest pair of points.
 *
 * @return The distance between the closest pair of points.
 */
double PointSet::closestPair() {
  // call the recursive closestUtil method
  return closest_Pair(0, points.size() - 1);
}

/**
 * @brief Recursive function to find the closest pair of points.
 *
 * @param left  The left index of the subarray.
 * @param right The right index of the subarray.
 * @return      The distance between the closest pair of points in the subarray.
 */
double PointSet::closest_Pair(int l, int r) {
  int size = r - l + 1;

  // If there are three or fewer points, we need to use brute force;
  if (size <= 3) {
    double result = bruteForce(l, r);
    // use the cout.precision to limit there are only 4 decimal nubmer after
    // point.
    std::cout.precision(4);
    // print the distance between the closest pair of points in this range
    std::cout << "D[" << l << "," << r << "]: " << std::fixed << result
              << std::endl;
    return result;
  }

  // Calculate the midpoint index
  // int mid = l + size - 1 >> 1; (this is will create a segementation fault)
  int mid = l + (size - 1) / 2;

  // Recursivley find the closest pair of points in the left and right half.
  double dl = closest_Pair(l, mid);
  double dr = closest_Pair(mid + 1, r);
  // find the minimum distance between dl and dr.
  double d = std::min(dl, dr);

  // find points that are within d distance of the vertical line at the midpoint
  std::vector<Point> strips;

  for (int i = l; i <= r; ++i)
    if (std::abs(points[i].x - points[mid].x) < d) strips.push_back(points[i]);

  // find the smallest distance in teh strip
  double strip_d = stripClosest(l, r, d);
  double min_d = std::min(d, strip_d);

  // use the cout.precision to limit there are only 4 decimal nubmer after
  // point.
  std::cout.precision(4);
  // print the distance between the closest pair of points in this range
  std::cout << "D[" << l << "," << r << "]: " << std::fixed << min_d
            << std::endl;
  // reutrn the smallest distance
  return min_d;
}

/**
 * @brief Brute force method for finding the smallest distance between points.
 *
 * @param left  The left index of the subarray.
 * @param right The right index of the subarray.
 * @return      The smallest distance between points in the subarray.
 */
double PointSet::bruteForce(int l, int r) {
  double min = DBL_MAX;
  // Iterate through all possible pairs of points and find the minimum distance.
  for (int i = l; i <= r; ++i)
    for (int j = i + 1; j <= r; ++j) {
      double dist =
          sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) +
               (points[i].y - points[j].y) * (points[i].y - points[j].y));
      //sqrt(pow(n, 2))
      if (dist < min) min = dist;
    }

  // reutrn the minimum distance
  return min;
}

/**
 * @brief Function to find the smallest distance in the strip.
 *
 * @param left  The left index of the subarray.
 * @param right The right index of the subarray.
 * @param d     The smallest distance found in the left and right subarrays.
 * @return      The smallest distance between points in the strip.
 */
double PointSet::stripClosest(int l, int r, double d) {
  double min = d;
  // Sort the points in the strip by their y-coordinate
  std::sort(points.begin() + l, points.begin() + r + 1,
            [](const Point& p1, const Point& p2) { return p1.y < p2.y; });

  // Iterate through the points in the strip and find the minimum disatance
  for (int i = l; i <= r; ++i)
    for (int j = i + 1; j <= r && (points[j].y - points[i].y) < min; ++j) {
      double dist =
          sqrt((points[j].x - points[i].x) * (points[j].x - points[i].x) +
               (points[j].y - points[i].y) * (points[j].y - points[i].y));
      if (dist < min) min = dist;
    }
  // reutnr the minimum distance
  return min;
}
