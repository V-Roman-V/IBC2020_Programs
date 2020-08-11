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
/*
Example:

7
0 5 1 1 5 4 5
5 0 9 4 8 6 1
1 9 0 10 5 2 2
1 4 10 0 5 2 9
5 8 5 5 0 6 3
4 6 2 2 6 0 7
5 1 2 9 3 7 0

Min Path length: 18 way: 253164
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
	void print() {cout<<"Path length: "<<way<<" way: ";for(int i:visit)cout<<i;cout<<endl;}
};

int main(){
	cin>>N;
	vector< vector<int> > dir(N,vector<int> (N));
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>dir[i][j];
	Path start(0,0,0);
	Path minPath(0,-1,0);
	queue<Path> Q;
	Q.push(start);
	while(!Q.empty()){
		Path cur = Q.front(); Q.pop();
		// cout<<"curr: "; cur.print();
		Path next;
		if(cur.count == N-1){
			next = cur;
			next.city = 0;
			next.way += dir[cur.city][next.city];
			// cout<<"fin: "; next.print();
			if((next.way < minPath.way) || minPath.way==-1)
				minPath=next;
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
				// cout<<"add: "; next.print();
				Q.push(next);
			}
	}
	cout<<"Min ";minPath.print();
	return 0;
}