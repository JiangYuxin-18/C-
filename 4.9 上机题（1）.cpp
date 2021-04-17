#include <iostream>
using namespace std;

class ARR {
public:
	ARR(int x[], int size);//���캯��
	void change();//�������
	void show();//��������ֵ
private:
	int n;//����ʵ��Ԫ�ظ���
	int a[100];//��ʼʱ���ԭʼ���ݣ����մ�Ž����������
};

ARR::ARR(int x[], int size) {
	for (int i = 0; i < size; i++) {
		a[i] = x[i];
	}
	n = size;
}

void ARR::change() {
	int flag = 0;	
	for(int i = 0; i < n - flag; i++){
		if(a[i] >= 0){
			for(int j = n - 1 - flag; j > i; j--){
				flag++;
				if(a[j] < 0){
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					break;
				}
			}
			
		} 
	}

}

void ARR::show() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	cout << "��ʦ���ã���ӭʹ�ã�" << endl;
	int b[10] = { 1,-3,-1,3,2,4,-4,5,-5,-2 };
	ARR v(b, 10);
	
	v.show();
	v.change();
	v.show();
	return 0;
}