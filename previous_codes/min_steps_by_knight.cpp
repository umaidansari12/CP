/*We can consider the chessboard as unweighted and undirected graph. We can always find shortest path in an unweighted graph using Breadth First Search.

Every cell in the chessboard can be considered as a different vertex connected to atmost 8 other vertices where the knight can reach from the current cell.
The possible moves for a Knight when it is at cell (x, y) are:
(x-2, y-1)
(x-2, y+1)
(x-1, y-2)
(x-1, y+2)
(x+2, y-1)
(x+2, y+1)
(x+1, y-2)
(x+1, y+2)

*/

// Back-end complete function template for C++

struct cell {
	int x, y;
	int dis;
	cell() {}
	cell(int x, int y, int dis)
		: x(x), y(y), dis(dis)
	{
	}
};

// Utility method returns true if (x, y) lies
// inside Board
bool isInside(int x, int y, int N)
{
	if (x >= 1 && x <= N && y >= 1 && y <= N)
		return true;
	return false;
}

int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
	// code here
	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	// queue for storing states of knight in board
	queue<cell> q;

	// push starting position of knight with 0 distance
	q.push(cell(knightPos[0], knightPos[1], 0));

	cell t;
	int x, y;
	bool visit[N + 1][N + 1];

	// make all cell unvisited
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			visit[i][j] = false;

	// visit starting state
	visit[knightPos[0]][knightPos[1]] = true;

	// loop untill we have one element in queue
	while (!q.empty()) {
		t = q.front();
		q.pop();

		// if current cell is equal to target cell,
		// return its distance
		if (t.x == targetPos[0] && t.y == targetPos[1])
			return t.dis;

		// loop for all reachable states
		for (int i = 0; i < 8; i++) {
			x = t.x + dx[i];
			y = t.y + dy[i];

			// If reachable state is not yet visited and
			// inside board, push that state into queue
			if (isInside(x, y, N) && !visit[x][y]) {
				visit[x][y] = true;
				q.push(cell(x, y, t.dis + 1));
			}
		}
	}
}


int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
	if (knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1]) return 0;

	int visited[N + 1][N + 1] = {0};
	visited[knightPos[0]][knightPos[1]] = 1;

	queue<pair<int, int> > q;
	q.push(pair<int, int>(knightPos[0], knightPos[1]));

	int rr[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
	int cc[8] = { -1, 1, -2, 2, -2, 2, -1, 1};

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextr = r + rr[i];
			int nextc = c + cc[i];

			if (nextr < 1 || nextc < 1 || nextr > N || nextc > N) continue;
			if (visited[nextr][nextc] != 0) continue;

			if (nextr == targetPos[0] && nextc == targetPos[1])
				return visited[r][c];

			visited[nextr][nextc] = visited[r][c] + 1;
			q.push(pair<int, int>(nextr, nextc));
		}
	}
	return 0;
}
