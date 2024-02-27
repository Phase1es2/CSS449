/*
 * @Author: your name
 * @Date: 2023-04-28 15:08:34
 * @LastEditTime: 2023-04-28 16:27:48
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /close_pair/point_set.cpp
 */

#include "point_set.h"

#include <algorithm>
#include <cfloat>
#include <fstream>
#include <iostream>
#include <limits>

Point_Set::Point_Set(const string& fileName) {
  ifstream in(fileName);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    p.emplace_back(Point(x, y));
  }
  sort(p.begin(), p.end(),
       [](const Point& p1, const Point& p2) { return p1.x < p2.x; });
}

double Point_Set::closet_pair() { return closetUtil(0, p.size() - 1); }

double closetUtil(int l, int r) {
  int size = r - l + 1;
  if (size <= 3) {
    double res = bruteForce(l, r);
    cout.precision(4);
    cout << "D[" << l << "," << r << "]: " << fixed << res << endl;
    return res;
  }

  int mid = (l + (size - 1)) >> 1;
  double dl, dr, d;
  dl = closetUtil(l, mid);
  dr = closetUtil(mid + 1, r);
  d = min(dl, dr);

  vector<Point> strip;
  for(int i = l; i <= r; ++i)
    if(abs(p[i].x - p[mid].x) < d)
        strip.push_back(p[i]);

 double strip_d = closet_Y(l, r, d);
 double min_d = min(d, strip_d);
 cout.precision(4);
  cout << "D[" << l << "," << r << "]: " << fixed << min_d << endl;
  return min_d;
}

double Point_Set::bruteForce(int l, int r) {
  double min = DLB_MAX;
  for (int i = l; i <= r; ++i)
    for (int j = l + 1; j <= r; ++j) {
      auto d = hypot(p[i].x - p[j].x, p[i].y - p[j].y);
      if (d < min) min = d;
    }
  return min;
}
double Point_Set::closet_Y(int l, int r, int d) {
  double min = d;
  sort(p.begin() + l, p.begin() + r + 1,
       [](const Point& p1, const Point& p2) { return p1.y < p2.y; });

  for (int i = l; i <= r; ++i)
    for (int j = i + 1; j <= r && (p[j].y - p[i].y) < min; ++j) {
      auto d = hypot(p[j].x - p[i].x, p[j].y - p[i].y);
      if (d < min) min = d;
    }
  return min;
}
