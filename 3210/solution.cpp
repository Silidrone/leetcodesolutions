class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        if(n == k) return s;

        string result = s;
        int i = 0;
        do {
            result[i] = s[(i + k) % n];
            i++;
        } while(i < n);

        return result;
    }
};
