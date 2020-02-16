#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src, dst;
	src = imread("lena.jpg");
	if (src.empty())
	{
		cout << "could not load image" << endl;
	}
	//��ֵ�˲� �������ڶ�Ӧͼ���������ص�ƽ��ֵ��Ϊģ�����ĵ������ֵ
	blur(src, dst, Size(4,4 ), Point(-1, -1));
	imshow("��ֵ�˲�",dst);
	//��˹�˲� ��˹�ֲ�ģ�͸�Ȩ��
	GaussianBlur(src, dst, Size(5, 5), 5,5);
	imshow("��˹�˲�", dst);
	//��ֵ�˲�
	medianBlur(src, dst, 5);
	imshow("��ֵ�˲�",dst);
	//˫���˲�
	bilateralFilter(src,dst,5,100,3);
	imshow("˫���˲�",dst);
	waitKey(0);
	return 0;
}