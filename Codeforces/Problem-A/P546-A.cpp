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
    unsigned long k,n,w;
    cin >> k >> n >> w;
    unsigned long sum = 0;
    for(int i = 0;i<w;i++)
    {
        sum += (i+1)*k;
    }
    if (sum > n)
        cout << (sum-n);
    else
        cout << 0;
    return 0;
}
