class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if(t.size() > s.size() || t == "") return "";
        std::unordered_map<char, int> needed;
        std::unordered_map<char, int> done;

        for(auto &c : t) {
            needed[c]++;
            done[c] = 0;
        }
        int total_needed = needed.size();
        int total_done = 0;

        int l = 0, r = 0;
        int mwl = -1, mwr = -1; //minimum window left index, minimum window right index
        for(int r = 0; r < s.size(); r++) {
            auto r_it = done.find(s[r]);
            if(r_it != done.end()) {
                r_it->second += 1;
                if(r_it->second == needed[s[r]]) {
                    total_done++;
                    while(total_done == total_needed) {
                        if((mwl == -1 && mwr == -1) || r - l < mwr - mwl) {
                            mwr = r;
                            mwl = l;
                        }
                        auto l_it = done.find(s[l]);
                        if(l_it != done.end()) {
                            l_it->second -= 1;
                            if(l_it->second < needed[s[l]]) {
                                total_done--;
                            }
                        }
                        l++;                               
                    }                     
                }
            }
        }

        return (mwl == -1 && mwr == -1) ? "" : s.substr(mwl, mwr - mwl + 1);
    }
};
