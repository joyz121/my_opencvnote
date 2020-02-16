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
	//均值滤波 将窗口内对应图像所有像素的平均值作为模板中心点的像素值
	blur(src, dst, Size(4,4 ), Point(-1, -1));
	imshow("均值滤波",dst);
	//高斯滤波 高斯分布模型赋权重
	GaussianBlur(src, dst, Size(5, 5), 5,5);
	imshow("高斯滤波", dst);
	//中值滤波
	medianBlur(src, dst, 5);
	imshow("中值滤波",dst);
	//双边滤波
	bilateralFilter(src,dst,5,100,3);
	imshow("双边滤波",dst);
	waitKey(0);
	return 0;
}