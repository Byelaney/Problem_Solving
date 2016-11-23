//
//  main.cpp
//  Acm
//
//  Created by 管君 on 16/3/14.
//  Copyright © 2016年 カンクン. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i = 0;i<N;i++)
        cin >> a[i];
    sort(a,a+N);

    int height = 1;
    int totals = 1;
    int max = 1;

    for(int i = 0;i<N-1;i++)
    {
        if(a[i] == a[i+1])
        {
            height++;
            if(height > max)
            {
                max = height;
            }
        }
        else
        {
            height = 1;
            totals++;
        }
    }

    cout << max << " " << totals << "\n";

    return 0;
}
