//Apply Breadth-first search.

class Solution
{
private:
	int R, C;
	bool isvalid(int i, int j)
	{
		return (i >= 0 && j >= 0 && i < R && j < C);
	}

	struct ele {
		int x, y;
	};

	bool isdelim(ele temp)
	{
		return (temp.x == -1 && temp.y == -1);
	}

	bool checkall(vector<vector<int>> hospital)
	{
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (hospital[i][j] == 1)
					return true;
		return false;
	}
public:
	int helpaterp(vector<vector<int>> hospital)
	{
		R = hospital.size();
		C = hospital[0].size();
		queue<ele> Q;
		ele temp;
		int ans = 0;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (hospital[i][j] == 2)
				{
					temp.x = i;
					temp.y = j;
					Q.push(temp);
				}
			}
		}
		temp.x = -1;
		temp.y = -1;
		Q.push(temp);

		while (!Q.empty())
		{

			bool flag = false;

			while (!isdelim(Q.front()))
			{
				temp = Q.front();

				if (isvalid(temp.x + 1, temp.y) && hospital[temp.x + 1][temp.y] == 1)
				{

					if (!flag) ans++, flag = true;
					hospital[temp.x + 1][temp.y] = 2;
					temp.x++;
					Q.push(temp);

					temp.x--;
				}
				if (isvalid(temp.x - 1, temp.y) && hospital[temp.x - 1][temp.y] == 1) {
					if (!flag) ans++, flag = true;
					hospital[temp.x - 1][temp.y] = 2;
					temp.x--;
					Q.push(temp);
					temp.x++;
				}
				if (isvalid(temp.x, temp.y + 1) && hospital[temp.x][temp.y + 1] == 1) {
					if (!flag) ans++, flag = true;
					hospital[temp.x][temp.y + 1] = 2;
					temp.y++;
					Q.push(temp);
					temp.y--;
				}
				if (isvalid(temp.x, temp.y - 1) && hospital[temp.x][temp.y - 1] == 1) {
					if (!flag) ans++, flag = true;
					hospital[temp.x][temp.y - 1] = 2;
					temp.y--;
					Q.push(temp);
				}
				Q.pop();
			}
			Q.pop();
			if (!Q.empty()) {
				temp.x = -1;
				temp.y = -1;
				Q.push(temp);
			}
		}


		return (checkall(hospital)) ? -1 : ans;

	}
};