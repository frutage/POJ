#include<iostream>
using namespace std;

void flip(int left, int right, char* p) {
	int i = left, j = right;
		while(i < j) {
			char c = p[i];
			p[i] = p[j];
			p[j] = c;
			i++;
			j--;
		}
}
int main()
{
	char str[500];
	cin.getline(str, 500);
	int left = 0, right = -1;
	for (int i = 0; i < 500; i++) {
		if (str[i] == '\0') {
			//cout << left << " " << right << endl;
			flip(left, right, str);
			break;
		}
		else if (str[i] == ' ') {
			//cout << left << " " << right << endl;
			flip(left, right, str);
			left = i + 1;
			right = i;
		}
		else {
			right++;
		}
	}
	cout << str << endl;
	return 0;
}