#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

    vector<pair<int, int>> numbers;
    int n, m, temp;

    while(cin >> n >> m){
        
        cout << n << " " << m << endl;
        if(n == 0 && m == 0) return 0;

        for(int i = 0; i < n; i++){
            cin >> temp;
            numbers.push_back({temp, temp % m});
        }

        sort(numbers.begin(), numbers.end(),
            [](const pair<int, int> left, const pair<int, int> right){
                
                if (left.second != right.second) {
                    return left.second < right.second;
                }

                bool leftIsOdd = left.first % 2 != 0;
                bool rightIsOdd = right.first % 2 != 0;

                if (leftIsOdd != rightIsOdd) {
                    return leftIsOdd;
                }

                if (leftIsOdd && rightIsOdd) {
                    return left.first > right.first;
                }

                return left.first < right.first; 
            }
        );

        for(auto number : numbers){
            cout << number.first << endl;
        }

        numbers.clear();

    }


}