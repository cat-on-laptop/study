#include <vector>

using namespace std;

bool used[200'005];

int solution(vector<int> nums)
{
    int answer = 0;
    
    for(const int &x : nums) {
        if(used[x]) continue;
        if(answer >= (int)nums.size() >> 1) continue;
        used[x] = true;
        ++answer;
    }
    
    return answer;
}