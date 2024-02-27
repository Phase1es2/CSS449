/*
 * @Author: your name
 * @Date: 2023-04-28 15:08:26
 * @LastEditTime: 2023-04-28 15:39:05
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /close_pair/point_set.h
 */

#ifndef POINT_SET_H_
#define POINT_SET_H_
#include <vector>

#include "point.h"
using namespace std;

class Point_Set {
 public:
  Point_Set(const string& fileName);
  double closet_pair();

 private:
  vector<Point> p;
  double bruteForce(int l, int r);
  double closetUtil(int l, int r);
  double closet_Y(int l, int r, int d);
};

#endif
