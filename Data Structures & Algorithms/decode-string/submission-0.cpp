class Solution {
public:
    string decodeString(string s) {
        
    stack<string> st;
    stack<int> nums;

    int num = 0;
    string curr = "";

    for(int i = 0; i < s.length(); i++) {

        if(s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }

        else if(s[i] == '[') {
            nums.push(num);
            st.push(curr);

            num = 0;
            curr = "";
        }

        else if(s[i] >= 'a' && s[i] <= 'z') {
            curr += s[i];
        }

        else if(s[i] == ']') {
            int repeat = nums.top();
            nums.pop();

            string prev = st.top();
            st.pop();

            string temp = "";

            for(int j = 0; j < repeat; j++) {
                temp += curr;
            }

            curr = prev + temp;
        }
    }

    return curr;
}
    };