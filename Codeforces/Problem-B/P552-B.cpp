//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    long long s1[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    long long s2[] = {9,90,900,9000,90000,900000,9000000,90000000,900000000,9000000000};
    int n;
    cin >> n;
    int i;
    for(i = 9;i>=0;i--)
    {
        if(n - s1[i] >= 0)
            break;
    }
    if(i == 0)
        cout << n << "\n";
    else
    {
        long long result = 0;
        for(int j = 0;j<i;j++)
        {
            result += s2[j] * (j+1);
        }
        result += (i+1) * (n - s1[i] + 1);
        cout << result << "\n";
    }
    return 0;
}
