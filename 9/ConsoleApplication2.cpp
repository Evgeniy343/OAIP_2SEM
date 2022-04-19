#include<iostream>
#include<math.h>

using namespace std;

void find_roots(int *gap, double x, double *roots);

int main()
{
	double x = 0, roots[3];
	int gap[8] = { -2, -1, 0, 1, 2, 3, 4, 5 };
	find_roots(gap, x, roots);
	return 0;
}

void find_roots(int* gap, double x, double* roots)
{
	bool check = true;
	double pivot = 0, fx = 0, z = 0;
	int counter = 0, p = 0, d = 0;
	double y[3];
	for (int i = 0; i < 8; i++)
	{
		pivot = gap[i];
		x = pivot;
		double fx_0 = pow(x, 3) - pow(x, 2) * 5 + 12, fx_1 = pow(x, 2) * 3 - 10 * x, fx_2 = 6 * x - 10;
		z = fx_0 * fx_2;
		if (z > 0)
		{
			while (true)
			{
				pivot = pivot - (pow(x, 3) - pow(x, 2) * 5 + 12) / (pow(x, 2) * 3 - 10 * x);
				x = pivot;
				fx = pow(x, 3) - pow(x, 2) * 5 + 12;
				/////////////////////////////
				if (counter == 0 && fx > 0.00000000001)
				{
					check = true;
				}
				if (counter == 0 && fx < 0.00000000001)
				{
					check = false;
				}

				if (fx < 0.00000000001 && fabs(fx) > 0.00000000001 && check == false)
				{
					counter++;
					continue;
				}
				if (fabs(fx) < 0.00000000001 && check == false)
				{
					if (fx > 0.00000000001)
					{
						counter = 0;
						break;
					}
					else
					{
						counter = 0;
						y[d] = fx;
						roots[p] = x;
						p++;
						d++;
						break;
					}
				}
				if (fx > 0.00000000001 && check == true)
				{
					counter++;
					continue;
				}
				else
				{
					if (fabs(fx) > 0.00000000001)
					{
						counter = 0;
						break;
					}
					else
					{
						counter = 0;
						y[d] = fx;
						roots[p] = x;
						p++;
						d++;
						break;
					}
				}
			}
		}
		if (z == 0)
		{
			y[d] = fx;
			roots[p] = x;
			p++;
			d++;
			continue;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "y" << i + 1 << " = " << y[i] << endl;
		cout << "x" << i + 1 << " = " << roots[i] << endl;
		cout << endl << endl;
	}
}
