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
    int candles,B;
    cin >> candles >> B;
    int hours = 0;
    int wentout = 0;
    while (candles)
    {
        hours += candles;
        wentout += candles;
        candles = 0;
        candles = wentout/B;
        wentout = wentout%B;

    }
    cout << hours;
    return 0;
}
