#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;
//Í¼ÏñÑÚÄ¤¡ª¡ª¾í»ý
int main() 
{
	Mat src = imread("C:/Users/Joy/Desktop/image/lena.jpg");
	imshow("img", src);

	int rows = src.rows;
	int offset = src.channels();
	int cols = src.cols * src.channels();

	int pix= src.ptr(1)[2];
	cout << pix << endl;

	Mat out = Mat::zeros(src.size(), src.type());
	/*
	-----------
	| 0|-1 | 0|
	|-1| 5 |-1|
	| 0|-1 | 0|
	-----------
	*/
	for (int i = 1; i < rows-1; i++)
	{
		uchar* preview = src.ptr(i - 1);
		uchar* current = src.ptr(i);
		uchar* next = src.ptr(i + 1);
		uchar* p=out.ptr(i);
		
		for (int j = offset; j < cols - offset; j++)
		{
			p[j] = saturate_cast<uchar>(5 * current[j] - current[j - offset] - current[j + offset]);
		}
	}
	
	imshow("img2",out);
	waitKey(0);
}