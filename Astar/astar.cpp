#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <functional>

using namespace std;

struct Node {
    int x, y; // Coordinates
    double g; // Cost from start to current node
    double h; // Heuristic cost estimate to goal
    double f; // Total cost (g + h)

    Node(int x, int y, double g, double h) : x(x), y(y), g(g), h(h), f(g + h) {}

    // Overloading < operator for priority queue
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

// Heuristic function (Euclidean distance)
double heuristic(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// A* algorithm
vector<pair<int, int>> astar(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    int cols = grid[0].size();
    priority_queue<Node, vector<Node>, greater<Node>> openSet;
    unordered_map<int, unordered_map<int, double>> gScore;
    unordered_map<int, unordered_map<int, pair<int, int>>> cameFrom;

    // Initialize gScore and add start node to openSet
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            gScore[i][j] = numeric_limits<double>::infinity();
        }
    }
    gScore[start.first][start.second] = 0.0;
    openSet.emplace(start.first, start.second, 0.0, heuristic(start.first, start.second, goal.first, goal.second));

    vector<pair<int, int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }; // 4 possible movements

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        // If we reached the goal, reconstruct the path
        if (current.x == goal.first && current.y == goal.second) {
            vector<pair<int, int>> path;
            pair<int, int> step = { current.x, current.y };
            while (cameFrom.count(step.first) && cameFrom[step.first].count(step.second)) {
                path.push_back(step);
                step = cameFrom[step.first][step.second];
            }
            path.push_back(start); // Add the start node to the path
            reverse(path.begin(), path.end()); // Reverse the path
            return path;
        }

        // Explore neighbors
        for (const auto& dir : directions) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 0) {
                double tentativeGScore = current.g + 1; // Assuming uniform cost for simplicity

                // Only consider this new path if it's better
                if (tentativeGScore < gScore[newX][newY]) {
                    cameFrom[newX][newY] = { current.x, current.y };
                    gScore[newX][newY] = tentativeGScore;
                    double h = heuristic(newX, newY, goal.first, goal.second);
                    openSet.emplace(newX, newY, tentativeGScore, h);
                }
            }
        }
    }

    return {}; // Return an empty path if no path is found
}

// Function to print the path
void printPath(const vector<pair<int, int>>& path) {
    for (const auto& p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int, int> start = { 0, 0 };
    pair<int, int> goal = { 4, 4 };

    vector<pair<int, int>> path = astar(grid, start, goal);

    if (!path.empty()) {
        cout << "Path found: ";
        printPath(path);
    }
    else {
        cout << "No path found." << endl;
    }

    return 0;
}
