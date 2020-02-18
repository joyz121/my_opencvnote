#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

Mat srcImage, dstImage;
//0-∏Ø ¥£¨1-≈Ú’Õ
int TrackbarNumber = 0;
int StructElementSize = 3;

void on_SizeChange(int, void*);
void on_NumChange(int, void*);
void Process();

int main()
{

	srcImage = imread("lena.jpg");
	if (srcImage.empty())
	{
		cout << "img_load_failed" << endl;
		return false;
	}
	namedWindow("output");
	createTrackbar("∏Ø ¥/≈Ú’Õ", "output", &TrackbarNumber, 1, on_NumChange);
	createTrackbar("size", "output", &StructElementSize, 21, on_SizeChange);

	waitKey(0);
	return 0;

}
void Process()
{
	Mat element = getStructuringElement(MORPH_RECT, Size(StructElementSize * 2 + 1, StructElementSize * 2 + 1), Point(StructElementSize, StructElementSize));
	if (TrackbarNumber == 0)
	{
		erode(srcImage, dstImage, element);
	}
	else
	{
		dilate(srcImage,dstImage,element);
	}
	imshow("output", dstImage);
}

void on_NumChange(int, void*)
{
	Process();
}
void on_SizeChange(int, void*)
{
	Process();
}