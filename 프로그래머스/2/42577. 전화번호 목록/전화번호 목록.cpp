#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool cmp(const string &l, const string &r)
{
    return l.length() == r.length() ? l < r : l.length() < r.length();   
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    unordered_set<string> us;
    for(const string& number : phone_book) {
        string temp = "";
        for(const char &x: number) {
            temp += x;
            if(us.find(temp) != us.end()) return false;
        }
        us.insert(number);
    }
    
    return true;
}