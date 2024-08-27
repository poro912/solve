#include <iostream>

#include <math.h>
#include <algorithm>

#include <map>
#include <vector>
#include <stack>
#include <queue>	// queue priority_queue
#include <deque>
#include <tuple>
#include <set>

using namespace std;
//			�� �� �� ��
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

//			�»� �� ��� �� ���� �� ���� ��
int dy[] = { -1, -1, -1, 0, 1, 1, 1,  0 };
int dx[] = { -1,  0,  1, 1, 1, 0, -1, -1 };

int x, y;

// ���߹��� �ʱ�ȭ
vector<vector<int>> map;
map = vector<vector<int>>(y, vector<int>(x, 0));

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
}


// x, y ��������
// t_y, t_x�� map ���� ��ǥ�ΰ�?
bool is_inside(int t_y, int t_x) {
	if (t_x < 0) return false;
	if (t_y < 0) return false;
	if (x <= t_x) return false;
	if (y <= t_y) return false;
	return true;
}


// map print
void print(vector<vector<int>>& map) {
	for (const auto& line : map) {
		for (const auto& cell : line) {
			cout << cell << " ";
		}
		cout << "\n";
	}
	cout << endl;
}


sort(schedule.begin(), schedule.end(), compare);

// pair ���� second�� ���� �������� first�� ���� ��������
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

// ���� �� �ߺ�����
sort(unique_sort.begin(), unique_sort.end());
unique_sort.erase(unique(unique_sort.begin(), unique_sort.end()), unique_sort.end());