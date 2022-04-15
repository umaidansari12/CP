#include<vector>
#include<string>
#include<sstream>
using namespace std;


string simplifyPath(string path) {
	//complete this code return the simplified path
	istringstream iss(path);
	vector<string> tokens;

	string token;
	while (getline(iss, token, '/')) {
		if (token == "." or token == "") {
			continue;
		}
		tokens.push_back(token);
	}


	// 2. Handle ..
	vector<string> stack;

	if (path[0] == '/') {
		//denotes that our path is an abs path (wrt root dir)
		stack.push_back("");
	}

	for (string token : tokens) {
		if (token == "..") {
			//2 cases -> Abs path or relative path
			if (stack.size() == 0 or stack[stack.size() - 1] == "..") {
				stack.push_back("..");
			}

			else if (stack[stack.size() - 1] != "") {
				stack.pop_back();
			}
		}
		else {
			//x,y,z...
			stack.push_back(token);
		}

	}
	//single element
	if (stack.size() == 1 and stack[0] == "") {
		return "/";
	}

	//combine all elements in stack to get the answer
	ostringstream oss;
	int i = 0;

	for (auto token : stack) {
		if (i != 0) {
			oss << "/";
		}
		i++;
		oss << token;
	}

	return oss.str();



}