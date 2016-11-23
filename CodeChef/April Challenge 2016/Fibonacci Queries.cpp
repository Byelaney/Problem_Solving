//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>

#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <math.h>
#include <set>
#include <queue>


#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define _CRT_SECURE_NO_WARNINGS
#define LL long long
#define ULL unsigned long long

using namespace std;

struct term
{
    ULL num;
    ULL rootfive;
    ULL denominator;
};


void multiply(ULL F[2][2], ULL M[2][2]);

void power(ULL F[2][2], ULL n);

/* function that returns nth Fibonacci number */
ULL fib(ULL n)
{
    ULL F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[0][0];
}

/* Optimized version of power() in method 4 */
void power(ULL F[2][2], ULL n)
{
    if( n == 0 || n == 1)
        return;
    ULL M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0)
        multiply(F, M);
}

void multiply(ULL F[2][2], ULL M[2][2])
{
    ULL x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    ULL y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    ULL z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    ULL w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}


term* multiply(term* a,term* b);
term* exponents(term* a,ULL n);
term* add(term* a,term* b);

int main()
{
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;

    vector<ULL>A;
    ULL max = 0;
    rep(i, N)
    {
        ULL t;
        cin >> t;
        if(t > max)
            max = t;
        A.push_back(t);
    }

    rep(i, Q)
    {
        char command;
        cin >> command;
        if(command == 'Q')
        {
            int L,R;
            cin >> L >> R;
            //from L-1 to R

            term* BASE = (term*)malloc(sizeof(struct term));
            BASE->num = 1;
            BASE->rootfive = 1;
            BASE->denominator = 1;

            term* result = exponents(BASE, A[L-1]);

            for(int Ai = L;Ai<R;++Ai)
            {
                term* r = exponents(BASE, A[Ai]);
                term* multi = multiply(result, r);
                term* sum = add(result, r);

                result->num = multi->num + sum->num;
                result->rootfive = multi->rootfive + sum->rootfive;
            }

            cout << result->rootfive%1000000007 << endl;

        }
        else if(command == 'C')
        {
            int X;
            ULL Y;
            cin >> X >> Y;
            A[X-1] = Y;
        }
    }


//    term* a = (term*)malloc(sizeof(struct term));
//    term* b = (term*)malloc(sizeof(struct term));
//    a->num = 1;
//    a->rootfive = 1;
//    a->denominator = 1;//this means 2^1
//
//    b->num = 6;
//    b->rootfive = 2;
//    b->denominator = 2;//this means 2^1
//
//
//    term* r = multiply(a, b);
//
//    cout << r->num << endl;
//    cout << r->rootfive << endl;
//    cout << r->denominator << endl;



    return 0;
}


//multiply two terms and 约分
term* multiply(term* a,term* b)
{
    term* res = (term*)malloc(sizeof(struct term));
    res->num = (a->num * b->num + 5* a->rootfive * b->rootfive)%1000000007;
    res->rootfive = (a->num * b->rootfive + a->rootfive * b->num)%1000000007;
    res->denominator = (a->denominator + b->denominator)%1000000007;

    //约分
    while(((res->rootfive %2 == 0) && (res->num %2 == 0)) && (res->denominator > 1))
    {
        res->rootfive /= 2;
        res->num /= 2;
        res->denominator -= 1;
    }

    return res;
}


//multiply one term and 约分 several times
term* exponents(term* a,ULL n)
{
    term* res = (term*)malloc(sizeof(struct term));
    res->num = a->num;
    res->rootfive = a->rootfive;
    res->denominator = a->denominator;
    for(int i = 1;i<n;++i)
    {
        res = multiply(res,a);
    }

    return res;
}

term* add(term* a,term* b)
{
    term* res = (term*)malloc(sizeof(struct term));
    res->num = (a->num + b->num)%1000000007;
    res->rootfive = (a->rootfive + b->rootfive)%1000000007;
    res->denominator = 1;
    return res;
}
