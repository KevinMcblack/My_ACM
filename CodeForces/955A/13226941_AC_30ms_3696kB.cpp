#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int hh, mm;
	double hun, inc, number, des;
	while (cin >> hh >> mm)
	{
		cin >> hun >> inc >> number >> des;
		if (hh >= 20)
		{
			cout << (ceil(hun / des) * number*0.8) << endl;
			continue;
		}
		else
		{
			double part1 = (ceil(hun / des) * number);
			double part2;
			int chh, chm;
			if (mm == 0)
			{
				chh = 20 - hh;
				part2 = (ceil((hun + chh * 60 * inc) / des) * number*0.8);
			}
			else
			{
				chh = 20 - hh - 1;
				chm = 60 - mm;
				int extend = chm + chh * 60;
				part2 = ( ceil( ( hun + extend *  inc ) / des) * number*0.8);
			}
			printf("%.4lf\n", min(part1, part2));
		}
	}
	return 0;
}