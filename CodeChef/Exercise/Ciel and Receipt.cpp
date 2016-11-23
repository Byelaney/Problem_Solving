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

int recipe[] = {1,2,4,8,16,32,64,128,256,512,1024,2048};

int main()
{
    ios::sync_with_stdio(0);
    int T,p;
    cin >> T;
    rep(i, T)
    {
        cin >> p;
        int menus = 0;
        int j,start;
        start = 11;
        while(p != 0)
        {

            for(j = start;j>=0;j--)
            {
                if(p / recipe[j] > 0)
                {
                    start = j;
                    break;
                }
            }
            menus += p/recipe[start];
            p = p % recipe[start];
        }

        cout << menus << endl;
    }


    return 0;
}
