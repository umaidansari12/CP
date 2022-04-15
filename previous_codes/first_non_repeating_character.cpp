class Solution {
public:
  // Complete this function
  char nonrepeatingCharacter(string S)
  {
    //Your code here
    unordered_map<char, int> s;
    char ans = '$';
    for (int i = 0; i < S.size(); i++)
    {
      s[S[i]]++;
    }
    for (int i = 0; i < S.size(); i++)
    {
      if (s[S[i]] == 1)
      {
        ans = S[i];
        break;
      }
    }
    return ans;
  }

};