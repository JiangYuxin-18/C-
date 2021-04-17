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
  		cout << "��ǰ�Ĵ�������Ϊ��" << bookNumber << endl;
 	}
 	void restore() {
 		bookNumber++;
  		cout << "��ǰ�Ĵ�������Ϊ��" << bookNumber << endl;
 	}
	
private:
	string bookName;
	string author;
	float price;
	int bookNumber;
};

int main() {
	
 	Book book("Little Prince","�����",9.98,100);
 	cout << "��ʦ���ã���ӭʹ�ã�" << endl;
 	cout << "����������������ܶ�Ӧ����ĸ��bΪ���ģ�rΪ���飬s��ʾ����������:" << endl;
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
