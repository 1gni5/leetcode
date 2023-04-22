struct point {
    int x;
    int y;
};

class Solution {
public:

    vector<vector<char>> grid;
    int width, height;

    bool inGrid(point p) {
        if (p.x < 0 || p.x >= width) {return false;}
        if (p.y < 0 || p.y >= height) {return false;}
        return true;
    }

    int removeIsland(point start) {

        // Initialization
        int size = 0;
        queue<point> waiting;

        // Start exploring
        waiting.push(start);
        while (!waiting.empty()) {
            point p = waiting.front();
            waiting.pop();

            // Mark position as done
            grid[p.y][p.x] = '0';
            size += 1; // Increase size

            // Generating all side of point
            vector<point> sides {
                {p.x, p.y + 1},
                {p.x, p.y - 1},
                {p.x + 1, p.y},
                {p.x - 1, p.y}
            };

            for (auto& s : sides) {

                // If point is valid and new position
                if (inGrid(s) && grid[s.y][s.x] == '1') 
                {
                    // Mark position as waiting
                    grid[s.y][s.x] = '2';
                    waiting.push(s);
                }
            }
        }

        return size;
    }

    int numIslands(vector<vector<char>> _grid) {
        // Initialization
        grid = _grid;
        width = grid[0].size();
        height = grid.size();

        int numberOfIsland = 0;

        // Walk throught the entire map
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {

                // New island discovered
                if (grid[y][x] == '1') {
                    int size = removeIsland({x, y});
                    numberOfIsland += 1;
                }                 
            }
        }

        return numberOfIsland;
    }
};