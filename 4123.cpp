#include <iostream>
using namespace std;
int m = 0, n = 0;
int cntPos(bool **arr, int x, int y, int cnt) 
{
	arr[x][y] = true;
	cnt += 1;
	if (cnt == m * n) {
		arr[x][y] = false;
		return 1;
	}
	else {
		int res = 0;
		if (x + 1 < m && y + 2 < n && !arr[x+1][y+2])
			res += cntPos(arr, x + 1, y + 2, cnt);
		if (x + 2 < m && y + 1 < n && !arr[x+2][y+1])
			res += cntPos(arr, x + 2, y + 1, cnt);
		if (x - 1 >= 0 && y - 2 >= 0 && !arr[x-1][y-2])
			res += cntPos(arr, x - 1, y - 2, cnt);
		if (x - 2 >= 0 && y - 1 >= 0 && !arr[x - 2][y - 1])
			res += cntPos(arr, x - 2, y - 1, cnt);
		if (x + 1 < m && y - 2 >= 0 && !arr[x+1][y-2])
			res += cntPos(arr, x + 1, y - 2, cnt);
		if (x + 2 < m && y - 1 >= 0 && !arr[x+2][y-1])
			res += cntPos(arr, x + 2, y - 1, cnt);
		if (x - 1 >= 0 && y + 2 < n && !arr[x-1][y+2])
			res += cntPos(arr, x - 1, y + 2, cnt);
		if (x - 2 >= 0 && y + 1 < n && !arr[x-2][y+1])
			res += cntPos(arr, x - 2, y + 1, cnt);
		arr[x][y] = false;
		return res;
	}
}

int main() 
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x = 0, y = 0;
		cin >> m >> n >> x >> y;
		bool** arr = (bool **)malloc(sizeof(bool *) * m);
		for (int j = 0; j < m; j++)
			arr[j] = (bool *)malloc(sizeof(bool) * n);
		for (int p = 0; p < m; p++)
			for (int k = 0; k < n; k++)
				arr[p][k] = false;
		cout << cntPos(arr, x, y, 0) << endl;
	}
	return 0;
}