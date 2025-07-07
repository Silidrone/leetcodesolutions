#include <iostream>
#include <array>
#include <vector>
#include <bitset>
using namespace std;

using Directions = bitset<4>; // "LURD" representation (Left, Up, Right, Down)

class Direction {
public:
    int r, c;
    Direction() : r(0), c(0) {}
    Direction(int _r, int _c) : r(_r), c(_c) {}
};

class Solution {
private:
    array<Directions, 6> streets = {
        Directions("1010"), // street 1
        Directions("0101"), // street 2
        Directions("1001"), // street 3
        Directions("0011"), // street 4
        Directions("1100"), // street 5
        Directions("0110")  // street 6
    };
    array<Directions, 4> directions = {
        Directions("1000"), // Left
        Directions("0100"), // Up
        Directions("0010"), // Right
        Directions("0001")  // Down
    };
    array<Direction, 4> directions_coordinate = {
        Direction(0, -1),   // Left
        Direction(-1, 0),   // Up
        Direction(0, 1),    // Right
        Direction(1, 0)     // Down
    };

    Directions opposite(Directions d) {
        if (d == directions[0]) return directions[2]; // Left -> Right
        if (d == directions[1]) return directions[3]; // Up -> Down
        if (d == directions[2]) return directions[0]; // Right -> Left
        if (d == directions[3]) return directions[1]; // Down -> Up
        return Directions("0000");
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if (r == grid.size() - 1 && c == grid[0].size() - 1) return true;

        visited[r][c] = true;

        for (int di = 0; di < directions.size(); di++) {
            int new_r = r + directions_coordinate[di].r;
            int new_c = c + directions_coordinate[di].c;

            if (new_r >= 0 && new_r < grid.size() && new_c >= 0 && new_c < grid[0].size() && !visited[new_r][new_c]) {
                int current_street_number = grid[r][c] - 1;
                int new_street_number = grid[new_r][new_c] - 1;

                Directions d = directions[di];
                Directions opposite_d = opposite(d);

                if ((streets[current_street_number] & d).any() && (streets[new_street_number] & opposite_d).any()) {
                    if (dfs(grid, visited, new_r, new_c)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        return dfs(grid, visited, 0, 0);
    }
};
