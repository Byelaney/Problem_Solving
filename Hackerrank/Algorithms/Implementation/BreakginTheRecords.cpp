#include <iostream>

int main()
{
	int n, s, h, l;
	int hc = 0;
	int lc = 0;
	std::cin >> n;
	std::cin >> s;
	h = s;
	l = s;
	n--;
	while (n--)
	{
		std::cin >> s;
		if (s > h)
		{
			hc++;
			h = s;
		}
		if (s < l)
		{
			lc++;
			l = s;
		}

	}
	std::cout << hc << " " << lc << std::endl;
	return 0;
}
