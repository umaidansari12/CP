#include <iostream>
#include <jsoncpp/json/json.h>

/*
Given a list of folders, print the path of a given folder from root. If there is no path to the root folder then return an empty string. Root level folders will have 0 as id. The structure of Folder is
like this:
class Folder {
 int id;
 List<int> subfolders;
 String name;
}
Ex:
list = [Folder(0, [7, 3], "abc"), Folder(0, [], "xyz"), Folder(3, [], "pqr"), Folder(8, [], "def"), Folder(7, [9], "ijk), Folder(9, [], "lmn")]
printPath(9) = "abc" -> "ijk" -> "lmn"
ultimate goal is to reach the folder with id as 0, and if not reachable return an empty string
*/
int main() {
  std::cout << "Hello world" << std::endl;
  return 0;
}

0 -> 7 -> 9
0 -> 3 -> 

// my answer to create the graph and then traverse in each component to search for the required path

0 -> abc       0 -> xyz   8 -> def
7 -> ijk 3 -> pqr
9 -> lmn  

// follow up -> how do we create the graph and it's component in the first place

map<pair<int, string>, Folder>>;
(0, abc) -> folder_0
(0, xyz) -> folder_1
(3, pqr) -> folder_2
(8, def) -> folder_3
(7, ijk) -> folder_4

// keep a track of folder id and name
// time complexity in terms of the number of elements

O(n)
O(n)

class Folder {
 int id;
 List<int> subfolders;
 String name;
}

list = [Folder(0, [7, 3], "abc"), Folder(0, [], "xyz"), Folder(3, [], "pqr"), Folder(8, [], "def"), Folder(7, [9], "ijk), Folder(9, [], "lmn")]
// printPath(9) = "abc" -> "ijk" -> "lmn"

printPath(int search_node, int current_node, int current_idx){
  if(current_node == search_node){
    cout << folders[current_idx].name << endl;
    return ;
  }
  cout << (folders[current_idx].name) << "->";
  for(auto folder: folders[current_idx].subfolders){
    // traversing list and find out current idx of the folder 
    printPath(search_node, folder, current_idx);
  }
}

int n = list.size();
for(int idx = 0; idx < n; i++){
  if(folder[idx].id == 0){
    printPath(search_node, folder[idx].id, idx);
  }
}

"abc" -> "ijk" -> "lmn"
