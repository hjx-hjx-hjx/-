#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\pic\\yb.jpg");
	Mat dstMat,erodMat,dilateMat,openMat,closeMat;
	threshold(srcMat, dstMat, 100, 255, THRESH_BINARY);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(dstMat, erodMat,MORPH_ERODE,kernel);
	morphologyEx(dstMat, dilateMat, MORPH_DILATE, kernel);
	morphologyEx(dstMat, openMat, MORPH_OPEN, kernel);
	morphologyEx(dstMat, closeMat, MORPH_CLOSE, kernel);

	imshow("二值图", dstMat);
	imshow("腐蚀",erodMat);
	imshow("膨胀", dilateMat);
	imshow("开运算", openMat);
	imshow("闭运算", closeMat);
	waitKey(0);
}