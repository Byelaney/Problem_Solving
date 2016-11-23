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
#include <stack>
#include <utility>


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define r_rep(i,n) for(int i = n-1;i>=0;--i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;
int intersect(vector<int> a,vector<int> b);
int myUnion(vector<int> a,vector<int> b);

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        int N,M,K,file;
        cin >> N >> M >> K;
        vector<int> ignored;
        vector<int> tracked;

        rep(i, M)
        {
            cin >> file;
            ignored.push_back(file);
        }

        rep(i, K)
        {
            cin >> file;
            tracked.push_back(file);
        }

        int o1 = intersect(ignored, tracked);
        int o2 = N - myUnion(ignored, tracked);

        cout << o1 << " " << o2 << endl;
    }

    return 0;
}

int intersect(vector<int> a,vector<int> b)
{
    int res = 0;
    int i = 0;
    int j = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
            i++;
        else if(a[i] > b[j])
            j++;
        else
        {
            res++;
            i++;j++;
        }
    }

    return res;
}

int myUnion(vector<int> a,vector<int> b)
{
    int res = 0;

    int i = 0;
    int j = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            res++;
            i++;
        }
        else if(a[i] > b[j])
        {
            res++;
            j++;
        }
        else
        {
            res++;
            i++;j++;
        }
    }

    while(i < a.size())
    {
        res++;
        i++;
    }


    while(j < b.size())
    {
        res++;
        j++;
    }

    return res;
}
