#include<iostream>
using namespace std;

int main()
{
	short col = 0;
	cin >> col;
	char str[200];
	cin >> str;
	int cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	int row = cnt / col;
	int cur = 0;
	bool flag = true;
	char** p= (char**)malloc(sizeof(char*)*row);
	for (int i = 0; i < row; i++) {
		p[i] = (char*)malloc(col);
		if (flag) {
			for (int j = 0; j < col; j++)
				p[i][j] = str[cur++];
			flag = false;
		}
		else {
			for (int j = 0; j < col; j++)
				p[i][j] = str[cur + col -1 - j];
			cur += col;
			flag = true;
		}
	}
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			cout << p[j][i];
	cout << endl;
	return 0;
}