#include<opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("lena.jpg",IMREAD_GRAYSCALE);

	//��ͼ����������ѳߴ磬�߽���0���
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);
	//����ӵ����س�ʼ��Ϊ0
	Mat padded;
	copyMakeBorder(srcImage, padded, 0, m - srcImage.rows, 0, n - srcImage.cols, BORDER_CONSTANT, Scalar::all(0));
	//Ϊ����Ҷ�任�Ľ�������ڴ�ռ�
	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);
	//��ɢ����Ҷ�任
	dft(complexI, complexI);
	//������ת��Ϊ��ֵ,0ͨ��Ϊʵ��ͨ����1Ϊ����
	split(complexI, planes);
	magnitude(planes[0], planes[1], planes[0]);
	Mat magnitudeImage = planes[0];
	//���ж����߶�����
	magnitudeImage += Scalar::all(1);
	log(magnitudeImage, magnitudeImage);
	//���к��طֲ���������
	magnitudeImage = magnitudeImage(Rect(0, 0, magnitudeImage.cols & -2, magnitudeImage.rows & -2));
	//�������У�ʹԭ��λ��ͼ������
	int cx = magnitudeImage.cols / 2;
	int cy = magnitudeImage.rows / 2;
	Mat q0(magnitudeImage, Rect(0, 0, cx, cy));
	Mat q1(magnitudeImage, Rect(cx, 0, cx, cy));
	Mat q2(magnitudeImage, Rect(0, cy, cx, cy));
	Mat q3(magnitudeImage, Rect(cx, cy, cx, cy));
	Mat tmp;
	//��������
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);
	//��һ��
	normalize(magnitudeImage, magnitudeImage, 1, 0, NORM_MINMAX);
	imshow("ԭʼͼ��",srcImage);
	imshow("Ƶ��", magnitudeImage);
	
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