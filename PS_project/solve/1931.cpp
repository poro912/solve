#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, int>> schedule;
	int n;
	int result = 0;
	int i = 0, t = 0;
	cin >> n;

	schedule = vector<pair<int, int>>(n, make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> schedule[i].first >> schedule[i].second;
	}
	
	sort(schedule.begin(), schedule.end(), compare);
	
	while (i < n) {
		if (t <= schedule[i].first) {
			t = schedule[i].second;
			result++;
		}
		i++;
	}

	for (auto& i : schedule) {
		cout << i.first << " " << i.second << "\n";
	}
	cout << result;
	cout << endl;
	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}