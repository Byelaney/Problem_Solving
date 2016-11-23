//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int n;
    int index = 0;
    for(int i = 0;i<25;i++)
    {
        cin >> n;
        if (n == 1)
            index = i;
    }
    int row = index/5 + 1;
    int column = index - (row-1) * 5 + 1;
    cout << abs(row-3) + abs(column-3);
    return 0;
}
