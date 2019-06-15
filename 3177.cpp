#include<iostream>
using namespace std;

int prime(int n) {
	if (n == 0)
		return 0;
	bool *arr = (bool*)malloc(sizeof(bool)*n);
	for (int i = 0; i < n; i++)
		arr[i] = true;
	arr[0] = false;
	for (int i = 2; i <= n / 2; i++) {
		int c = 2;
		while (c*i <= n) {
			arr[c*i - 1] = false;
			c++;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (arr[i])
			cnt += 1;
	return cnt;
}
int main()
{
	int m, n;
	while (cin >> m >> n) {
		int m2 = (m >= n) ? m : n;
		cout << prime(m2) - prime(m + n - m2 - 1) << endl;
	}
	return 0;
}