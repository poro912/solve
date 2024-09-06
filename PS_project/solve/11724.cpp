#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

void bfs(map<int, vector<int>>& edge, vector<bool>& visited, int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count_vertax, count_edge;
	int result = 0;
	map<int, vector<int>> edge;
	vector<bool> visited;

	cin >> count_vertax >> count_edge;

	for (int i = 0; i < count_vertax; i++) {
		edge[i] = vector<int>();
	}
	visited = vector<bool>(count_vertax, false);

	for (int i = 0; i < count_edge; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int i = 0; i < visited.size(); i++) {
		if (!visited[i]) {
			result++;
			bfs(edge, visited, i);
		}
	}

	cout << result;
	cout.flush();
	return 0;
}

void bfs(map<int, vector<int>>& edge, vector<bool>& visited, int start) {
	queue<int> vertax_queue;
	int now = start;
	vertax_queue.push(start);
	visited[now] = true;

	while (!vertax_queue.empty()) {
		now = vertax_queue.front();
		vertax_queue.pop();

		for (const auto& target : edge[now]) {
			if (!visited[target]) {
				visited[target] = true;
				vertax_queue.push(target);
			}
		}
	}
}
