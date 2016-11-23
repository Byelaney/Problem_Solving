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

using namespace std;

string NumToS(int num);
int STONum(string s);
int myatoi(string s);

int base[] = {1,10,100,1000,10000,100000,1000000,10000000};

int main() {
    ios::sync_with_stdio(0);
    int n;
    string c;
    cin >> n;
    while(n--)
    {
        cin >> c;
        bool f1 = false;
        bool f2 = false;
        int sec_idx = -1;
        for(int i = 0;i<c.length()-1;i++)
        {
            if(c[i] == 'R' && ('0' <= c[i+1] && c[i+1] <= '9'))
            {
                f1 = true;
                continue;
            }
            if(c[i] == 'C' && ('0' <= c[i+1] && c[i+1] <= '9'))
            {
                f2 = true;
                sec_idx = i;
                break;
            }
        }

        if(f1 && f2)
        {
            string s1 = "";
            string s2 = "";
            for(int i = sec_idx+1;i<c.length();i++)
                s1 += c[i];
            for(int i = 1;i<sec_idx;i++)
                s2 += c[i];

            cout << NumToS(myatoi(s1)) << s2 << "\n";
        }
        else
        {
            int i;
            string s1 = "";
            string s2 = "";
            for(i = 0;i<c.length();i++)
            {
                if(c[i] <= '9' && c[i] >= '0')
                    break;
                else
                    s1 += c[i];
            }
            for(int j = i;j<c.length();j++)
                s2 += c[j];

            cout << "R" << s2 << "C" << STONum(s1) << "\n";
        }
    }


    return 0;
}

string NumToS(int num)
{
    string s = "";
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(num > 0)
    {
        if(num%26 == 0)
        {
            num = num/26 - 1;
            s+='Z';
        }
        else
        {
            int k = num%26;
            num = num/26;
            s+=a[k-1];
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int STONum(string s)
{
    int k;
    int num = 0;
    for(int i = 0;i<s.length();i++)
    {
        k = s[i] - 'A' + 1;
        num = num*26 + k;
    }

    return num;
}

int myatoi(string s)
{
    int num = 0;
    for(int i = 0;i<s.length();i++)
    {
        num += (s[i] - '0') * base[s.length()-i-1];
    }
    return num;
}
