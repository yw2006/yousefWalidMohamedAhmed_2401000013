#include <iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='[' || s[i]=='{' || s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }else{
                char poped = st.top();
                st.pop();
                if((poped=='[' && s[i]!=']')|| (poped=='{' && s[i]!='}') || (poped=='(' && s[i]!=')')){
                    return false;
                }
                }
            }
        }
        return st.empty()  ;  
    }
};

int main(){
    Solution so;
    cout << so.isValid("[]") << endl;
    cout << so.isValid("[") << endl;
    cout << so.isValid("[{}]") << endl;
}
