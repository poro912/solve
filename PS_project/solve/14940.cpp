#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;
// 상 우 하 좌
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int y, x;

void bfs(vector<vector<int>>& map, pair<int, int>& start);
void print(vector<vector<int>> &map);
bool is_inside(int t_y, int t_x);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> map;
	pair<int, int> point;
	int t;

	cin >> y >> x;
	map = vector<vector<int>>(y, vector<int>(x, -1));

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> t;
			if(t == 0) map[i][j] = 0;
			if (t == 2) {
				point = make_pair(i, j);
				map[i][j] = 0;
			}
		}
	}
	//print(map);
	bfs(map, point);
	print(map);
	cout << endl;
	return 0;
}


void bfs(vector<vector<int>>& map, pair<int, int>& start) {
	queue<pair<int, int>> bfs_queue;
	pair<int, int> now;
	
	int t_y, t_x;

	bfs_queue.push(start);
	
	while (!bfs_queue.empty()) {
		now = bfs_queue.front();
		bfs_queue.pop();

		t_y = now.first;
		t_x = now.second;

		for (int i = 0; i < 4; i++) {
			if (!is_inside(t_y + dy[i], t_x + dx[i])) continue;
			if (-1 != map[t_y + dy[i]][t_x + dx[i]]) continue;
			//if (0 == map[t_y + dy[i]][t_x + dx[i]]) continue;

			map[t_y + dy[i]][t_x + dx[i]] = map[t_y][t_x] + 1;
			bfs_queue.push(make_pair(t_y + dy[i], t_x + dx[i]));
		}
	}
}

void print(vector<vector<int>>& map) {
	for (const auto& line : map) {
		for (const auto& cell : line) {
			cout << cell << " ";
		}
		cout << "\n";
	}
}

bool is_inside(int t_y, int t_x) {
	if (t_x < 0) return false;
	if (t_y < 0) return false;
	if (x <= t_x) return false;
	if (y <= t_y) return false;
	return true;
}