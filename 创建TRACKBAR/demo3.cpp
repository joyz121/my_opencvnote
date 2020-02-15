#include<opencv.hpp>
using namespace cv;

/*trackbar*/
int ContrastValue=80;
int BrightValue=80;
Mat src, dst;

//回调函数
static void back(int, void*)
{

	for (int y = 0; y < src.rows; y++)
	{
		for (int x = 0; x < src.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				dst.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((ContrastValue * 0.01) * src.at<Vec3b>(y, x)[c] + BrightValue);
			}
		}
	}
	imshow("img2", src);
	imshow("img", dst);
}

int main()
{
	src = imread("C:/Users/Joy/Desktop/image/lena.jpg");
	dst = Mat::zeros(src.size(),src.type());
	//ContrastValue = 80;
	//BrightValue = 80;

	namedWindow("img",1);
	createTrackbar("对比度", "img", &ContrastValue, 300,back);
	createTrackbar("亮度", "img", &BrightValue,200,back);

	back(ContrastValue, 0);
	back(BrightValue, 0);

	while (waitKey(1) != 'q') {};
	return 0;
}
