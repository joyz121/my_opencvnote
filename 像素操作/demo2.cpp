#include<opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{

	Mat img = imread("C:/Users/Joy/Desktop/image/lena.jpg");
	//��ָ���������
	uchar* data1 = img.ptr(2);//dataָ��ڶ��еĵ�һ�����صĵ�ַ
	int data2 = img.ptr(2)[2];
	
	printf("%d\n", *data1);
	printf("%d\n", data1[2]);
	printf("%d", data2);

}