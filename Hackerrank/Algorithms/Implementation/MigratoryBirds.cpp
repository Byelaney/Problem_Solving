#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, t, f;
	int m = 0;
	cin >> n;
	vector<int> v(5);
	while (n--)
	{
		cin >> t;
		v[t-1]++;
	}
	for (int i = (int) v.size() - 1; i >= 0; --i)
		if (v[i] >= m) {
			m = v[i];
			f = i + 1;
		}	
	cout << f << endl;
	return 0;
}
