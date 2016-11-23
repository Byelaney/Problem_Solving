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
    int n,m;
    cin >> n >> m;
    int days = 0;
    int cooldown = m;
    while (n) {
        days++;
        n--;cooldown--;
        if(cooldown == 0)
        {
            n++;
            cooldown = m;
        }
    }
    cout << days;
    return 0;
}
