#include<iostream>
using namespace std;
#include<string>
#include<math.h>



//// ����1��
//// �����������(Cube)
//// ���ԣ�������(m_L)����(m_W)����(m_H)
//// ���������������������������
//// �ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
//
//
//class Cube
//{
//private:
//	double n_L;
//	double n_W;
//	double n_H;
//
//public:
//	void setInfo(double a, double b, double c) {// ������������Ϣ
//		n_L = a;
//		n_W = b;
//		n_H = c;
//	}
//	
//	double* getInfo() {// ���ش����������Ϣ�Ķ�������
//		double* arr = new double[3];
//		arr[0] = n_L;
//		arr[1] = n_W;
//		arr[2] = n_H;
//		return arr;
//	}
//
//	double getV() {// ���س��������
//		return  n_L * n_W * n_H;
//	}
//
//	double getS() {// ���س��������
//		return 2 * n_L * n_W + 2 * n_W * n_H + 2 * n_L * n_H;
//	}
//
//	int isSame1(Cube& c1) {// �жϱ�������ʹ��������������Ƿ���ȣ���ȷ���1�����ȷ���0
//		double* arr = c1.getInfo();
//		if (arr[0] == n_L && arr[1] == n_W && arr[2] == n_H) {
//			delete[] arr;
//			return 1;
//		}
//		else {
//			delete[] arr;
//			return 0;
//		}
//	}
//};
//
//
//// �ж����������Ƿ���ȣ���ȷ���1�����ȷ���0
//int isSame2(Cube& c1, Cube& c2)// ���������Ƽ����ô��Σ�ʡ�ռ�
//{
//	double* arr1 = c1.getInfo();
//	double* arr2 = c2.getInfo();
//	for (int i = 0; i < 3; i++) {
//		if (arr1[i] != arr2[i]) {
//			delete[] arr1;
//			delete[] arr2;
//			return 0;
//		}
//	}
//	delete[] arr1;
//	delete[] arr2;
//	return 1;
//}
//
//
//int main()
//{
//	// �������������
//	Cube c1;
//	Cube c2;
//
//	// ���������峤���
//	c1.setInfo(1, 2, 3);
//	c2.setInfo(3, 2, 1);
//
//	// ��ӡ������c1��Ϣ
//	cout << "c1��Ϣ��";
//	double* arr1 = c1.getInfo();
//	for (int i = 0; i < 3; i++) {
//		cout << arr1[i] << " ";
//	}
//	cout << endl;
//
//	// ��ȡ������c1��������
//	cout << "c1�����" << c1.getS() << endl;
//	cout << "c1�����" << c1.getV() << endl;
//
//	// �ж����������Ƿ���ȣ�ȫ�ֺ����ͳ�Ա�����ֱ��жϣ�
//	cout << (isSame2(c1, c2) ? "���" : "�����") << endl;
//	cout << (c1.isSame1(c2) ? "���" : "�����") << endl;
//	
//	// �ͷŶ�������ռ�
//	delete[] arr1;
//
//	return 0;
//}








//// ����2
//// ���һ�����࣬���԰���xy����
//// ���һ��Բ�࣬���԰���Բ�ĺͰ뾶��������һ���жϵ��Բ��ϵ�ĳ�Ա����
//
//
//class Point
//{
//private:
//	double x;
//	double y;
//
//public:
//	void setX(double a) { x = a; }
//	double getX() { return x; }
//	void setY(double a) { y = a; }
//	double getY() { return y; }
//};
//
//
//class Circle
//{
//private:
//	int r;// �뾶
//	Point center;// Բ�ģ�һ��������������һ����ĳ�Ա��
//public:
//
//	void setR(double a) { r = a; }
//	double getR() { return r; }
//	void setCenter(Point& p) { center = p; }
//	Point getCenter() { return center; }
//
//	void PoiCirRelation(Point& a) {
//		double d = pow(a.getX() - center.getX(), 2) + pow(a.getY() - center.getY(), 2);
//		if (d > pow(r, 2))
//			cout << "����Բ��" << endl;
//		else if (d == pow(r, 2))
//			cout << "����Բ��" << endl;
//		else
//			cout << "����Բ��" << endl;
//	}
//};
//
//int main()
//{
//	Circle c;
//	Point center;
//	center.setX(3);
//	center.setY(4);
//	c.setCenter(center);
//	c.setR(5);
//
//	Point p;
//	p.setX(0);
//	p.setY(0);
//	c.PoiCirRelation(p);// ����Բ��
//
//	p.setX(1);
//	p.setY(1);
//	c.PoiCirRelation(p);// ����Բ��
//
//	p.setX(-1);
//	p.setY(-1);
//	c.PoiCirRelation(p);// ����Բ��
//	
//
//	return 0;
//}



