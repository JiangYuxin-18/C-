#include <iostream>
#include <string>
using namespace std;

void invert(char a[]);

int main() {
	int n;//�������
	char a[10];

	cin >> n;

	for (int j = 0; j < n; j++) {
		for (int p = 0; p < 10; p++) {
			cin >> a[p];
		}
		invert(a);
	}

	return 0;
}

//ʹ��������ĺ���
void invert(char a[]) {
	for (int i = 9; i >= 0; i--) {
		cout << a[i];
	}
	cout << endl;
}