#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int t,n;
    cin >> t;
    int tmp,last;
    vector<int> v;
    vector<int> v_d;
    while (t--)
    {
        cin >> n;
        last = 0;
        int mins = 1;
        int plus = 1;
        for (int i = 0;i<n;i++)
        {
            cin >> tmp;
            int diff = tmp - last;
            for (int j = 0;j<diff;j++)
            {
                v.push_back(-mins);
                v_d.push_back(-1);
                mins++;
            }
            v.push_back(plus);
            v_d.push_back(1);
            plus++;
            last = tmp;
        }

        for (int i = 0;i<v_d.size();i++)
        {
            if(v_d[i] == 1)
            {   int w_s = 0;
                int flag_sum = 0;
                for (int j = i;j>=0;j--)
                {
                    flag_sum += v_d[j];
                    if(flag_sum == 0)
                    {
                        for (int z = j;z<=i;z++)
                        {
                            if (v[z] > 0)
                            {
                                w_s = v[i] - v[z] + 1;
                                break;
                            }
                        }
                        break;
                    }
                }
                cout << w_s << " ";
            }
        }
        cout << "\n";
        v.clear();
        v_d.clear();
    }
    return 0;
}
