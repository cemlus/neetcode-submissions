class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            // If it's an opening bracket, push it to the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If it's a closing bracket but stack is empty, it's invalid
                if (st.empty()) return false;
                
                char top = st.top();
                // Check if the current closing bracket matches the stack top
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false; // Mismatched bracket type
                }
            }
        }
        // If the stack is empty, all brackets were correctly matched
        return st.empty();
    }
};