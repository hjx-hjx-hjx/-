#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\pic\\dl.jpg",0);
	Mat srcMat_th,erodMat,dilateMat,labMat,statMat,centMat;
	threshold(srcMat, srcMat_th, 100, 255, THRESH_BINARY);
	Mat dstMat = 255 - srcMat_th;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(dstMat, erodMat, MORPH_ERODE, kernel,Point(-1,-1),10);
	morphologyEx(erodMat, dilateMat, MORPH_DILATE, kernel, Point(-1, -1), 10);
	int number = cv::connectedComponentsWithStats(dilateMat, labMat, statMat, centMat);
	imshow("aa", dilateMat);
	cout << "图中有" << number - 1 << "个圆点" << endl;
	waitKey(0);
}