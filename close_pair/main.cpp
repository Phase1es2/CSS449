/*
 * @Author: your name
 * @Date: 2023-04-28 15:08:39
 * @LastEditTime: 2023-04-28 16:29:01
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /close_pair/main.cpp
 */

#include "point_set.h"

int main() {
    Point_Set pointSet("program2data.txt");
    double result = pointSet.closet_pair();
    return 0;
}