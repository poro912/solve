#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int& start, int& end);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start, end;
	int result = 0;
	cin >> start >> end;
	
	cout << bfs(start, end);

	cout << endl;
	return 0;
}


int bfs(int& start, int& end) {
	vector<int> check_map = vector<int>(300001, -1); // 0.7mb
	queue<int> wait_queue;

	int t = -1;
	int max = start ? start : 1;
	while (max <= end) {
		max = max * 2;
	}

	wait_queue.push(start);
	check_map[start] = 0;

	//while (t != end) {
	while(check_map[end] == -1){
		t = wait_queue.front();
		wait_queue.pop();
		if (check_map[end] != -1) break;
		if (t * 2 <= max) {
			if (check_map[t * 2] == -1) {
				wait_queue.push(t * 2);
				check_map[t * 2] = check_map[t] + 1;
			}
		}
		if (t + 1 <= max) {
			if (check_map[t + 1] == -1) {
				wait_queue.push(t + 1);
				check_map[t + 1] = check_map[t] + 1;
			}
		}
		if (0 <= t - 1) {
			if (check_map[t - 1] == -1) {
				wait_queue.push(t - 1);
				check_map[t - 1] = check_map[t] + 1;
			}
		}
	}
	return check_map[end];
}