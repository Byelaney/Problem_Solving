//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;


int main() {
    int n,l;
    cin >> n >> l;
    double* lantern = new double[n];
    for(int i = 0;i<n;i++)
        cin >> lantern[i];
    sort(lantern,lantern+n);
    double rad = 0.0;
    double lt = 0.0;
    for(int i = 0;i<n-1;i++)
    {
        lt = (lantern[i+1] - lantern[i])/2.0;
        rad = (lt>rad)?lt:rad;
    }
    rad = (lantern[0]>rad)?(lantern[0]*1.0):rad;
    rad = ((l-lantern[n-1])>rad)?((l-lantern[n-1])*1.0):rad;

    cout << fixed << setprecision(10) << rad;
    return 0;
}
