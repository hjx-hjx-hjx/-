#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\pic\\yb.jpg",0);
	Mat dstMat,closeMat,labMat,statMat,centMat;
	threshold(srcMat, dstMat, 100, 255, THRESH_BINARY);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(dstMat, closeMat, MORPH_CLOSE, kernel);
	int number = cv::connectedComponentsWithStats(dstMat, labMat, statMat, centMat);
	cout << "有" << number << "个连通域" << endl;
	for (int i = 1; i < number; i++) {
		Rect rect;
		rect.x = statMat.at<int>(i, 0);
		rect.y = statMat.at<int>(i, 1);
		rect.width = statMat.at<int>(i, 2);
		rect.height = statMat.at<int>(i, 3);
		rectangle(srcMat, rect, CV_RGB(255, 0, 0));
	}
	imshow("openMat", srcMat);
	waitKey(0);

}