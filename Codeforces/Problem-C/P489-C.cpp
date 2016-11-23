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

string MAX(int m,int s);
string MIN(int m,int s);

int main() {
    ios::sync_with_stdio(0);
    int m,s;
    cin >> m >> s;

    cout <<MIN(m, s) << " " << MAX(m, s) << "\n";
    return 0;
}

string MAX(int m,int s)
{
    string max = "";
    int i;
    for(i = 0;i<m;++i)
    {
        if(s/9 > 0)
        {
            max += '0' + 9;
            s -= 9;
        }else
        {
            max += '0' + s;
            s = 0;
            break;
        }
    }

    for(int j = i+1;j<m;++j)
        max += '0';

    if(max[0] == '0')
        return "-1";
    else
    {
       if(s != 0)
           return "-1";
       else
           return max;
    }
}


string MIN(int m,int s)
{
    if(s == 0 && m != 1)
        return "-1";
    string r_min = "";
    int i;
    for(i = m-1;i>=0;--i)
    {
        if(s/9 > 0)
        {
            r_min += '0' + 9;
            s -= 9;
        }
        else
        {
            r_min += '0' + (s-i);
            s = 0;
            break;
        }
    }
    
    for(int j = i-1;j>=0;--j)
        r_min += '1';

    if(r_min[m-1] == '0')
        return "-1";

    else
    {
        if(s != 0)
            return "-1";
        else
        {
            reverse(r_min.begin(), r_min.end());
            return r_min;
        }
    }

}
