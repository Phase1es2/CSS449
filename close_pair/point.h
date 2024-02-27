/*
 * @Author: your name
 * @Date: 2023-04-28 15:08:15
 * @LastEditTime: 2023-04-28 15:12:02
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /close_pair/point.h
 */
#ifndef POINT_H_
#define POINT_H_
#include <iostream>
using namespace std;

class Point {
 public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}

  friend ostream& operator<<(ostream& os, const Point& p);
};

#endif