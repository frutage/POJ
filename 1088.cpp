
#include<iostream>
using namespace std;

int** memory;
short **arr;

int ski_from_high(int i, int j, int r, int c) {
	if (memory[i][j] > 0)
		return memory[i][j];
	int a[4] = { 0,0,0,0 };
	bool flag = false;
	if (j + 1 < c && arr[i][j + 1] < arr[i][j]) {
		a[0] = ski_from_high(i, j + 1, r, c);
		flag = true;
	}
	if (i + 1 < r && arr[i + 1][j] < arr[i][j]) {
		a[1] = ski_from_high(i + 1, j, r, c);
		flag = true;
	}
	if (i - 1 >= 0  && arr[i - 1][j] < arr[i][j]) {
		a[2] = ski_from_high(i - 1, j, r, c);
		flag = true;
	}
	if (j - 1 >= 0 && arr[i][j - 1] < arr[i][j]) {
		a[3] = ski_from_high(i, j - 1, r, c);
		flag = true;
	}
	if (!flag)
		return 1;
	int max_len = a[0];
	for (int i = 1; i < 4; i++)
		if (a[i] > max_len)
			max_len = a[i];
	memory[i][j] = max_len + 1;
	return max_len + 1;
}

int main()
{
	int r = 0, c = 0;
	cin >> r >> c;
	arr = (short**)malloc(sizeof(short*)*r);
	memory = (int**)malloc(sizeof(int*)*r);
	for (int i = 0; i < r; i++) {
		arr[i] = (short*)malloc(sizeof(short)*c);
		memory[i] = (int*)malloc(sizeof(int)*c);
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			memory[i][j] = 0;
		}
	int ski_len = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			bool flag = false;
			if (j + 1 < c && arr[i][j + 1] > arr[i][j])
				flag = true;
			if (i + 1 < r && arr[i + 1][j] > arr[i][j])
				flag = true;
			if (i - 1 >= 0 && arr[i - 1][j] > arr[i][j])
				flag = true;
			if (j - 1 >= 0 && arr[i][j - 1] > arr[i][j])
				flag = true;
			if (!flag) {
				//cout << i << " " << j << "" << arr[i][j] << endl;
				int num = ski_from_high(i, j, r, c);
				if (num > ski_len)
					ski_len = num;
			}
		}
	cout << ski_len << endl;
	return 0;
}