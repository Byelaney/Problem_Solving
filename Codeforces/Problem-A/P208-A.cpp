//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int i = 0;
    int j = 0;
    for(;i<s.length();)
    {
        if ((s[i] == 'W' && s[i+1] == 'U') && s[i+2] == 'B')
        {
            i += 3;
        }
        else
        {
            for(j = i+1;j<s.length();j++)
            {
                if ((s[j] == 'W' && s[j+1] == 'U') && s[j+2] == 'B')
                {
                    break;
                }
            }
            for (int z = i; z<j; z++)
                cout << s[z];
            cout << " ";
            i = j;
        }
    }
    return 0;
}
