#include<opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("lena.jpg",IMREAD_GRAYSCALE);

	//将图像延扩到最佳尺寸，边界用0填充
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);
	//将添加的像素初始化为0
	Mat padded;
	copyMakeBorder(srcImage, padded, 0, m - srcImage.rows, 0, n - srcImage.cols, BORDER_CONSTANT, Scalar::all(0));
	//为傅里叶变换的结果分配内存空间
	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);
	//离散傅里叶变换
	dft(complexI, complexI);
	//将复数转化为幅值,0通道为实数通道，1为虚数
	split(complexI, planes);
	magnitude(planes[0], planes[1], planes[0]);
	Mat magnitudeImage = planes[0];
	//进行对数尺度缩放
	magnitudeImage += Scalar::all(1);
	log(magnitudeImage, magnitudeImage);
	//剪切和重分布幅度象限
	magnitudeImage = magnitudeImage(Rect(0, 0, magnitudeImage.cols & -2, magnitudeImage.rows & -2));
	//重新排列，使原点位于图像中心
	int cx = magnitudeImage.cols / 2;
	int cy = magnitudeImage.rows / 2;
	Mat q0(magnitudeImage, Rect(0, 0, cx, cy));
	Mat q1(magnitudeImage, Rect(cx, 0, cx, cy));
	Mat q2(magnitudeImage, Rect(0, cy, cx, cy));
	Mat q3(magnitudeImage, Rect(cx, cy, cx, cy));
	Mat tmp;
	//交换象限
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);
	//归一化
	normalize(magnitudeImage, magnitudeImage, 1, 0, NORM_MINMAX);
	imshow("原始图像",srcImage);
	imshow("频谱", magnitudeImage);
	
	//IDFT
	Mat _complexi;
	complexI.copyTo(_complexi);
	Mat IDFT[] = { Mat::zeros(planes[0].size(),CV_32F),Mat::zeros(planes[0].size(),CV_32F) };
	idft(_complexi,_complexi);
	split(_complexi, IDFT);
	magnitude(IDFT[0],IDFT[1],IDFT[0]);
	normalize(IDFT[0], IDFT[0], 1, 0, NORM_MINMAX);
	imshow("IDFT",IDFT[0]);

	waitKey(0);
	return 0;
}