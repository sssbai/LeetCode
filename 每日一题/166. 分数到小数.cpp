#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long a = numerator, b = denominator;
        string sign = a * b >= 0 ? "": "-";
        a = abs(a);
        b = abs(b);
        long long q = a / b;
        long long r = a % b;
        if(r == 0){
            return sign + to_string(q);
        }
        string res = sign + to_string(q) + ".";
        unordered_map<long long, int> umap;
        while(r){
            umap[r] = res.size();
            r *= 10;
            q = r / b;
            r = r % b;
            res += '0' + q; 
            if(umap.contains(r)){
                int pos = umap[r];
                return res.substr(0, pos) + "(" + res.substr(pos) + ")";
            }
        }
        return res;
    }
};
int main(){
    Solution solve = Solution();
    string result = solve.fractionToDecimal(1,5);
    cout<<result<<endl;
    return 0;
}