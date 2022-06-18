#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define ROWS 6
#define COLS 6

enum COLOR { RED = 0, YELLOW = 1, GREEN = 2 };
enum TRAVERSAL {DFS, BFS};

struct graph {
	int key;
	COLOR color;
};
void traverseGraph(int arr[][COLS], TRAVERSAL t) {
	graph vertices[ROWS];
	for (int i = 0;i < ROWS;i++) {
		vertices[i].key = i;
		vertices[i].color = RED;
	}
	switch (t)
	{
	case DFS:
	{
		stack<graph> s;
		s.push(vertices[0]);
		vertices[0].color = YELLOW;
		while (!s.empty()) {
			int k = s.top().key;
			s.pop();
			vertices[k].color = GREEN;
			for (int i = 0;i < COLS;i++) {
				if (arr[k][i] == 1 && vertices[i].color == RED) {
					s.push(vertices[i]);
					vertices[i].color = YELLOW;
				}
			}
			cout << "V" << k << "\t";
		}
		cout << endl;
	}
		break;
	case BFS:
	{
		queue<graph> q;
		q.push(vertices[0]);
		vertices[0].color = YELLOW;
		while (!q.empty()) {
			int k = q.front().key;
			q.pop();
			vertices[k].color = GREEN;
			for (int i = 0;i < COLS;i++) {
				if (arr[k][i] == 1 && vertices[i].color == RED) {
					q.push(vertices[i]);
					vertices[i].color = YELLOW;
				}
			}
			cout << "V" << k << "\t";
		}
		cout << endl;
	}
		break;
	default:
		break;
	}
}
int main() {
	int paths[ROWS][COLS] = { {0,1,1,0,0,1},{1,0,0,1,0,0},{0,0,0,1,1,0},{1,0,0,1,1,0},{0,0,0,0,0,0},{0,0,1,0,0,0} };
	traverseGraph(paths, DFS);
	traverseGraph(paths, BFS);
	return 0;
}