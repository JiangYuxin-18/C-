/*ʵ�����󳤷��壨�����壩�����������
���ʾ����
����߷ֱ�Ϊ��***��***��***
���Ϊ��***
�����Ϊ��***   */
#include <iostream>
using namespace std;

class CRectangle{
		public:
			int l, w, h;//���εĳ����
			//��������ĺ���
			int Volume(){
				return l*w*h;
			}
			//���������ĺ���
			int SuperficialArea(){
				return (l * w + l * h + w * h) * 2;
			}
			//������ʼ���ĺ���
			void Init(int l_, int w_, int h_){
				l = l_; w = w_; h = h_;
			}
	};

int main(){
	int l, w, h;
	CRectangle r;//r��һ������
	cout << "��ʦ���ã���ӭʹ��" << endl << "���������볤��ߣ��м��ÿո�տ���" << endl;
	cin >> l >> w >> h;
	r.Init(l, w, h);
	cout << "����߷ֱ�Ϊ��" << l <<","<< w <<","<< h << endl << "���Ϊ��" << r.Volume() << endl << "�����Ϊ��" << r.SuperficialArea();
	return 0;
}