//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//
#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <math.h>

using namespace std;

bool X_qualified(int N,int E);
bool Y_qualified(int N,int E);
bool T_qualified(int N,int E);


int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    int N = n;
    int E = m;
    while(1)
    {
        if(T_qualified(N,E))
        {
            if(X_qualified(N,E))
            {
                if(Y_qualified(N,E))
                    break;
                else
                {
                    if(2*E-N < 0)
                        --N;
                    else
                        (E > N)?--E:--N;
                }
            }
            else
            {
                if(2*N-E < 0)
                    --E;
                else
                    (E > N)?--E:--N;
            }
        }
        else
        {
            (E > N)?--E:--N;
        }
    }

    cout << (N+E)/3 << endl;
    return 0;
}

bool X_qualified(int N,int E)
{
    if((2*N-E >= 0)&&((2*N-E)%3 == 0))
        return true;
    else
        return false;
}

bool Y_qualified(int N,int E)
{
    if((2*E-N >= 0)&&((2*E-N)%3 == 0))
        return true;
    else
        return false;
}

bool T_qualified(int N,int E)
{
    if((N+E)%3 == 0)
        return true;
    else
        return false;
}
