class Solution
{
public:
	// TC - O(n! * n) (n! permutations are being generated and we're looping in every time n times)
	// SC - O(n) + O(n)
	void permute(string S, int idx, int _size, string res, vector<string> &answer, vector<bool> visited, set<string> &unique) {
		visited[idx] = true;
		res += S[idx];

		// cout<<res.size()<<endl;
		if (res.size() == _size) {
			// cout<<res<<endl;
			if (unique.find(res) == unique.end()) {
				unique.insert(res);
				answer.push_back(res);
			}
			return;
		}
		// cout<<res<<endl;
		for (int i = 0; i < _size; i++) {
			if (!visited[i]) {
				// cout<<i<<" "<<endl;
				permute(S, i, _size, res, answer, visited, unique);
			}
		}
		visited[idx] = false;
		res.pop_back();
	}
	vector<string>find_permutation(string S)
	{
		// Code here there
		vector<string> answer;
		set<string> unique;
		int _size = S.size();
		vector<bool> visited(_size, false);
		string res = "";
		for (int i = 0; i < _size; i++) {
			permute(S, i, _size, res, answer, visited, unique);
		}
		//  cout<<answer.size()<<endl;
		return answer;
	}
};

class Solution
{
public:
	void permute(string S, int idx, int _size, string res, vector<string> &answer, vector<bool> visited, set<string> &unique) {
		visited[idx] = true;
		res += S[idx];

		// cout<<res.size()<<endl;
		if (res.size() == _size) {
			// cout<<res<<endl;
			if (unique.find(res) == unique.end()) {
				unique.insert(res);
				answer.push_back(res);
			}
			return;
		}
		// cout<<res<<endl;
		for (int i = 0; i < _size; i++) {
			if (!visited[i]) {
				// cout<<i<<" "<<endl;
				permute(S, i, _size, res, answer, visited, unique);
			}
		}
		visited[idx] = false;
		res.pop_back();
	}
	vector<string>find_permutation(string S)
	{
		// Code here there
		vector<string> answer;
		set<string> unique;
		int _size = S.size();
		vector<bool> visited(_size, false);
		string res = "";
		for (int i = 0; i < _size; i++) {
			permute(S, i, _size, res, answer, visited, unique);
		}
		//  cout<<answer.size()<<endl;
		return answer;
	}
};

class Solution
{
public:
	void permute(string S, string permutation, vector<string> &permutations, set<string> &unique_permutations, vector<bool> visited) {
		if (permutation.size() == S.size()) {
			if (unique_permutations.find(permutation) == unique_permutations.end()) {
				unique_permutations.insert(permutation);
				permutations.push_back(permutation);
			}
			return;
		}
		for (int i = 0; i < S.size(); i++) {
			if (!visited[i]) {
				visited[i] = true;
				permutation += S[i];
				permute(S, permutation, permutations, unique_permutations, visited);
				visited[i] = false;
				permutation.pop_back();
			}
		}
	}
	vector<string>find_permutation(string S)
	{
		// Code here there
		vector<string> permutations;
		set<string> unique_permutations;
		int _size = S.size();
		string permutation = "";
		vector<bool> visited(_size, false);
		permute(S, permutation, permutations, unique_permutations, visited);
		return permutations;
	}
};
