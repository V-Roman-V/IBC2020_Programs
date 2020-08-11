#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
/*
To run this program, paste into the .replit file this text:
	
	run = "clang++-7 -pthread -std=c++17 -o Min_path/main Min_path/main.cpp \n ./Min_path/main"

And click the run button
*/
int N;

class Path{
public:
	Path(){;}
	Path(int c, int w, int cnt){city=c;way=w;count=cnt; visit.resize(N-1,0);}
	int city;
	int way;
	int count;
	vector<int> visit;
	void print() {cout<<"city: "<<city<<" way: "<<way<<" visit: ";for(int i:visit)cout<<i;cout<<endl;}
};

int main(){
	cin>>N;
	vector< vector<int> > dir(N,vector<int> (N));
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>dir[i][j];
	Path start(0,0,0);
	int minPath = -1;
	queue<Path> Q;
	Q.push(start);
	while(!Q.empty()){
		Path cur = Q.front(); Q.pop();
		cout<<"curr: "; cur.print();
		Path next;
		if(cur.count == N-1){
			next = cur;
			next.city = 0;
			next.way += dir[cur.city][next.city];
			cout<<"fin: "; next.print();
			if((next.way < minPath) || minPath==-1)
				minPath=next.way;
			continue;
		}
		vector<bool> to(N,true);
		for(int i=0;i<cur.visit.size();i++)
			to[cur.visit[i]] = false;
		for(int i=0;i<N;i++)
			if(to[i]){
				next = cur;
				next.city = i;
				next.way += dir[cur.city][next.city];
				next.visit[next.count]=i;
				next.count += 1;
				cout<<"add: "; next.print();
				Q.push(next);
			}
	}
	cout<<minPath;
	return 0;
}