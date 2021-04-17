#include <iostream>
#include <cstring>
using namespace std;

void insert(char str[], char x);
int main() {
	char str[100]; //输入的字符串
	char x;        //要插入的字符
	
	cin >> str;
	cin >> x;
	
	insert(str, x);
	
	return 0;
}

//插入字符的函数
void insert(char str[], char x) {
	char temp[100]={0}; //写入新的字符串
	
	for (int i = 0; i <= strlen(str); i++) {
		temp[2*i] = str[i];
	}
	for (int j = 1; j < 2*strlen(str); j += 2) {
		temp[j] = x;
	}
	
	cout << temp;
}
