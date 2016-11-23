//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool wayToSort(long long i, long long j) { return i > j; }

int main() {
    ios::sync_with_stdio(0);
    long long n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> vv;
    for(long long i = 0;i<n;i++)
    {
        if(s[i] != '0' && s[i] != '1')
        {
            if(s[i] == '4')
            {
                vv.push_back(3);
                vv.push_back(2);
                vv.push_back(2);
            }
            else if(s[i] == '6')
            {
                vv.push_back(5);
                vv.push_back(3);
            }
            else if(s[i] == '8')
            {
                vv.push_back(7);
                vv.push_back(2);
                vv.push_back(2);
                vv.push_back(2);
            }
            else if(s[i] == '9')
            {
                vv.push_back(7);
                vv.push_back(3);
                vv.push_back(3);
                vv.push_back(2);
            }
            else
                vv.push_back(s[i] - '0');
        }
    }
    sort(vv.begin(),vv.end(),wayToSort);
    for (vector<long long>::iterator it = vv.begin() ; it != vv.end(); ++it)
        cout << *it;
    cout << "\n";
    return 0;
}


/*
This problem needs a little math.The key is to figure out the follow:
  2! = 1! * 2!
  4! = 3! * 2! * 2!
  6! = 5! * 3!
  8! = 7! * 2! * 2! * 2!
  9! = 7! * 3! * 3! * 2!

*/
