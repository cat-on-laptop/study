#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> um;
    
    for(const string &x: participant) um[x]++;
    
    for(const string &x: completion) {
        if(um[x] != 0) um[x]--;
        if(um[x] == 0) um.erase(um.find(x));
    }
    answer = um.begin()->first;
    
    return answer;
}