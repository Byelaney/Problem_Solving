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
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int num1,num2;
    cin >> num1;
    int num;
    for (int i = 1;i<n;i++)
    {
        cin >> num;
        num1 = num1^num;
    }
    num2 = num1;
    for (int i = 0;i<n-1;i++)
    {
        cin >> num;
        num1 = num1 ^ num;
    }
    num2 = num2 ^ num1;
    for (int i = 0;i<n-2;i++)
    {
        cin >> num;
        num2 = num2 ^ num;
    }
    cout << num1 << "\n" << num2;
    return 0;
}
