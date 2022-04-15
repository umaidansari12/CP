/*Apply dfs on the binary
tree and for each node maintain it's level and take the maximum value at each level.*/

//C++
void solve(Node* node, int level, vector<int> &answer)
{
	if (node == NULL)
		return ;
	if (level == answer.size())
		answer.push_back(node->data);
	else
		answer[level] = max(answer[level], node->data);
	solve(node->left, level + 1, answer);
	solve(node->right, level + 1, answer);
}

vector<int> maximumvalue(Node* node) {
	vector<int> answer;
	solve(node, 0, answer);
	return answer;
}

vector<int> maximumValue(Node* node) {
	//code here
	vector<int> r;
	queue<Node*>q;
	q.push(node);
	while (!q.empty())
	{
		int size = q.size(), ma = INT_MIN;
		for (int i = 0; i < size; i++)
		{
			Node* curr = q.front();
			ma = max(ma, curr->data);
			q.pop();
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}
		r.push_back(ma);
	}
	return r;
}