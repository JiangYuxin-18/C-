#include <iostream>
#include <cstring>
using namespace std;

void insert(char str[], char x);
int main() {
	char str[100]; //������ַ���
	char x;        //Ҫ������ַ�
	
	cin >> str;
	cin >> x;
	
	insert(str, x);
	
	return 0;
}

//�����ַ��ĺ���
void insert(char str[], char x) {
	char temp[100]={0}; //д���µ��ַ���
	
	for (int i = 0; i <= strlen(str); i++) {
		temp[2*i] = str[i];
	}
	for (int j = 1; j < 2*strlen(str); j += 2) {
		temp[j] = x;
	}
	
	cout << temp;
}
