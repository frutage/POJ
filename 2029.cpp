#include<iostream>
using namespace std;

void insert(char *p) {
	int i = 0; 
	for (; i < 40; i++)
		if (p[i] == '\0')
			break;
	p[2 * i - 1] = '\0';
	for (int j = 2 * i - 2; j >= 0; j--)
		if (j % 2 == 0)
			p[j] = p[j / 2];
		else
			p[j] = ' ';
}
int main()
{
	char buf[40];
	while (cin.getline(buf, 40, '\n')) {
		insert(buf);
		cout << buf << endl;
	}
	return 0;
}