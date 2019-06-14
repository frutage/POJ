#include <iostream>
#include<string>
#include<map>
using namespace std;

int getNum(char c) {
	if (c >= 'A' && c < 'Q')
		return (c - 'A') / 3 + 2 + '0';
	else if (c > 'Q' && c < 'Z')
		return (c - 1 - 'A') / 3 + 2 + '0';
	else
		return c;
}
int main()
{
	int n = 0;
	string s;
	bool flag = false;
	map<string, int> cont;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int cur = 0;
		string number = "000-0000";
		for (auto c : s) {
			if (c == '-')
				continue;
			else {
				if (cur == 3)
					cur++;
				number[cur++] = getNum(c);
			}
		}
		if (cont.find(number) != cont.end()) {
			flag = true;
			cont[number] += 1;
		}
		else
			cont[number] = 1;
	}
	if (!flag)
		cout << "No duplicates.\n";
	else {
		for (auto pair : cont) {
			if (pair.second >= 2)
				cout << pair.first << " " << pair.second << endl;
		}
	}
	return 0;
}
