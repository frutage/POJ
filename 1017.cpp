#include<iostream>
using namespace std;
int main()
{
	int n, a, b, c, d, e, f, x, y;
	//x ��ʾ1��1�Ŀ�λ��Ŀ
	//y ��ʾ2��2�Ŀ�λ��Ŀ
	int u[4] = { 0, 5, 3, 1 };
	//��ʾ3��3�Ĳ�Ʒ�ֱ���4k, 4k+1, 4k+2, 4k+3ʱ
	//Ϊ3��3��Ʒ�򿪵��������У�ʣ��2��2�Ŀ�λ��
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
		x = 36 * n - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b; //x���������е������У�ʣ�µ�1��1��λ��
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