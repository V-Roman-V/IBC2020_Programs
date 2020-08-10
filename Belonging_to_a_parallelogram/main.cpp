#include <iostream>
#include <cmath>
#include <string>
using namespace std;
/*
To run this program, paste into the .replit file this text:
	
	run = "clang++-7 -pthread -std=c++17 -o Belonging_to_a_parallelogram/main Belonging_to_a_parallelogram/main.cpp \n ./Belonging_to_a_parallelogram/main"

And click the run button
*/
const double EPS = 1e-5;

class Point{
public:
	double x;
	double y;
};

class Line{
public:
	Point p1,p2;
	void setLine(Point P1, Point P2){p1=P1;p2=P2;}
	int isOn(Point p){
		if(abs(p1.x - p2.x) < EPS) // vertical
			return ((p1.x<p.x)?1:(p1.x==p.x)?2:0);
		// cout<<getK()<<" "<<getB()<<" "<<((getK()*p.x + getB()) <= p.y)<<endl;
		if(getK()*p.x + getB() == p.y && into(p) ) return 2;
		return  (((getK()*p.x + getB()) < p.y)?1:0);
	}
private:
	bool into(Point p){
		return (min(p1.x,p2.x) <= p.x && p.x <= max(p1.x,p2.x) && min(p1.y,p2.y) <= p.y && p.y <= max(p1.y,p2.y));
	}
	double getK(){
		if(abs(p1.x - p2.x) < EPS) // protection
			return 0;
		return (p1.y - p2.y)/(p1.x - p2.x);
	}
	double getB(){
		if(abs(p1.x - p2.x) < EPS) // protection
			return 0;
		return p1.y - p1.x*getK();
	}
};

class Parallelogram{
public:
	Parallelogram(Point P1, Point P2,Point P3, Point P4) {p1=P1;p2=P2;p3=P3;p4=P4;update();}
	bool isInto(Point p);

private:
	void update(){l1.setLine(p1,p2);l2.setLine(p2,p3);l3.setLine(p3,p4);l4.setLine(p4,p1);}

	Point p1,p2,p3,p4;
	Line l1,l2,l3,l4;
};

bool Parallelogram::isInto(Point p){
	string loc="";
	loc+=to_string(l1.isOn(p));
	loc+=to_string(l2.isOn(p));
	loc+=to_string(l3.isOn(p));
	loc+=to_string(l4.isOn(p));
	loc+=loc;
	// cout<<loc<<endl;
	if(loc.rfind("2") != std::string::npos) return true;
	return (loc.rfind("1100")!=std::string::npos);
}

int main(){
	Point p1,p2,p3,p4,p5;
	cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y>>p5.x>>p5.y;
	Parallelogram par(p1,p2,p3,p4);
	if(par.isInto(p5))
		cout<<"Point lies inside";
	else
		cout<<"Point lies outside";
}