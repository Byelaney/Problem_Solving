#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ORcount(string a, string b)
{
    int counts = 0;
    for (int i = 0;i<a.size();++i)
    {
        if (a[i] == '1' || b[i] == '1')
            counts++;
    }
    return counts;
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(m);
    for(int topic_i = 0;topic_i < n;topic_i++){
        cin >> topic[topic_i];
    }
    int max_topics = 0;
    int max_pairs = 0;
    for (int i = 0;i<n-1;++i)
    {
        for (int j = i+1;j<n;++j)
        {
            int ones = ORcount(topic[i], topic[j]);
            if (ones > max_topics)
            {
                max_topics = ones;
                max_pairs = 1;
            }
            else if (ones == max_topics)
            {
                max_pairs++;
            }
        }
    }
    cout << max_topics << endl;
    cout << max_pairs << endl;
    return 0;
}
