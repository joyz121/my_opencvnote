#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//ȫ�ֱ�������
Mat srcImage, dstImage,dstImage2,dstImage3,dstImage4;
int g_nMeanBulrValue = 3;
int g_nGaussianBulrValue = 3;
int g_nMedianBlurValue = 5;
int g_nBilateralFilterValue = 6;

//�ص���������
static void on_Meanblur(int,void*);
static void on_GaussianBulr(int, void*);
static void on_MedianBlur(int, void*);
static void on_BilateralFilter(int, void*);

int main()
{
	srcImage = imread("lena.jpg");
	if (srcImage.empty())
	{
		cout << "could not load image" << endl;
	}
	namedWindow("��ֵ�˲�", 1);
	createTrackbar("�ں�ֵ","��ֵ�˲�",&g_nMeanBulrValue,40,on_Meanblur);
	on_Meanblur(g_nMeanBulrValue,0);
	
	namedWindow("��˹�˲�",1);
	createTrackbar("�ں�ֵ", "��˹�˲�", &g_nGaussianBulrValue, 40, on_GaussianBulr);
	on_GaussianBulr(g_nGaussianBulrValue,0);

	namedWindow("��ֵ�˲�", 1);
	createTrackbar("�ο�ֵ", "��ֵ�˲�", &g_nMedianBlurValue, 40, on_MedianBlur);
	on_MedianBlur(g_nMedianBlurValue,0);

	namedWindow("˫���˲�",1);
	createTrackbar("�ο�ֵ", "˫���˲�", &g_nBilateralFilterValue, 50, on_BilateralFilter);
	on_BilateralFilter(g_nBilateralFilterValue,0);
	waitKey(0);
	return 0;
}



//====================�����˲�======================//
static void on_Meanblur(int, void*)
{
	blur(srcImage, dstImage, Size(g_nMeanBulrValue + 1, g_nMeanBulrValue + 1), Point(-1, -1));
	imshow("��ֵ�˲�", dstImage);
}
static void on_GaussianBulr(int, void*)
{
	GaussianBlur(srcImage, dstImage2, Size(g_nGaussianBulrValue * 2 + 1, g_nGaussianBulrValue * 2 + 1), 0, 0);
	imshow("��˹�˲�", dstImage2);
}
//====================�������˲�======================//
static void on_MedianBlur(int, void*)
{
	//���������������Ǵ���1������
	medianBlur(srcImage, dstImage3, g_nMedianBlurValue * 2 + 1);
	imshow("��ֵ�˲�", dstImage3);
}
static void on_BilateralFilter(int, void*)
{
	bilateralFilter(srcImage, dstImage4, g_nBilateralFilterValue, g_nBilateralFilterValue * 2, g_nBilateralFilterValue / 2);
	imshow("˫���˲�", dstImage4);
}