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
    long long n;
    cin >> n;
    if (n%2 == 0)
        cout << (n/2);
    else
        cout << (n-1)/2 - n;
}
