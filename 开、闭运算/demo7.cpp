#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("lena.jpg");
	Mat dstImage;	
	Mat element = getStructuringElement(MORPH_OPEN, Size(15, 15));
	
	//开运算——先腐蚀，再膨胀(消除小物体)
	morphologyEx(srcImage,dstImage,MORPH_OPEN,element);
	imshow("开运算",dstImage);
	
	//闭运算——先膨胀，再腐蚀(排除小的黑色区域)
	morphologyEx(srcImage, dstImage, MORPH_CLOSE, element);
	imshow("闭运算", dstImage);

	//形态学梯度——膨胀图和腐蚀图的差(边缘突出)
	morphologyEx(srcImage, dstImage, MORPH_GRADIENT, element);
	imshow("形态学梯度", dstImage);
	
	//顶帽——原图与开运算的差(分离亮斑/背景提取）
	morphologyEx(srcImage, dstImage, MORPH_TOPHAT , element);
	imshow("顶帽", dstImage);
	
	//黑帽——原图与闭运算的差（分离暗斑/轮廓提取）
	morphologyEx(srcImage, dstImage, MORPH_BLACKHAT, element);
	imshow("黑帽", dstImage);
	waitKey(0);
	return 0;
}