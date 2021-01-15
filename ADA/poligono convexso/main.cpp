#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
struct Point
{
    int x, y;
};
Point p0;
Point next_Top(stack<Point> &S)
{
    Point p = S.top();cout<<p.x<<" p  "<<p.y<<endl;
    S.pop();
    Point res = S.top();cout<<res.x<<" res "<<res.y<<endl;
    S.push(p);
    return res;
}
int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
int distSq(Point p1, Point p2)
{
    cout<<"dis  "<<(p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y)<<endl;
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
// 0 --> p, q y r igual, lineal, 1 --> horario, 2 --> antihorario
int orientacion(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);//producto vectorial
    cout<<"ori "<<val<<endl;
    if (val == 0) return 0;  // lineal
    return (val > 0)? 1: 2; // horaio o antihorario
}
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;cout<<p1->x<<"pun1"<<p1->y<<endl;
   Point *p2 = (Point *)vp2;cout<<p2->x<<"pun2"<<p2->y<<endl;
   int o = orientacion(p0, *p1, *p2);cout<<" ooo "<<o<<endl;
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
   return (o == 2)? -1: 1;
}
void polig_convexo(Point points[], int n)
{
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
     if ((y < ymin) || (ymin == y && points[i].x < points[min].x)){
        ymin = points[i].y; min = i;}
   }
   swap(points[0], points[min]);
   p0 = points[0];
   for(int i=0;i<n;i++){
    cout<<"("<<points[i].x<<",,"<<points[i].y<<") ";
   }
   qsort(&points[1], n-1, sizeof(Point), compare);
   for(int i=0;i<n;i++){
    cout<<"("<<points[i].x<<","<<points[i].y<<") ";
   }
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       while (i < n-1 && orientacion(p0, points[i],points[i+1]) == 0)
          i++;
       points[m] = points[i];
       m++;  // Update size of modified array
   }
   if (m < 3) return;
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
   for (int i = 3; i < m; i++)
   {
      while (orientacion(next_Top(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
   while (!S.empty())
   {
       Point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}
int main()
{
    Point points[] = {{0, 3}, {1, 1}, {4, 4}, {2, 2},{0, 0}, {1, 2}, {3, 3},{1,4},{2,3}};
    int n = sizeof(points)/sizeof(points[0]);
    polig_convexo(points, n);
    return 0;
}
