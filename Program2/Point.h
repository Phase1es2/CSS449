/*
 * @Author: Hao Yang
 * @Date: 2023-04-17 16:54:18
 * @LastEditTime: 2023-04-28 23:21:26
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /CSS449/Program2/Point.h
 */

#ifndef POINT_H_
#define POINT_H_
#include <iostream>

class Point {
 public:
  /**
   * @brief Constructor for Point class.
   *
   * @param x The x-coordinate of the point (default: 0).
   * @param y The y-coordinate of the point (default: 0).
   */
  // Constructor for Point with default values for x and y
  Point(double x = 0, double y = 0) : x(x), y(y) {}

  // Overload << operaotr to print Point
  friend std::ostream& operator<<(std::ostream& os, const Point& p);

  private: 
    double x, y;
    friend class PointSet;
};

#endif