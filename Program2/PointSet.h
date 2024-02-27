/*
 * @Author: Hao Yang
 * @Date: 2023-04-17 16:54:51
 * @LastEditTime: 2023-04-28 22:59:38
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /CSS449/Program2/PointSet.h
 */

#ifndef POINT_SET_H_
#define POINT_SET_H_
#include <vector>

#include "Point.h"

class PointSet {
 public:
  // Constructor for PointSet class
  // read the data from the input file
  PointSet(const std::string& fileName);
  // Function to find the closest pair of points
  double closestPair();

 private:
  // vecotr use to store all the input poins;
  std::vector<Point> points;
  // private helper functions;
  // recursive function to find the closest pair of points
  double closest_Pair(int l, int r);
  // Brute force method for finding the smallest distance between points
  // which deal with less and equal 3 inputs
  double bruteForce(int l, int r);
  // function to find the smallest distance in the strip.
  double stripClosest(int l, int r, double d);
};

#endif