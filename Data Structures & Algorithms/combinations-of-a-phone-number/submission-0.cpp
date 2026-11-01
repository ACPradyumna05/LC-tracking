class Solution {
public:
    const vector<string> pad = {
        "",     
        "",     
        "abc",  
        "def",  
        "ghi",  
        "jkl",  
        "mno",  
        "pqrs", 
        "tuv",  
        "wxyz"  
    };
    void backtrack(const string& digits, int index, string& current, vector<string>& result){
        if(index==digits.size()){
            result.push_back(current);
            return;
        }

        const string& letters=pad[digits[index]-'0'];
        for (char ch:letters){
            current.push_back(ch);
            backtrack(digits, index+1, current, result);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;

        string current = "";
        backtrack(digits,0,current, result);
        return result;
    }
};
