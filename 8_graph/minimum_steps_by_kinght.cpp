#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*This problem can be seen as shortest path in unweighted graph.
  Therefore we use BFS to solve this problem. We try all 8 possible
  positions where a Knight can reach from its position. If reachable
  position is not already visited and is inside the board, we push
  this state into queue with distance 1 more than its parent state.
  Finally we return distance of target position, when it gets pop out
  from queue.*/

class Solution
{
public:
	//Function to find out minimum steps Knight needs to reach target position.
	bool isSafe(int x, int y, int n) {
		if (x >= 1 and y >= 1 and x <= n and y <= n)
			return true;
		return false;
	}
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
	{
		// Code here
		int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
		int dy[] = {1, -1, 2, -2, -2, 2, -1, 1};
		queue<pair<pair<int, int>, int>> q; //pair((x,y),dist)
		q.push({make_pair(KnightPos[0], KnightPos[1]), 0});
		vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
		visited[KnightPos[0]][KnightPos[1]] = true;
		while (!q.empty()) {
			pair<int, int> coordinates = q.front().first;
			int dist = q.front().second;
			int x = coordinates.first;
			int y = coordinates.second;
			if (x == TargetPos[0] and y == TargetPos[1])
				return dist;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isSafe(nx, ny, N) and !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({make_pair(nx, ny), dist + 1});
				}
			}
		}
		return 0;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends