#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <list>

#define sf scanf
#define pf printf
#define rep(i,n) for(int i = 0;i<n;++i)
#define rep1(i,n) for(int i = 1;i<n;++i)
#define rep1e(i,n) for(int i = 1;i<=n;++i)
#define r_rep(i,n) for(int i = n-1;i>=0;--i)
#define FOR(i,s,e) for(int i = s;i<=e;++i)
#define LL long long
#define ULL unsigned long long

using namespace std;

int binSearch(int juiccy,int left_p[],int right_p[],int start,int end)
{
    int left = start;
    int right = end;
    int mid = 1;
    while (mid >= start && mid <= end)
    {
        int mid = (right-left)/2 + left;
        if (juiccy < left_p[mid])
            right = mid-1;
        else if (juiccy > right_p[mid])
            left = mid+1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n;
    int left[100002];
    int right[100002];
    left[0] = right[0] = 0;
    rep1e(i, n)
    {
        int num;
        cin >> num;
        left[i] = right[i-1] + 1;
        right[i] = left[i] + num-1;
        //cout << "[" << left[i] << "," << right[i] << "]" << endl;
    }
    cin >> m;
    while (m--)
    {
        int juiccy;
        cin >> juiccy;
        cout << binSearch(juiccy, left,right,1,n) << endl;
    }
    return 0;
}
