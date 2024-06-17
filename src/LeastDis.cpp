#include <iostream>
#include <cstdlib>  
#include <ctime> 
#include <iomanip>
#include <math.h>
#include "../include/misuzu.h"
#include <algorithm>
#include <vector>
using namespace std; 
#define start
struct Point {
	float x;
	float y;
	// bool operator<(const Point& other) const {
	// 	return (x < other.x) || (x == other.x && y < other.y);
	// }
};
bool compareByX(const Point& a, const Point& b) {
    return a.x < b.x;
}
bool compareByY(const Point& a, const Point& b) {
    return a.y < b.y;
}

void Init(Point *point, int num);
float Violent(Point *point, int num);
float Distance_nosqrt(Point a, Point b);
float MyPPleast(Point *point, int num);


int main(int argc, char *argv[])
{
	int num = 100000;
	
	cout.setf(ios_base ::left);
	cout.setf(ios_base::showpoint);
	double iStart,iElaps;
	srand(time(NULL));
    Point *point = new Point [num];
	Init(point, num);
	
	sort(point, point + num, compareByX);

	iStart=cpuSecond();
	float ViolentLeast = sqrt(Violent(point, num));
	iElaps=cpuSecond()-iStart;

	cout << "Violent cost " << setprecision(4) << iElaps * 1000 << "ms" <<endl;


#ifdef start
	iStart=cpuSecond();
	float Myleast = sqrt(MyPPleast(point, num));
	iElaps=cpuSecond()-iStart;
	cout << "My cost " << setprecision(4) << iElaps * 1000 << "ms" <<endl;

	cout.setf(ios_base ::scientific);
	if(abs(ViolentLeast - Myleast) < 0.001){
		cout << "Correct" << endl << "The result is " << setprecision(4) << Myleast << endl;
	}else{
		cout << "Incorrect" << endl;
	}
#endif

}
void Init(Point *point, int num){
	for (int i = 0; i < num; i++)
	{
		float x = (rand() % num) * 1.0 + (rand() % 10) * 1.21 / 10;
		float y = (rand() % num) * 1.0 + (rand() % 10) * 1.331 / 10;
		point[i].x = x;
		point[i].y = y;
	}
}
float Distance_nosqrt(Point a, Point b){
	return (abs(a.x - b.x)) * (abs(a.x - b.x)) + (abs(a.y - b.y)) * (abs(a.y - b.y));
}
float Violent(Point *point, int num){
	float ViolentLeast = __FLT_MAX__;
	
	for(int i = 0; i < num; i++){
		for(int j = i + 1; j < num; j++){
			float temp = Distance_nosqrt(point[i], point[j]);
			if(ViolentLeast > temp){
				ViolentLeast = temp;
			}
		}
	}
	return ViolentLeast;
}
#ifdef start
float MyPPleast(Point *point, int num){
	if(num < 2){                                
		return __FLT_MAX__;
	}
	if(num == 2){
		return Distance_nosqrt(point[0], point[1]);
	}
	int mid = num / 2;
	float d1 = MyPPleast(point, mid);
	float d2 = MyPPleast(point + mid, num - mid);
	float d = (d1) > (d2) ? (d2) : (d1);

	vector<Point> C1, C2;
	for(int i = 0; i < num; i++){
		if((point[mid].x - point[i].x) <= sqrt(d) && i < mid){
			C1.push_back(point[i]);
			continue;
		}
		if((point[i].x - point[mid].x) <= sqrt(d)){
			C2.push_back(point[i]);
		}
	}
	sort(C2.begin(), C2.end(), compareByY);
	for(int i=0; i < C1.size(); i++){
		auto it = lower_bound(C2.begin(), C2.end(), C1[i], compareByY);
		if(it != C2.end()){
			auto temp = it;
			for(int j = 0; j < 3; j++){
				float dis = Distance_nosqrt(C1[i], *it);
				if(dis < d){
					d = dis;
				}
				it++;
				if(it == C2.end()){
					break;
				}
			}
			if(temp != C2.begin()){
				temp--;
				for(int j = 0; j < 3; j++){
					float dis = Distance_nosqrt(C1[i], *temp);
					if(dis < d){
						d = dis;
					}
					if(temp == C2.begin()){
						break;
					}
					temp--;
				}
			}
		}else{
			auto temp = --it;
			for(int j = 0; j < 3; j++){
				float dis = Distance_nosqrt(C1[i], *temp);
				if(dis < d){
					d = dis;
				}
				if(temp == C2.begin()){
					break;
				}
				temp--;
			}
		}	
	}
	return d;
}
#endif