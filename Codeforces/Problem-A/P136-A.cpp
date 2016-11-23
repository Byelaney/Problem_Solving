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
    int* a = new int[n];
    int num = 0;
    for(int i = 0;i<n;i++)
    {
        cin >> num;
        a[num-1] = i+1;
    }
    for(int i = 0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
