class Solution {
public:
    int findPosition(std::vector<int>& arr, int x) {
        int l = 0, r = arr.size();

        while(l < r) {
            int m = l + (r - l) / 2;
            if(x == arr[m]) return m;
            else if(x < arr[m]) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l == arr.size() ? l - 1 : l;
    }

    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int x_position = findPosition(arr, x);
        int i = x_position;
        int j = x_position + 1;
        if(i > 0 && abs(arr[i - 1] - x) <= abs(arr[i] - x)) {
            --i;
            --j;
        };
        
        while(--k >= 0) {
            if(i < 0) {
                j++;
            } else if (j == arr.size()) {
                i--;
            } else if(abs(arr[i] - x) <= abs(arr[j] - x)) {
                i--;
            } else {
                j++;
            }
        }
        
        std::vector<int> result;
        for(i++; i < j; i++) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};
