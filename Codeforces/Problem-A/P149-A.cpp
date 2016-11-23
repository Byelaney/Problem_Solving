//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int k;
    cin >> k;

    if(k == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    
    int* a = new int[12];
    for(int i = 0;i<12;i++)
        cin >> a[i];
    sort(a,a+12);
    int growth = 0;
    int j;
    for(j = 11;j>=0;j--)
    {
        growth += a[j];
        if(growth >= k)
            break;
    }
    if(growth >= k)
        cout << 12 - j << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
