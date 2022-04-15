#include<bits/stdc++.h>
using namespace std;


bool cmp(pair<string, string>p1 , pair<string, string>p2) {
    //Prime orders before non Prime
    string s1 = p1.second;
    string s2 = p2.second;
    //Assuming none of the Metadata is NULL

    //Both are Prime
    /*
    s1 = "Kindle ebook"
    s2 = "Kandle"
           i                when i = 1  s1[i] - s2[i]>0  => s2 is lexographically smaller
                            this means p2 will be coming first in sequence for that to happen
                            return false;
    */
    if ((s1[0] >= 'a' && s1[0] <= 'z') && (s2[0] >= 'a' && s2[0] <= 'z')) {
        //Find lexographically smaller Metadata and it will come first in sequence
        for (int i = 0 ; i < s1.size() , i < s2.size() ; i++) {
            if ((s1[i] - s2[i]) > 0)    return false;
            else if ((s1[i] - s2[i] < 0))  return true;
        }
        //if none of the statements is returned a tie comes up and lexographically smaller Id comes ahead in sequence
        string id1 = p1.first;
        string id2 = p2.first;
        for (int i = 0 ; i < id1.size() , i < id2.size() ; i++) {
            if ((id1[i] - id2[i]) > 0)    return false;
            else if ((id1[i] - id2[i] < 0))  return true;
        }
    }
    //Only 1st is prime
    if (s1[0] >= 'a' && s1[0] <= 'z') {
        return true;
    }
    //Only 2nd is prime
    if (s2[0] >= 'a' && s2[0] <= 'z') {
        return false;
    }

    //None is prime else leave the sequence as it is
    return true;
}

//Make a list of orders
int main() {
    vector<pair<string, string>>v = {{"abc", "12 23"}, {"xff", "43 29"}, {"af", "nfrh nfrh"}, {"f", "kindle ebook"}};
    v.push_back({"aax", "12 23"});
    v.push_back({"ff" , "kindle ebook"});
    v.push_back({"ff" , "kandle ebook"});
    //Now sort the vector of string with the help of a cmp function created above
    sort(v.begin() , v.end() , cmp);
    for (auto i : v) cout << i.first << " " << i.second << endl;
}

// Working solution to the problem with full explanation :

// Logic :

// I've passed my comparator function and then applied the logic inside the comparator function.
// For separating the id with metadata, I've used a helper function and then again joined them via another function.
// Please upvote if you like the solution.


vector<pair<string, string>> preprocess(vector<string> &list) {
    //we will find the string before the first ' '
    vector<pair<string, string>> ans;
    int n = list.size();

    for (int i = 0; i < n; i++) {
        string s = list[i];
        int index = 0;
        while (index < s.size() && s[index] != ' ')
            index++;

        //we will store the data as {metadata,id}
        string id = s.substr(0, index);
        string metadata = s.substr(index + 1);
        ans.push_back({metadata, id});
    }
    return ans;
}

vector<string> join(vector<pair<string, string>> &orders) {
    vector<string> ans;
    for (int i = 0; i < orders.size(); i++) {
        string id = orders[i].second, metadata = orders[i].first;
        string orderData = id + " " + metadata;
        ans.push_back(orderData);
    }
    return ans;
}

bool compare(const pair<string, string> &a, const pair<string, string> &b) {
    //if both orders are prime orders
    string s1 = a.first, s2 = b.first;
    if ((s1[0] >= 'a' && s1[0] <= 'z') && (s2[0] >= 'a' && s2[0] <= 'z')) {
        for (int i = 0; i < s1.size(), i < s2.size(); i++) {
            if (s1[i] < s2[i])
                return true;
            if (s1[i] > s2[i])
                return false;
        }

        //now if both the metadata are equal, we will compare the value
        string id1 = a.second, id2 = b.second;
        for (int i = 0; i < id1.size(), i < id2.size(); i++) {
            if (id1[i] < id2[i])
                return true;
            if (id1[i] > id2[i])
                return false;
        }

        //if both the id and metadata are equal, maintain the sequence from the order list
        return false;
    }

    //if only first order is prime
    if (s1[0] >= 'a' && s1[0] <= 'z')
        return true;

    //if only the second order is prime
    if (s2[0] >= 'a' && s2[0] <= 'z')
        return false;

    //if both the orders are non-prime
    return false;
}

vector<string> sortOrders(vector<string> &orderList) {
    //separate the id and metadata and then sort
    vector<pair<string, string>> v = preprocess(orderList);
    //sort the pair
    sort(v.begin(), v.end(), compare);
    //again join the pairs to form the resultant string
    vector<string> ans = join(v);
    return ans;
}