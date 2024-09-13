#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<vector<pair<int, int>>> tree;
	vector<int> visited;
	stack<pair<int,int>> vist;
	int root = 0;
	int n;

	cin >> n;

	tree = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());

	for (int i = 0; i < n - 1; i++) {
		int parent, child, vertax;
		cin >> parent >> child >> vertax;

		parent--;
		child--;
		tree[parent].push_back(make_pair(child, vertax));
		tree[child].push_back(make_pair(parent, vertax));
	}

	// 가장 깊은 노드 확인
	visited = vector<int>(n, false);
	pair<int,int> temp_node;
	int deepest_node = 0;
	int depth = 0;

	vist.push(make_pair(0,0));
	while (!vist.empty()){
		temp_node = vist.top();
		vist.pop();
		for()
	}
	


	// 가장 깊은 노드 에서 가장 먼 노드 확인
	visited = vector<int>(n, false);
	
	vist.push(deepest_node);


	cout.flush();
	return 0;
}



