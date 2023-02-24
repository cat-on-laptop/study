#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int q = 0; q < commands.size(); ++q) {
        int i = commands[q][0], j = commands[q][1], k = commands[q][2];
        --i, --k;
        vector<int> temp(array.begin() + i, array.begin() + j); 
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[k]);
    }
    return answer;
}