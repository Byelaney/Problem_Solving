#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double mealCost = 0;
    int tipPercent = 0;
    int taxPercent = 0;
    cin >> mealCost >> tipPercent >> taxPercent;
    double totalCost = mealCost + mealCost * 1.0*tipPercent/100 + mealCost * 1.0*taxPercent/100;
    cout << "The total meal cost is " << round(totalCost) << " dollars." << endl;
    return 0;
}
