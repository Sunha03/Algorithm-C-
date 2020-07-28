#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct NODE {
	int x;
	int y;
	int num;
	struct NODE* left;
	struct NODE* right;
} node;

vector<vector<int>> vec_nodes;
vector<vector<node>> layer;
vector<int> ans1, ans2;

bool cmp(const vector<int> &v1, const vector<int> &v2) {
	if (v1[1] == v2[1]) {
		return v1[0] < v2[0];
	}
	return v1[1] > v2[1];
}

void makeTree(int l_min, int r_max, node &now, int depth) {
	if (depth < layer.size() - 1) {
		depth++;
		for (int i = 0; i < layer[depth].size(); i++) {
			if (layer[depth][i].x >= l_min && layer[depth][i].x <= now.x - 1) {
				now.left = &layer[depth][i];
				makeTree(l_min, now.x - 1, layer[depth][i], depth);
			}
			else if (layer[depth][i].x >= now.x + 1 && layer[depth][i].x <= r_max) {
				now.right = &layer[depth][i];
				makeTree(now.x + 1, r_max, layer[depth][i], depth);
			}
		}

	}
}

void preorder(node now) {
	ans1.push_back(now.num);

	if (now.left != NULL) {
		preorder(*now.left);
	}
	if (now.right != NULL) {
		preorder(*now.right);
	}
}

void postorder(node now) {
	if (now.left != NULL) {
		postorder(*now.left);
	}
	if (now.right != NULL) {
		postorder(*now.right);
	}

	ans2.push_back(now.num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	node nodes[10001];
	vector<vector<int>> answer;

	for (int i = 0; i < nodeinfo.size(); i++) {
		nodeinfo[i].push_back({ i + 1 });
	}

	sort(nodeinfo.begin(), nodeinfo.end(), cmp);
	vec_nodes = nodeinfo;

	for (int i = 0; i < nodeinfo.size(); i++) {
		nodes[i].x = nodeinfo[i][0];
		nodes[i].y = nodeinfo[i][1];
		nodes[i].num = nodeinfo[i][2];
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}

	vector<node> v_node;
	for (int i = 0; i < nodeinfo.size() - 1; i++) {
		v_node.push_back({ nodes[i] });
		if (nodeinfo[i][1] != nodeinfo[i + 1][1]) {
			layer.push_back({ v_node });
			v_node.clear();

			if (i == nodeinfo.size() - 2) {
				layer.push_back({ nodes[i + 1] });
			}
		}

		if (i == nodeinfo.size() - 2 && nodeinfo[i][1] == nodeinfo[i + 1][1]) {
			v_node.push_back({ nodes[i + 1] });
			layer.push_back({ v_node });
		}
	}

	makeTree(0, 10000, nodes[0], 0);

	preorder(nodes[0]);
	postorder(nodes[0]);
	answer.push_back(ans1);
	answer.push_back(ans2);

	return answer;
}