//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    long long n,m;
    cin >> n >> m;
    long long max = (n-m+1) * (n-m)/2;
    long long min = 0;
    if(n%m == 0)
    {
        min = (n/m)*(n/m-1)/2*m;
    }
    else
    {
        long long tmp = n;
        long long round = 0;
        while (tmp - m > 0) {
            tmp -= m;
            round++;
        }
        min = (round+1)*round/2*tmp + (m-tmp)*(round)*(round-1)/2;
    }

    cout << min << " " << max << "\n";

    return 0;
}
