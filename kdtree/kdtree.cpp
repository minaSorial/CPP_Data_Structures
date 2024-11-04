#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <memory>
#include <initializer_list>

using namespace std;

// A generic Point structure that can handle any numeric type
template <typename T>
struct Point {
    vector<T> coordinates;

    // Constructor that initializes a point with given coordinates
    Point(initializer_list<T> coords) : coordinates(coords) {}

    // Calculates Euclidean distance between this point and another point
    T distance(const Point<T>& other) const {
        T dist = 0;
        for (size_t i = 0; i < coordinates.size(); i++) {
            dist += (coordinates[i] - other.coordinates[i]) * (coordinates[i] - other.coordinates[i]);
        }
        return sqrt(dist);
    }
};

// A node structure in the k-d tree, containing a point and unique pointers to left and right children
template <typename T>
struct Node {
    Point<T> point;
    unique_ptr<Node<T>> left, right;

    // Constructor initializes a node with a given point
    Node(const Point<T>& pt) : point(pt), left(nullptr), right(nullptr) {}
};

// Recursive function to build the k-d tree
template <typename T>
unique_ptr<Node<T>> buildKDTree(vector<Point<T>>& points, int depth = 0) {
    if (points.empty()) return nullptr;

    // Determine the dimension (axis) to split on, based on current depth
    int axis = depth % points[0].coordinates.size();

    // Sort points by the selected dimension
    sort(points.begin(), points.end(), [axis](const Point<T>& a, const Point<T>& b) {
        return a.coordinates[axis] < b.coordinates[axis];
        });

    // Find the median point, which will be the root of the current subtree
    int medianIdx = points.size() / 2;
    auto node = make_unique<Node<T>>(points[medianIdx]);

    // Recursively build left and right subtrees
    vector<Point<T>> leftPoints(points.begin(), points.begin() + medianIdx);
    vector<Point<T>> rightPoints(points.begin() + medianIdx + 1, points.end());

    node->left = buildKDTree(leftPoints, depth + 1);
    node->right = buildKDTree(rightPoints, depth + 1);

    return node;
}

// Helper function to search for the nearest neighbor
template <typename T>
void nearestNeighborSearch(const unique_ptr<Node<T>>& root, const Point<T>& target, int depth,
    Node<T>*& best, T& bestDist) {
    if (!root) return;

    // Calculate distance from current node to the target point
    T dist = target.distance(root->point);
    if (dist < bestDist) {
        bestDist = dist;
        best = root.get();
    }

    // Determine which side of the split to explore first
    int axis = depth % target.coordinates.size();
    const unique_ptr<Node<T>>& nextBranch = (target.coordinates[axis] < root->point.coordinates[axis])
        ? root->left : root->right;
    const unique_ptr<Node<T>>& oppositeBranch = (target.coordinates[axis] < root->point.coordinates[axis])
        ? root->right : root->left;

    // Recursively search in the chosen branch
    nearestNeighborSearch(nextBranch, target, depth + 1, best, bestDist);

    // Check if we need to explore the opposite branch
    if (abs(target.coordinates[axis] - root->point.coordinates[axis]) < bestDist) {
        nearestNeighborSearch(oppositeBranch, target, depth + 1, best, bestDist);
    }
}

// Function to find the nearest neighbor for a given target point
template <typename T>
Point<T> findNearestNeighbor(const unique_ptr<Node<T>>& root, const Point<T>& target) {
    Node<T>* best = nullptr;
    T bestDist = numeric_limits<T>::infinity();
    nearestNeighborSearch(root, target, 0, best, bestDist);
    return best ? best->point : Point<T>({});
}

template <typename T>
void insert(unique_ptr<Node<T>>& root, const Point<T>& point, int depth = 0) {
    if (!root) {
        root = make_unique<Node<T>>(point);
        return;
    }

    int axis = depth % point.coordinates.size();
    if (point.coordinates[axis] < root->point.coordinates[axis]) {
        insert(root->left, point, depth + 1);
    }
    else {
        insert(root->right, point, depth + 1);
    }
}

template <typename T>
Node<T>* find(const unique_ptr<Node<T>>& root, const Point<T>& target, int depth = 0) {
    if (!root) return nullptr;

    if (root->point.coordinates == target.coordinates) {
        return root.get();
    }

    int axis = depth % target.coordinates.size();
    if (target.coordinates[axis] < root->point.coordinates[axis]) {
        return find(root->left, target, depth + 1);
    }
    else {
        return find(root->right, target, depth + 1);
    }
}

template <typename T>
void printKDTree(const unique_ptr<Node<T>>& root, int depth = 0, bool isLeft = true) {
    if (!root) return;

    // Print indentation based on depth to create a tree-like structure
    for (int i = 0; i < depth - 1; i++) {
        cout << "│   ";
    }
    if (depth > 0) {
        cout << (isLeft ? "├── " : "└── ");
    }

    // Display the coordinates of the point at this node
    cout << "(";
    for (size_t i = 0; i < root->point.coordinates.size(); i++) {
        cout << root->point.coordinates[i];
        if (i < root->point.coordinates.size() - 1) cout << ", ";
    }
    cout << ")\n";

    // Recursively print the left and right subtrees with updated depth and branch indicators
    if (root->left || root->right) {  // Only print if there are children
        if (root->left) {
            printKDTree(root->left, depth + 1, true);
        }
        else {
            // Print placeholder for empty left child
            for (int i = 0; i < depth; i++) cout << "│   ";
            cout << "├── (empty)\n";
        }

        if (root->right) {
            printKDTree(root->right, depth + 1, false);
        }
        else {
            // Print placeholder for empty right child
            for (int i = 0; i < depth; i++) cout << "│   ";
            cout << "└── (empty)\n";
        }
    }
}





int main() {
    // Define some initial points
    vector<Point<double>> points = {
        {2.1, 3.1},
        {5.4, 7.8},
        {1.3, 4.5},
        {8.1, 3.2},
        {6.3, 2.8}
    };

    // Build the initial k-d Tree
    auto root = buildKDTree(points);

    // Insert a new point into the tree
    Point<double> newPoint = { 3.5, 4.2 };
    insert(root, newPoint);

    // Visualize the tree structure
    cout << "k-d Tree structure:\n";
    printKDTree(root);

    return 0;
}

