
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    double V_s,R,C;
    int n;
        cin >> V_s >> R >> C >> n;

        double w;
        while (n--)
        {
            cin >> w;
            cout.precision(3);
            cout.setf(ios::fixed);
            cout << C * R * w * V_s /(sqrt(1.0 + C * C * R * R * w * w)) << "\n";
        }

    return 0;
}
