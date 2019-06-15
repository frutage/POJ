#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> dict;
vector<string> sim;

bool checkSim(string shortstr, string longstr) {
	short flag = 0;
	for (int i = 0, j = 0; i < longstr.size();) {
		if (shortstr[j] == longstr[i])
			i++, j++;
		else if (flag == 0)
			i++, flag = 1;
		else {
			flag = 2;
			break;
		}
	}
	if (flag == 1)
		return true;
	else
		return false;
}
 void findSim(string s) {
	 for (auto w : dict) {
		 int size1 = w.size();
		 int size2 = s.size();
		 if (size1 == size2) {
			 int diff = 0;
			 for (int i = 0; i < size1; i++) {
				 if (w[i] != s[i])
					 diff += 1;
				 if (diff >= 2)
					 break;
			 }
			 if (diff == 1)
				 sim.push_back(w);
		 }
		 else if (size1==size2+1) {
			 if (checkSim(s, w))
				 sim.push_back(w);
		 }
		 else if (size2 == size1 + 1) {
			 if (checkSim(w, s))
				 sim.push_back(w);
		 }
	 }
}
int main()
{
	bool flag = false;
	string s;
	while (cin >> s) {
		if (s == "#")
			if (!flag) {
				flag = true;
				continue;
			}
			else
				break;
		if (!flag)
			dict.push_back(s);
		else {
			if (find(dict.begin(), dict.end(), s) != dict.end())
				cout << s << " is correct\n";
			else {
				findSim(s);
				cout << s << ":";
				for (int i = 0; i < sim.size(); i++)
					cout << " " << sim[i];
				cout << endl;
				sim.clear();
			}
		}

	}
}