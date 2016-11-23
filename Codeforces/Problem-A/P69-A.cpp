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
    int n;
    cin >> n;
    int x = 0;
    int y = 0;
    int z = 0;
    int t;
    while (n--)
    {
        cin >> t;
        x += t;
        cin >> t;
        y += t;
        cin >> t;
        z += t;
    }
    if( (x == 0 && y == 0) && z == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
