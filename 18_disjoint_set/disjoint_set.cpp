#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//normal union and find takes O(logN) time
// union by rank and find by path compression takes O(4alpha) time which is approximated to 4

int findParentPathCompression(int node, vector<int>& parent, vector<int>&rank)
{
	if (parent[node] == node)
	{
		return node;
	}
	//this is path compression
	// 7-> 4 -> 3 -> 2 root parent is 2 and when 2 is returned we will store it in recursive a call and making the height of every node equal to 1
	//     2
	// /	\	\
	//7     4    3
	//        2
	//	 	  \
	// 	       4
	//  		\
	//   	 	 3
	// 	          \
	// 	           7
	return parent[node] = findParentPathCompression(parent[node], parent, rank);
}

int findParent(int node, vector<int>& parent, vector<int>& rank)
{
	if (parent[node] == node)
		return node;
	return findParent(parent[node], parent, rank);
}

void makeUnion(int u, int v, vector<int>& parent, vector<int>&rank)
{
	u = findParent(u, parent, rank);
	v = findParent(v, parent, rank);
	parent[u] = v;
}


//union by rank
// lower rank guy gets attached to the bigger rank guy
void makeUnionByRank(int u, int v, vector<int> &parent, vector<int>&rank)
{
	u = findParent(u, parent, rank);
	v = findParent(v, parent, rank);
	//connect parents rather than 2 nodes u and v itself this is union by rank
	if (rank[u] < rank[v]) {
		//if rank[u] < rank[v] means the height of node u is less than that of
		//height of node v and u can be accomodated below the node v
		//otherwise if we insert node v below the node u the case will arise when
		//the tree will become skewed and time complexity to find the parent
		//will be increased
		// if you attach smaller rank guy to the larger guy then we will not increase the rank because height of the tree will not increase
		parent[u] = v;
	}
	else if (rank[u] > rank[v]) {
		//if rank[u] > rank[v] means the height of node v is less than that of
		//height of node u and v can be accomodated below the node u
		//otherwise if we insert node u below the node v the case will arise when
		//the tree will become skewed and time complexity to find the parent
		//will be increased
		// if you attach smaller rank guy to the larger guy then we will not increase the rank because height of the tree will not increase
		parent[v] = u;
	}
	else {
		//the rank of both the nodes is same we can accomodate any node below
		//any of the other node and as the height of both are same adding one
		//node below it will increase the height of tree / component so we
		//will increase the rank of the node in which the other node is inserted
		parent[v] = u;
		rank[u]++;
	}
}



void makeSet(int n)
{
	int q;//number of query
	cin >> q;
	vector<int> parent(n + 1), rank(n + 1, 0);
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;//each node is parent of itself
		rank[i] = 0;//initially rank of every node is 0 because they are single component
	}
	while (q--)
	{
		int type, u, v;
		cin >> type >> u >> v;//type of query and nodes u and v
		if (type == 1)
		{
			makeUnion(u, v, parent, rank);
		}
		else if (type == 2)
		{
			if (findParent(u, parent, rank) == findParent(v, parent, rank))
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;//number of nodes
		makeSet(n);

	}


	return 0;
}