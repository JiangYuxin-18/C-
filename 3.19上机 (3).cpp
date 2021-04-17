#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int x = 0, y = 0;//行数和列数

    int a[50][50];

    cin >> x >> y;//输入行数和列数
    //输入矩阵
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> a[i][j];
        }
    }
    int flag = 0;
    //找出行最大的数以及所在列
    for (int i = 0; i < x; i++) {
        int max = a[i][0];
        int maxCol = 0;
        for (int j = 1; j < y; j++) {
            if (max < a[i][j]) {
                max = a[i][j];
                maxCol = j;
            }
        }
        //找出行最大数所在列中的最小数
        int min = a[0][maxCol];
        for (int k = 0; k < x; k++) {
            if (min > a[k][maxCol])
                min = a[k][maxCol];
        }
        //判断行最大数是否与列最小数相等
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