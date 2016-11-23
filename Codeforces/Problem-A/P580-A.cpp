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
    int num;
    cin >> num;
    int last = num;
    int max = 0;
    int length = 0;
    for(int i = 1;i<n;i++)
    {
        cin >> num;
        if(num >= last)
        {
            length++;
            last = num;
            if(length > max)
                max = length;
        }
        else
        {
            length = 0;
            last = num;
        }

    }
    cout << max+1;
    return 0;
}
