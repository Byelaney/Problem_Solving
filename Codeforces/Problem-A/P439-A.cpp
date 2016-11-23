//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)

struct exam
{
    int id;
    int a;
    int b;
};


using namespace std;

bool cmp1(exam* e1,exam* e2){return e1->a < e2->a;}
bool cmp2(exam* e1,exam* e2){return e1->b < e2->b;}

bool finish(int* songs,int n,int d);

int main() {
    ios::sync_with_stdio(0);
    int n,d;
    cin >> n >> d;
    int* songs = new int[n];
    rep(i, n)
    cin >> songs[i];

    if(finish(songs, n, d))
    {
        int jokes = 0;
        while(finish(songs, n, d-5))
        {
            d -= 5;
            ++jokes;
        }

        for(int i = 0;i<n;++i)
        {
            d -= songs[i];
        }
        d -= (n-1)*10;
        jokes += (n-1)*2 + d/5;

        cout << jokes << "\n";
    }
    else
        cout << -1 << "\n";
    return 0;
}

bool finish(int* songs,int n,int d)
{
    int time = 0;
    for(int j = 0;j<n-1;++j)
    {
        time += songs[j] + 10;
    }
    if(time + songs[n-1] <= d)
        return true;
    else
        return false;
}
