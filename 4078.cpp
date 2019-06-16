#include<iostream>
#include<vector>
using namespace std;

vector<int> minHeap;

void sif_down() {
	int j = 0;
	int i = j * 2 + 1;
	while (i < minHeap.size()) {
		if (i < minHeap.size() - 1 && minHeap[i + 1] < minHeap[i])
			i++;
		if (minHeap[j] > minHeap[i]) {
			int tmp = minHeap[j];
			minHeap[j] = minHeap[i];
			minHeap[i] = tmp;
			j = i;
			i = 2 * i + 1;
		}
		else
			break;
	}
}

void sif_up() {
	int i = minHeap.size() - 1;
	int j = (i - 1) / 2;
	while (i > 0) {

		if (minHeap[j] <= minHeap[i])
			break;
		int tmp = minHeap[j];
		minHeap[j] = minHeap[i];
		minHeap[i] = tmp;
		i = j;
		j = (j - 1) / 2;
	}
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		short type = 0;
		cin >> type;
		if (type == 1) {
			int u = 0;
			cin >> u;
			minHeap.push_back(u);
			sif_up();
		}
		else {
			cout << minHeap[0] << endl;
			minHeap[0] = minHeap[minHeap.size() - 1];
			minHeap.pop_back();
			sif_down();
		}
	}
	return 0;
}