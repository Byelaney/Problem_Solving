#include<iostream>

using namespace std;

int main()
{
	int n, grade, next, final;
	cin >> n;
	while (n--)
	{
		cin >> grade;
		next = (grade / 5 + 1) * 5;
		if (grade >= 38 && (next - grade < 3))
			final = next;	
		else
			final = grade;

		cout << final << endl;
	}
	return 0;

}
