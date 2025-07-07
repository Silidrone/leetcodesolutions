/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include <climits>

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;

        while(l < r) {
            int m = l + (r - l) / 2;
            int feedback = guess(m);
            if(feedback == -1) { // i guessed too high
                r = m;
            } else if(feedback == 1) { // i guessed too low
                l = m + 1;
            } else {
                return m;
            }
        }

        return l;
    }
};
