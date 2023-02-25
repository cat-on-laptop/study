#include <string>
#include <vector>
#include <iostream>

using namespace std;

int imos[1500];

int solution(vector<vector<string>> book_time) {
    for(const vector<string> arr: book_time) {
        // int t1 = stoi(arr[0].substr(1,3)) * 60 + stoi(arr[0].substr(4, 6)) , t2 = stoi(arr[1].substr(4,6));
        int t1 = stoi(arr[0].substr(0,2)) * 60 + stoi(arr[0].substr(3,5));
        int t2 = stoi(arr[1].substr(0,2)) * 60 + stoi(arr[1].substr(3,5));
        
        imos[t1] += 1;
        imos[t2 + 10] -= 1;
    }
    
    for(int i = 1; i < 1500; ++i) {
        imos[i] += imos[i-1];
    }
    
    int answer = 1;
    
    for(int i = 0; i < 1500; ++i) {
        answer = max(answer, imos[i]);
    }
    
    return answer;
}