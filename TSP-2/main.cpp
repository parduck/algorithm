#include <iostream>
#include <cstring>
using namespace std;


int _n; // num
const int MAX_SIZE = 15; // �Է� ũ�⿡ ���� ����� (32 �̻� �� �� ����)
int _distance[MAX_SIZE][MAX_SIZE]; // _distance
int _memory[MAX_SIZE][1 << MAX_SIZE]; // for memoization



void getInput() {
	cin >> _n;
	for (int i = 0; i < _n; i++) {
		for (int j = 0; j < _n; j++) {
			cin >> _distance[i][j];
		}
	}
	memset(_memory, 0, sizeof(int) * MAX_SIZE * (1 << MAX_SIZE));
}


int tsp(int from, int toFlag) {
	int &memo = _memory[from][toFlag]; // _memory[][] �� 0 �� �ʱ�ȭ �Ǿ� �־�� ��.
	if (memo != 0) {
		return memo;
	}
	if (__builtin_popcount(toFlag) == 1) {
		int to = __builtin_ctz(toFlag);
		return _distance[from][to];
	}

	memo = INT_MAX; // �׳� ����� ū ���� ����ص� �ȴ�
	for (int i = 0; i < _n /* the nuber of cities */; i++) {
		if (!(toFlag & (1 << i))) continue;

		int v = _distance[from][i] + tsp(i, (toFlag & ~(1 << i)));
		memo = min(memo, v);
	}
	return memo;
}

int main() {
	getInput();
	int m = INT_MAX;
	int allFlag = (1 << _n) - 1;
	for (int i = 0; i < _n; i++) {
		int v = tsp(i, allFlag & ~(1 << i));
		m = min(m, v);
	}
	cout << m << endl;
	return 0;
}