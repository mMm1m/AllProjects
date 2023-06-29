#include <bits/stdc++.h>
using ll = long long;

struct Point
{
  double x,y;
  Point(double x_,double y_)
  {
    x = x_;
    y = y_;
  }
};

short type(Point p1, Point p2, Point p3)
{
  double k1 = (p3.y-p2.y)*(p2.x-p1.x), k2 = (p2.y-p1.y)*(p3.x-p2.x);
  if(k1>k2) return 1;
  else if(k1<k2) return 2;
  else return 0;
}

bool part_of_segment(Point p1, Point p2, Point p3)
{
  bool flag;
  (p3.y>=std::min(p1.y,p2.y) && p3.y<=std::max(p1.y,p2.y)
  && p3.x>=std::min(p1.x,p2.x) && p3.x<=std::max(p1.x,p2.x))
  ? flag = true : flag = false;
  return flag;
}

bool intersect(Point p1, Point p2, Point p3, Point p4)
{
  double o1 = type(p1,p2,p3);
  double o2 = type(p1,p2,p4);
  double o3 = type(p3,p4,p1);
  double o4 = type(p3,p4,p2);

  if(o1 != o2 && o3 != o4)
    return true;
  if(o1 == 0 && part_of_segment(p1,p2,p3))
    return true;
  if(o2 == 0 && part_of_segment(p1,p2,p4))
    return true;
  if(o3 == 0 && part_of_segment(p3,p4,p1))
    return true;
  if(o4 == 0 && part_of_segment(p3,p4,p2))
    return true;
  return false;
}

int main()
{
  int t;
  std::cin >> t;
  for(int i = 0; i < t; i++)
  {
    double x1,y1,x2,y2,x3,y3,x4,y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    Point p1(x1,y1), p2(x2,y2), p3(x3,y3), p4(x4,y4);
    if(intersect(p1,p2,p3,p4))
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }
  return 0;
}