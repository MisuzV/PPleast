#include <iostream>
#include <cstdlib>  
#include <ctime> 
#include <iomanip>
#include <math.h>
#include "../include/misuzu.h"
using namespace std; 
//#define start;
struct Point {
	float x;
	float y;
};
void Init(Point *point, int num);
float Violent(Point *point, int num);
float Distance_nosqrt(Point a, Point b);
#ifdef start
float fun(Point *point, int num){
	if(num < 2){
		return __FLT_MAX__;
	}
	if(num == 2){
		return Distance_nosqrt(point[0], point[1]);
	}
	int mid = num / 2;
	float d1 = fun(point, mid);
	float d2 = fun(point + mid, num - mid);
	float d = (d1) > (d2) ? (d2) : (d1);
	
}
#endif
// float fun(locate result, float mid_distance){     //求得在给定的点中最小的距离(已按x轴排序)
//     if(result.num<2){
//         return
//     }
//     else if(result.num=2){
//         return dis()
//     }
//     else{
//         mid = (0 + max) / 2
//         d1 = fun(result[0~mid], (float)result[0+mid]/2)
//         d2 = fun(result[mid+1~max], (float)result[mid+1+max]/2)
//         d = min(d1,d2)
//         c1 = arr(result, mid_distance-d, mid_distance)//安排好
//         c2 = arr(result, mid_distance, mid_distance_d)//
//         sort(c2) //按y轴排序
//         for i in c1:
//             if(|i.y-|)
        
//     }
// }



int main(int argc, char *argv[])
{
	int num = 100000;
	double iStart,iElaps;
	srand(time(NULL));
    Point *point = new Point [num];
	Init(point, num);
	iStart=cpuSecond();
	float ViolentLeast = sqrt(Violent(point, num));
	iElaps=cpuSecond()-iStart;
	cout << "Violent cost " << setprecision(4) << iElaps << "ms" <<endl;
#ifdef start
	iStart=cpuSecond();
	float Myleast = sqrt(fun(point, num));
	iElaps=cpuSecond()-iStart;
	cout << "My cost " << setprecision(4) << iElaps << "ms" <<endl;
#endif 
	cout.setf(ios_base ::scientific);
	cout.setf(ios_base ::left);
	cout << ViolentLeast <<endl;

#ifdef start
	cout << Myleast <<endl;
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
	float ViolentLeast = 999999.0;
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




