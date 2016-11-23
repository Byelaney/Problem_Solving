//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

int MIN(const int a,const int b)
{
    if(a < b)
        return a;
    else
        return b;
}


int ABS(int x)
{
    if(x < 0)
        return -x;
    else
        return x;
}

bool range(int x)
{
    if(x >= -1000 && x <= 1000)
        return true;
    else
        return false;
}

bool withinbounds(int x,int y)
{
    return range(x) && range(y);
}

int main()
{
    ios::sync_with_stdio(0);

    int x1,y1,x2,y2,x3,y3,x4,y4;
    x3 = y3 = x4 = y4 = -10000;
    bool solution = true;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2)
    {
        int d = ABS(y1-y2);
        x3 = x1 + d;
        y3 = y1;
        x4 = x1 + d;
        y4 = y2;

        if(!(withinbounds(x3,y3) && withinbounds(x4, y4)))
        {
            x3 = x1 - d;
            x4 = x1 - d;
            if(!(withinbounds(x3,y3) && withinbounds(x4, y4)))
                solution = false;
        }
    }

    else if(y1 == y2)
    {
        int d = ABS(x1-x2);
        x3 = x1;
        y3 = y1 + d;
        x4 = x2;
        y4 = y2 + d;

        if(!(withinbounds(x3,y3) && withinbounds(x4, y4)))
        {
            y3 = x1 - d;
            y4 = x1 - d;
            if(!(withinbounds(x3,y3) && withinbounds(x4, y4)))
                solution = false;
        }
    }

    else
    {
        int width = ABS(x1-x2);
        int height = ABS(y1-y2);
        if(width != height)
            solution = false;
        else
        {
            x3 = x1;
            y3 = y2;
            x4 = x2;
            y4 = y1;

            if(!(withinbounds(x3,y3) && withinbounds(x4, y4)))
                solution = false;
        }

    }

    if(solution)
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    else
        cout << -1 << endl;

    return 0;
}
