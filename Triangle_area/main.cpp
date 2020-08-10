#include <iostream>
#include <cmath>
using namespace std;

class Point{
public:
	int x;
	int y;
};

double dist(Point a, Point b){
	return sqrt( pow(a.x - b.x,2) + pow(a.y - b.y,2));
}

class Triangle{
public:
	Triangle();
	Triangle(Point P1, Point P2, Point P3){p1=P1,p2=P2,p3=P3;update();}
	void setTriangle(Point P1, Point P2, Point P3){p1=P1,p2=P2,p3=P3;update();}
	double getArea();
private:
	void update(){a=dist(p1,p2);b=dist(p2,p3);c=dist(p1,p3);}

	Point p1,p2,p3;
	double a,b,c;
};

double Triangle::getArea(){
	double p = (a+b+c)*0.5;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}


int main() {
	Point p1,p2,p3;
	cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
	Triangle tri(p1,p2,p3);
	cout<<tri.getArea();
	return 0;
}