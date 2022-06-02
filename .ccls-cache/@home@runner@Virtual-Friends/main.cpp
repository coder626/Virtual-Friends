#include <iostream>
#include <unordered_map>
#include <iterator>
#include <cstring>
#include <fstream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <queue>
#include <array>
#include <vector>
#include <queue>
#include <cassert>
#include <stack>
#include <algorithm>
using namespace std;


int arr[1000000];
int setSizes[1000000];
unordered_map<string, int> relationships;



int find(int set){
  //cout << arr[set];
  if(arr[set] == -1){
    return set;
  }
   //return find(arr[set]);
  arr[set] = find(arr[set]);
  return arr[set];
}

void UnionFunction(int set1, int set2){
  //cout << set1 << " " << set2 << endl;
  set1 = find(set1);
  set2 = find(set2);
  //cout << set1 << " " << set2 << endl;

  if(set1 == set2){
    //cout << "HERE *dubmfuck";
    return;
  }

  if(setSizes[set1] < setSizes[set2]){
    arr[set1] = set2;
    setSizes[set2] = setSizes[set2] + setSizes[set1];
  }
  else{
  arr[set2] = set1;
  setSizes[set1] = setSizes[set2] + setSizes[set1];
    }
}

/*
class Set{
  private:
  

  Set(string current){
    
  }

  

};
*/



int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /*
  //tester code, comment out on Kattis
  ifstream cin("input.txt");
  ifstream textFile;
  textFile.open("input.txt");
  if(textFile.fail()){
    cout << "File Open Failed";
    return 0;
  }
  */

  int counter = 1;
  int a;
  int b;
  string first;
  string second;
  cin >> a;
  for(int i = 0; i < a; i++){
    cin >> b;
    
    //std::fill_n(arr, b, -1);
    //std::fill_n(setSizes, b, -1);
    for(int i = 0; i < 1000000; i++){
      setSizes[i] = 1;
      arr[i] = -1;
    }
     
    relationships.clear();
    for(int j = 0; j < b; j++){
      
      cin >> first >> second;

      
      if(relationships.count(first) == 0){
          relationships[first] = counter;
          counter++;
        }
      if(relationships.count(second) == 0){
          //cout << second;
          relationships[second] = counter;
          counter++;
        }

      UnionFunction(relationships[first], relationships[second]);
      //cout << relationships[first] << " " << relationships[second] << endl;

      cout << setSizes[find(relationships[second])];
      cout<< endl;

      //unionFunction()
    }
  }
  
  //std::cout << "Hello World!\n";
}