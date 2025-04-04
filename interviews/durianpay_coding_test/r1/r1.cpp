#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		vector<string> text, answer;
		int maxWidth, text_size;
		cin >> text_size;
		string word;
		for (int i = 0; i < text_size; i++) {
			cin >> word;
			text.push_back(word);
		}
		cin >> maxWidth;
		string line, temp;
		int txt_idx = 0;
		while (txt_idx < text_size) {
			temp = text[txt_idx];
			if (line.size() + temp.size() <= maxWidth) {
				line += temp;
				line += " ";
				txt_idx++;
			}
			else {
				answer.push_back(line);
				line = "";
			}
		}
		for (int j = line.size(); j <= maxWidth; j++) {
			line += " ";
		}
		answer.push_back(line);
		for (int i = 0; i < answer.size(); i++) {
			if (answer[i].size() < maxWidth) {
				int diff = maxWidth - answer[i].size();
				int countWords = 0;
				for (int j = 0; j < answer[i].size(); j++) {
					if (answer[i][j] == ' ')
						countWords++;
				}
				if (countWords > 1) {
					int noOfSpaces = ceil(diff / 2);
					for (int k = 0; k < answer[i].size(); k++) {
					}
				}
				else {
					for (int k = 0; k <= diff; k++) {
						answer[i].push_back(' ');
					}
				}
			}
			cout << answer[i] << endl;

		}
	}
}
