#ifndef DEBUG_MESSAGE_H
#define DEBUG_MESSAGE_H
#include <iostream>
#include <vector>
using namespace std;
#define COUTFUNC cout << __func__<<" "<<__LINE__ << endl;

template<typename T>
void printVector(vector<T> vec) {
  for (auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
}
template<typename T>
void printMatrix(vector<vector<T>> matrix){
    for(auto i:matrix){
        for(auto j:i){
          cout<<j<<" ";
        }
        cout<<endl;
    }
}
#endif // DEBUG_MESSAGE_H
