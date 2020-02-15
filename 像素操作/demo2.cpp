#include<opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{

	Mat img = imread("C:/Users/Joy/Desktop/image/lena.jpg");
	//用指针操作像素
	uchar* data1 = img.ptr(2);//data指向第二行的第一个像素的地址
	int data2 = img.ptr(2)[2];
	
	printf("%d\n", *data1);
	printf("%d\n", data1[2]);
	printf("%d", data2);

}