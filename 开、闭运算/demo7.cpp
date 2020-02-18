#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("lena.jpg");
	Mat dstImage;	
	Mat element = getStructuringElement(MORPH_OPEN, Size(15, 15));
	
	//�����㡪���ȸ�ʴ��������(����С����)
	morphologyEx(srcImage,dstImage,MORPH_OPEN,element);
	imshow("������",dstImage);
	
	//�����㡪�������ͣ��ٸ�ʴ(�ų�С�ĺ�ɫ����)
	morphologyEx(srcImage, dstImage, MORPH_CLOSE, element);
	imshow("������", dstImage);

	//��̬ѧ�ݶȡ�������ͼ�͸�ʴͼ�Ĳ�(��Եͻ��)
	morphologyEx(srcImage, dstImage, MORPH_GRADIENT, element);
	imshow("��̬ѧ�ݶ�", dstImage);
	
	//��ñ����ԭͼ�뿪����Ĳ�(��������/������ȡ��
	morphologyEx(srcImage, dstImage, MORPH_TOPHAT , element);
	imshow("��ñ", dstImage);
	
	//��ñ����ԭͼ�������Ĳ���밵��/������ȡ��
	morphologyEx(srcImage, dstImage, MORPH_BLACKHAT, element);
	imshow("��ñ", dstImage);
	waitKey(0);
	return 0;
}