/*#include<bits/stdc++.h>

using namespace std;

int getVal(vector<vector<int>> a,int i,int j)
{
    if(i<0 || i > a.size() || j<0 || j> a[0].size())
    {
        return 0;
    }
    return a[i][j];
}

void findMaxBlock(vector<vector<int>> a,int r, int c,int size,vector<vector<bool>> cntarr, int &maxsize)
{
    if(r>=a.size()|| c >=a[0].size())
        return;
    cntarr[r][c]=true;
    size++;
    if(size > maxsize)
    {
        maxsize=size;
    }
    int directions[][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    for(int i=0;i<8;i++)
    {
        int newi=r+direction[i][0];
        int newj=c+direction[i][1];
        int val=getVal(a,newi,newj);
        if(val>0 && (cntarr[newj]==false))
        {
            findMaxBlock(a,newi,newj,size,cntarr,maxsize);
        }
    }
    cntarr[r][c]=false;
}

int getMaxOnes(vector<vector<int>> a,int rmax,int colmax)
{
    int maxsize=0;
    int size =0;
    bool **cntarr=create2darr(rmax,colmax);
    for
}

int** create2darr(int rmax, 5){
	
		int** ary = new int[rmax][5];
		return ary;
	}

int main()
{
    return 0;
}*/
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
//http://best-interview.com/find-group-1s-mxn-matrix/
using namespace std;
/*int rmax;
int colmax=5;*/
int main(){

	int A[5][5] = { { 1, 1, 0, 0, 0 }, { 0, 1, 1, 0, 1 }, { 0, 0, 0, 1, 1 }, { 1, 0, 0, 1, 1 }, { 0, 1, 0, 1, 1 } };
	
	cout << "Numer of maximum 1's are" << getMaxOnes(A, 5, 5) << endl;


}

int getval(int (*A)[5], int i, int j, int L, int H)
	{

	if (i < 0 || i >= L || j < 0 || j >= H){
		return 0;
	}

	else{
		return A[i][j];
	}

}

void findMaxBlock(int(*A)[5], int r, int c, int L, int H, int size, bool **cntarr, int &maxsize){

	if (r >= L || c >= H)
		return;

		cntarr[r][c] = true;

		size++;

		if (size > maxsize){
			maxsize = size;
		}

		int direction[][2] = { { -1, 0 }, { -1, -1 }, { 1, 0 }, { 0, -1 }, { 1, -1 }, { 1, 1 }, { 0, 1 }, { -1, 1 } };
		for (int i = 0; i < 8; i++){
			int newi = r + direction[i][0];
			int newj = c + direction[i][1];
			int val = getval(A, newi, newj, L, H);
			if (val>0 && cntarr[newi][newj] == false){
				findMaxBlock(A, newi, newj, L, H, size, cntarr, maxsize);
			}

		}
		cntarr[r][c] = false;
	

}

	int getMaxOnes(int(*A)[5], int rmax, int colmax){
		int maxsize = 0;
		int size = 0;
		bool **cntarr = create2darr(rmax, colmax);
		for (int i = 0; i < rmax; i++){
			for (int j = 0; j < colmax; j++){
				if (A[i][j] == 1){
					findMaxBlock(A, i, j, rmax, colmax, 0, cntarr, maxsize);
				}
			}
		}
		return maxsize;
	}

	bool** create2darr(int rmax, int colmax){
	
		bool** ary = new bool[rmax][5];
		return ary;
	}
    