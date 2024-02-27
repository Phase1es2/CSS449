/*
 * @Author: your name
 * @Date: 2023-04-28 15:08:19
 * @LastEditTime: 2023-04-28 15:13:57
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /close_pair/point.cpp
 */

#include "point.h"

ostream& operator<<(ostream& os, const Point& p) {
  os << p.x << " " << p.y;
  return os;
}