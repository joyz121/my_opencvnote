#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//全局变量声明
Mat srcImage, dstImage,dstImage2,dstImage3,dstImage4;
int g_nMeanBulrValue = 3;
int g_nGaussianBulrValue = 3;
int g_nMedianBlurValue = 5;
int g_nBilateralFilterValue = 6;

//回调函数声明
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
	namedWindow("均值滤波", 1);
	createTrackbar("内核值","均值滤波",&g_nMeanBulrValue,40,on_Meanblur);
	on_Meanblur(g_nMeanBulrValue,0);
	
	namedWindow("高斯滤波",1);
	createTrackbar("内核值", "高斯滤波", &g_nGaussianBulrValue, 40, on_GaussianBulr);
	on_GaussianBulr(g_nGaussianBulrValue,0);

	namedWindow("中值滤波", 1);
	createTrackbar("参考值", "中值滤波", &g_nMedianBlurValue, 40, on_MedianBlur);
	on_MedianBlur(g_nMedianBlurValue,0);

	namedWindow("双边滤波",1);
	createTrackbar("参考值", "双边滤波", &g_nBilateralFilterValue, 50, on_BilateralFilter);
	on_BilateralFilter(g_nBilateralFilterValue,0);
	waitKey(0);
	return 0;
}



//====================线性滤波======================//
static void on_Meanblur(int, void*)
{
	blur(srcImage, dstImage, Size(g_nMeanBulrValue + 1, g_nMeanBulrValue + 1), Point(-1, -1));
	imshow("均值滤波", dstImage);
}
static void on_GaussianBulr(int, void*)
{
	GaussianBlur(srcImage, dstImage2, Size(g_nGaussianBulrValue * 2 + 1, g_nGaussianBulrValue * 2 + 1), 0, 0);
	imshow("高斯滤波", dstImage2);
}
//====================非线性滤波======================//
static void on_MedianBlur(int, void*)
{
	//第三个参数必须是大于1的奇数
	medianBlur(srcImage, dstImage3, g_nMedianBlurValue * 2 + 1);
	imshow("中值滤波", dstImage3);
}
static void on_BilateralFilter(int, void*)
{
	bilateralFilter(srcImage, dstImage4, g_nBilateralFilterValue, g_nBilateralFilterValue * 2, g_nBilateralFilterValue / 2);
	imshow("双边滤波", dstImage4);
}