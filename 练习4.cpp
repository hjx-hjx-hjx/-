#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\pic\\hxz.jpg", 0);
	Mat srcMat_th,dstMat,labMat,statMat,centMat;
	threshold(srcMat, srcMat_th, 100, 255, THRESH_BINARY);
	dstMat = 255 - srcMat_th;
	int number = connectedComponentsWithStats(dstMat, labMat, statMat, centMat);
	//cout << number << endl;
	vector<int> p(number);
	for (int i = 0; i < number; i++) {
		p[i] = statMat.at<int>(i, 4);
	}
	sort(p.begin(), p.end());
	int a = p[number / 2];
	int min = a - 1000, max = a + 1000;
	int minend = 0,maxend=number-1;
	while (number--) {
		if (p[minend] < min)
			minend++;
		else {
			number++;
			break;
		}
	}
	while (number--) {
		if (p[maxend] > max)
			maxend--;
		else {
			number++;
			break;
		}
	}
	cout <<"有"<< number <<"个回形针"<< endl;
	return 0;
}