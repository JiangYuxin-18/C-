/*实现类求长方体（正方体）的体积表和面积
输出示例：
长宽高分别为：***，***，***
体积为：***
表面积为：***   */
#include <iostream>
using namespace std;

class CRectangle{
		public:
			int l, w, h;//矩形的长宽高
			//计算体积的函数
			int Volume(){
				return l*w*h;
			}
			//计算表面积的函数
			int SuperficialArea(){
				return (l * w + l * h + w * h) * 2;
			}
			//用来初始化的函数
			void Init(int l_, int w_, int h_){
				l = l_; w = w_; h = h_;
			}
	};

int main(){
	int l, w, h;
	CRectangle r;//r是一个对象
	cout << "老师您好，欢迎使用" << endl << "请依次输入长宽高，中间用空格空开：" << endl;
	cin >> l >> w >> h;
	r.Init(l, w, h);
	cout << "长宽高分别为：" << l <<","<< w <<","<< h << endl << "体积为：" << r.Volume() << endl << "表面积为：" << r.SuperficialArea();
	return 0;
}