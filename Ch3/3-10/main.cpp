#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef struct Point
{
    int x,y;
    Point(int x=0, int y=0):x(x),y(y){}
}Point;

bool operator < (Point &a, Point &b)
{
    return (a.x<b.x || (a.x==b.x && a.y<b.y));
}
bool operator == (Point &a, Point &b)
{
    return (a.x==b.x && a.y==b.y);
}
bool operator != (Point &a, Point &b)
{
    return (a.x!=b.x || a.y!=b.y);
}

vector<Point> pallets;
bool solve();
int main()
{
    Point tmp;
    while(true)
    {
        pallets.clear();
        for(int i=0; i<6; i++)
        {
            if(!(cin>>tmp.x>>tmp.y))
                return 0;
            if(tmp.x>tmp.y)
                swap(tmp.x, tmp.y);
            pallets.push_back(tmp);
        }
        if(solve())
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

bool solve()
{
    sort(pallets.begin(), pallets.end());
    for(int i=0; i<3; i++)
    {
        if(pallets[2*i]!=pallets[2*i+1])
            return false;
    }
    if(pallets[0].y==pallets[4].x && pallets[2].y==pallets[4].y && pallets[0].x==pallets[2].x)
        return true;
    else
        return false;
}
