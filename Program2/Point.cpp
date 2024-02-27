/*
 * @Author: Hao Yang
 * @Date: 2023-04-17 16:54:09
 * @LastEditTime: 2023-04-28 18:15:51
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /CSS449/Program2/Point.cpp
 */

#include "Point.h"

/**
 * @brief Overloaded << operator implementation for Point class.
 *
 * @param os The output stream to print the point.
 * @param p  The point to be printed.
 * @return   The output stream with the point coordinates.
 */
std::ostream& operator<<(std::ostream& os, const Point& p) {
  os << p.x << " " << p.y;
  return os;
}
