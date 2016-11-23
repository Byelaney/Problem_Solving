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

// l starts from 0 and r is less than n
bool ins_sorted(int* a,int l,int r)
{
    if(l == r)
        return true;

    for(int i = l;i<r;++i)
    {
        if(a[i] > a[i+1])
            return false;
    }
    return true;
}

bool des_sorted(int* a,int l,int r)
{
    if(l == r)
        return true;

    for(int i = l;i<r;++i)
    {
        if(a[i] < a[i+1])
            return false;
    }
    return true;
}

// find the segment start
int seg_start(int* a,int n)
{
    int l = 0;
    for(int i = 0;i<n-1;++i)
    {
        if(a[i] > a[i+1])
        {
            l = i;
            break;
        }
    }
    return l;
}

// find the segment end
int seg_end(int* a,int n)
{
    int r = n-1;
    for(int i = n-1;i>0;--i)
    {
        if(a[i] < a[i-1])
        {
            r = i;
            break;
        }
    }
    return r;
}



int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int* a = new int[n];
    rep(i, n)
    cin >> a[i];

    if(ins_sorted(a,0,n-1))
    {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
    }
    else
    {
        bool solvable = true;

        int l = seg_start(a,n);
        int r = seg_end(a,n);

        if(l > r)
            solvable = false;

        if(des_sorted(a, l, r))
        {
            int prev_l = (l > 0)?(l-1):l;
            int post_r = (r < n-1)?(r+1):r;

            if(l == 0 && r == n-1)
            {
                //do nothing
            }
            else if(l == 0 && r < n-1)
            {
                if(a[l] > a[post_r])
                    solvable = false;
            }
            else if(l > 0 && r == n-1)
            {
                if(a[r] < a[prev_l])
                    solvable = false;
            }
            else
            {
                if((a[r] < a[prev_l]) || (a[l] > a[post_r]))
                    solvable = false;
            }

            if( (!ins_sorted(a,0,prev_l)) || (!ins_sorted(a, post_r, n-1)) )
                solvable = false;

            if(solvable)
            {
                cout << "yes" << endl;
                cout << l+1 << " " << r+1 << endl;
            }
            else
            {
                cout << "no" << endl;
            }

        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
