#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Book {
public:
	
	Book(string bookName,string author,float price,int bookNumber):bookName(bookName),author(author),price(price),bookNumber(bookNumber){
		
	}
	void display() {
  		cout << bookName << endl << author << endl << price << endl << bookNumber << endl;
 	}
 	void borrow() {
 		bookNumber--;
  		cout << "当前的存书数量为：" << bookNumber << endl;
 	}
 	void restore() {
 		bookNumber++;
  		cout << "当前的存书数量为：" << bookNumber << endl;
 	}
	
private:
	string bookName;
	string author;
	float price;
	int bookNumber;
};

int main() {
	
 	Book book("Little Prince","江雨歆",9.98,100);
 	cout << "老师您好，欢迎使用！" << endl;
 	cout << "请输入您所需服务功能对应的字母（b为借阅，r为还书，s显示存书数量）:" << endl;
 	char x = '0';
 	cin >> x;
 	while (x != 'e') {
 		
  		if (x == 'b') {
   			book.borrow();
  		}
  		else if (x == 'r') {
   			book.restore();
  		}
  		else if (x == 's') {
   			book.display();
  		}	
  		cin >> x;
 	}
 	return 0;
}
