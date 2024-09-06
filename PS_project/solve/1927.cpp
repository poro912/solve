#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int cmd;
		cin >> cmd;

		if (cmd == 0) {
			if (min_heap.empty())
				cout << 0 << "\n";
			else {
				cout << min_heap.top() << "\n";
				min_heap.pop();
			}
				
			continue;
		}
		min_heap.push(cmd);
	}
	
	cout.flush();
	return 0;
}

