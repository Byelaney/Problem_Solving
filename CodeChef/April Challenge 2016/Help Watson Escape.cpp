//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//
#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)




#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <fstream>

#include <cstring>

#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <math.h>


using namespace std;

int MAX(int a,int b)
{
    return (a>b)?a:b;
}


unsigned long long fast_exp(unsigned long long base, unsigned long long exp) {
    unsigned long long res=1;
    while(exp>0) {
        if(exp%2==1) res=(res*base)%1000000007;
        base=(base*base)%1000000007;
        exp/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        unsigned long long N,K;
        cin >> N >> K;
        unsigned long long combs = K;
        --N;
        combs *= fast_exp(K-1,N);
        cout << combs%1000000007 << endl;
    }
    return 0;
}





//vector<string> &split(const string &s, char delim, vector<string> &elems);
//vector<string> split(const string &s, char delim);
//vector<string> tokenization(string s);
//map<string,int> tokens(string file);
//
//int main()
//{
//
//
//    return 0;
//}
//
//
//map<string,int> tokens(string file)
//{
//    map<string,int> m;
//    try {
//        ifstream infile(file);
//        string line;
//
//        while (getline(infile, line))
//        {
//            vector<string> v = tokenization(line);
//            for(int i = 0;i<v.size();++i)
//            {
//                if(v[i] == " ")
//                    continue;
//
//                if(m.count(v[i]) == 0)
//                {
//                    m[v[i]] = 1;
//                }
//                else
//                {
//                    m[v[i]] = m[v[i]] + 1;
//                }
//            }
//        }
//
//    } catch (exception &e) {
//        cerr << e.what() << "\n";
//
//    }
//    return m;
//}
//
//
//vector<string> tokenization(const string s)
//{
//    string f_s;
//    remove_copy_if(s.begin(), s.end(),
//                   back_inserter(f_s), //Store output
//                   ptr_fun<int, int>(&ispunct));
//
//    return split(f_s,' ');
//}
//
//
//vector<string> &split(const string &s, char delim, vector<string> &elems) {
//    stringstream ss(s);
//    string item;
//    while (getline(ss, item, delim)) {
//        elems.push_back(item);
//    }
//    return elems;
//}
//
//vector<string> split(const string &s, char delim) {
//    vector<string> elems;
//    split(s, delim, elems);
//    return elems;
//}
//
