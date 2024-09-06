#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define PLUCKED 0
#define PLANTED 1

using namespace std;

//			상 우 하 좌
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void cabbage();
int BFS(vector<vector<int>>& map, int x_size, int y_size);
void BFS_checking(vector<vector<int>>& map, int x_size, int y_size, int x, int y);
bool is_inside(int x, int y, int t_x, int t_y);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cabbage();
	}
	
	cout.flush();
	return 0;
}

void cabbage() {
	vector<vector<int>> map;
	int x, y, planted;
	cin >> x >> y >> planted;

	map = vector<vector<int>>(y, vector<int>(x, PLUCKED));

	for (int i = 0; i < planted; i++) {
		int x, y;
		cin >> x >> y;
		map[y][x] = PLANTED;
	}


	cout << BFS(map, x, y) << "\n";

	/*for (const auto i : map) {
		for (const auto t : i) {
			cout << t << " ";
		}
		cout << "\n";
	}*/
}

int BFS(vector<vector<int>>& map, int x_size, int y_size) {
	int result = 0;
	for (int y = 0; y < y_size; y++) {
		for (int x = 0; x < x_size; x++) {
			if (PLANTED == map[y][x]) {
				result++;
				BFS_checking(map, x_size, y_size, x, y);
			}
		}
	}
	return result;
}

void BFS_checking(vector<vector<int>>& map, int x_size, int y_size, int x, int y) {
	queue<pair<int, int>> bfs_queue;

	map[y][x] = PLUCKED;
	bfs_queue.push(make_pair(y, x));

	while (!bfs_queue.empty()) {
		pair<int, int> point = bfs_queue.front();
		int t_x, t_y;
		bfs_queue.pop();

		for (int i = 0; i < 4; i++) {
			t_y = point.first + dy[i];
			t_x = point.second + dx[i];
			if (!is_inside(x_size, y_size, t_x, t_y)) continue;
			if (PLANTED != map[t_y][t_x]) continue;

			bfs_queue.push(make_pair(t_y, t_x));
			map[t_y][t_x] = PLUCKED;
		}
	}
}


// x, y 전역변수
// t_y, t_x가 map 내부 좌표인가?
bool is_inside(int x, int y, int t_x, int t_y) {
	if (t_x < 0) return false;
	if (t_y < 0) return false;
	if (x <= t_x) return false;
	if (y <= t_y) return false;
	return true;
}