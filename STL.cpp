#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<pair<string, int>> sort_map(map <string, int>& rank)
{
    vector<pair<string, int>> ordered;
 
    for (auto& i : rank) {
        if (i.second) {
            pair<string, int> p{ i.first, i.second };
            ordered.push_back(p);
        }
    }
 
    sort(
        begin(ordered), end(ordered),
        [=](auto&& p1, auto&& p2) {
            return p1.second > p2.second;
        }
    );
 
    return ordered;
}
 
int main() {
    map <string, int> rank;
 
    rank.insert(pair<string, int>("Anakonda", 52));
    rank.insert(pair<string, int>("Kenguru", 38));
    rank.insert(pair<string, int>("Orrszarvú", 42));
    rank.insert(pair<string, int>("Koala", 22));
    rank.insert(pair<string, int>("Vipera", 89));
 
    vector<pair<string, int>> res = sort_map(rank);
 
    for (auto& i : res)
        cout << i.first << " " << i.second << endl;
 
    return 0;
}