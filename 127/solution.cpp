class Solution {
public:
    int ladderLength(string begin_word, string end_word, vector<string>& word_list) {
        std::set<string> transition_words(word_list.begin(), word_list.end());
        if(transition_words.find(end_word) == transition_words.end()) return 0;

        std::set<string> visited;

        std::queue<string> words_to_explore;
        words_to_explore.push(begin_word);
        int transitions_count = 1;

        while(!words_to_explore.empty()) { // loop for levels
            int level_nodes_count = words_to_explore.size();
            for(int lni = 0; lni < level_nodes_count; lni++) { // loop for all nodes at the current level
                std::string current_word = words_to_explore.front();
                words_to_explore.pop();
                visited.insert(current_word);

                for(int i = 0; i < current_word.size(); i++) {
                    std::string candidate_transition = std::string(current_word);
                    for(char j = 'a'; j <= 'z'; j++) {
                        candidate_transition[i] = j;
                        if(candidate_transition == end_word) return transitions_count + 1;
                        else if(transition_words.find(candidate_transition) != transition_words.end() && visited.find(candidate_transition) == visited.end()) {
                            words_to_explore.push(candidate_transition);
                            visited.insert(candidate_transition);
                        }
                    } 
                }
            }

            transitions_count++;
        }

        return 0;
    }
};
