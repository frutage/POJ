#include<iostream>
using namespace std;
int main()
{
	int n, a, b, c, d, e, f, x, y;
	//x 表示1×1的空位数目
	//y 表示2×2的空位数目
	int u[4] = { 0, 5, 3, 1 };
	//表示3×3的产品分别是4k, 4k+1, 4k+2, 4k+3时
	//为3×3产品打开的新箱子中，剩余2×2的空位数
	while (cin >> a) {
		cin >> b >> c >> d >> e >> f;
		if (a + b + c + d + e + f == 0)
			break;
		n = f + e + d + c / 4;
		if (c % 4 != 0)
			n++;
		y = 5 * d + u[c % 4];
		if (b>y) {
			n += (b - y) / 9;
			if ((b - y) % 9 != 0)
				n++;
		}
		x = 36 * n - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b; //x是现在所有的箱子中，剩下的1×1的位置
		if (a>x)
		{
			n += (a - x) / 36;
			if ((a - x) % 36 != 0)
				n++;
		}

		printf("%d\n", n);
	}
	return 0;
}