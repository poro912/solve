#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define WHITE 0
#define BLUE 1

void split_count(int x, int y, int size, pair<int, int>& result);

vector<vector<int>> map;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	pair<int, int> result = make_pair(0, 0);

	cin >> size;

	map = vector<vector<int>>(size, vector<int>(size, 0));

	for (auto& t : map) {
		for (auto& i : t) {
			cin >> i;
		}
	}

	/*for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> map[i][j];
		}
	}*/


	split_count(0, 0, size, result);

	cout << result.first << endl;
	cout << result.second << endl;
	
	cout.flush();
	return 0;
}

void split_count(int x, int y, int size, pair<int,int> &result) {
	pair<int, int> temp_pair;
	int blue = 0, white = 0;
	int t;
	t = map[y][x];

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (t != map[i][j]) {
				int half = size / 2;
				split_count(x, y, half, result);
				split_count(x + half, y, half, result);
				split_count(x, y + half, half, result);
				split_count(x + half, y + half, half, result);
				return;
			}
		}
	}

	if (t == BLUE) result.second++;
	else result.first++;
}
