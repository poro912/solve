#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;
// 상 우 하 좌
int dx[] = {0, 1, 0, -1};
int dy[] = { -1, 0, 1, 0 };

int x = 0, y = 0;

void print(vector<vector<int>> &box);
void bfs(vector<vector<int>>& box);
bool is_inside(int t_y, int t_x);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<vector<int>> box;
	int t;
	int count = 0;
	cin >> x >> y;

	box = vector<vector<int>>(y, vector<int>(x, -1));

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> t;
			box[i][j] = t;
		}
	}

	bfs(box);

	for (const auto& line : box) {
		for (const auto& cell : line) {
			if (count < cell) count = cell;
			if (cell == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << count-1;
	return 0;
}

void print(vector<vector<int>>& box) {
	for (const auto& line : box) {
		for (const auto& cell : line) {
			cout << cell << " ";
		}
		cout << "\n";
	}
	cout << endl;
}

void bfs(vector<vector<int>>& box) {
	queue<pair<int, int>> tomato_queue;
	pair<int, int> point;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (1 == box[i][j]) tomato_queue.push(make_pair(i, j));
		}
	}

	while (!tomato_queue.empty()) {
		int t_y, t_x;
		
		point = tomato_queue.front();
		tomato_queue.pop();

		t_y = point.first;
		t_x = point.second;
		//cout << "y :" << point.first << "x :" << point.second << "\n";

		for (int i = 0; i < 4; i++) {
			

			if (!is_inside(t_y + dy[i], t_x + dx[i]))continue;
			if (0 != box[t_y + dy[i]][t_x + dx[i]]) continue;

			tomato_queue.push(make_pair(t_y + dy[i], t_x + dx[i]));
			box[t_y + dy[i]][t_x + dx[i]] = box[t_y][t_x] + 1;
		}
	}
}

bool is_inside(int t_y, int t_x) {
	if (t_x < 0) return false;
	if (t_y < 0) return false;
	if (x <= t_x) return false;
	if (y <= t_y) return false;
	return true;
}