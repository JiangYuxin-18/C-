#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int x = 0, y = 0;//����������

    int a[50][50];

    cin >> x >> y;//��������������
    //�������
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> a[i][j];
        }
    }
    int flag = 0;
    //�ҳ����������Լ�������
    for (int i = 0; i < x; i++) {
        int max = a[i][0];
        int maxCol = 0;
        for (int j = 1; j < y; j++) {
            if (max < a[i][j]) {
                max = a[i][j];
                maxCol = j;
            }
        }
        //�ҳ���������������е���С��
        int min = a[0][maxCol];
        for (int k = 0; k < x; k++) {
            if (min > a[k][maxCol])
                min = a[k][maxCol];
        }
        //�ж���������Ƿ�������С�����
        if (max == min) {
            cout << max;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << "no";
    }
    return 0;
}