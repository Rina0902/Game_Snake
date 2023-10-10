#include "AStar.h"

std::vector<std::pair<int, int>> returnPath(Node* current_node, std::vector<std::vector<int>>& maze) {
    std::vector<std::pair<int, int>> path;
    int no_rows = maze.size();
    int no_columns = maze[0].size();
    std::vector<std::vector<int>> result(no_rows, std::vector<int>(no_columns, -1));
    Node* current = current_node;

    while (current != nullptr) {
        path.push_back(current->position);
        current = current->parent;
    }

    std::reverse(path.begin(), path.end());
    int start_value = 0;

    for (size_t i = 0; i < path.size(); ++i) {
        result[path[i].first][path[i].second] = start_value;
        start_value++;
    }

    return path;
}

std::vector<std::pair<int, int>> search(std::vector<std::vector<int>>& maze, int cost, std::pair<int, int> start, std::pair<int, int> end)
{
    std::set<Node*> yet_to_visit_list;
    std::set<Node*> visited_list;

    Node* start_node = new Node(nullptr, start);
    start_node->g = start_node->h = start_node->f = 0;
    Node* end_node = new Node(nullptr, end);
    end_node->g = end_node->h = end_node->f = 0;

    yet_to_visit_list.insert(start_node);

    int outer_iterations = 0;
    int max_iterations = (maze.size() / 2) * (maze.size() / 2);

    std::vector<std::pair<int, int>> move = {
        {-1, 0}, // go up
        {0, -1}, // go left
        {1, 0},  // go down
        {0, 1}   // go right
    };

    int no_rows = maze.size();
    int no_columns = maze[0].size();

    while (!yet_to_visit_list.empty()) {
        outer_iterations++;

        Node* current_node = *yet_to_visit_list.begin();

        for (Node* node : yet_to_visit_list) {
            if (node->f < current_node->f) {
                current_node = node;
            }
        }
        yet_to_visit_list.erase(current_node);
        visited_list.insert(current_node);

        if (*current_node == *end_node)
        {
            return returnPath(current_node, maze);
        }

        std::vector<Node*> children;

        for (std::pair<int, int> new_position : move) {
            std::pair<int, int> node_position = { current_node->position.first + new_position.first, current_node->position.second + new_position.second };

            if (node_position.first < 0 || node_position.first >= no_rows || node_position.second < 0 || node_position.second >= no_columns) {
                continue;
            }

            if (maze[node_position.first][node_position.second] != 0) {
                continue;
            }

            Node* new_node = new Node(current_node, node_position);

            children.push_back(new_node);
        }

        for (Node* child : children) {
            if (visited_list.find(child) != visited_list.end()) {
                continue;
            }

            child->g = current_node->g + cost;
            child->h = (child->position.first - end_node->position.first) * (child->position.first - end_node->position.first) + (child->position.second - end_node->position.second) * (child->position.second - end_node->position.second);
            child->f = child->g + child->h;

            if (yet_to_visit_list.find(child) != yet_to_visit_list.end() && child->g > current_node->g) {
                continue;
            }

            yet_to_visit_list.insert(child);
        }
    }

    std::cout << "No path found" << std::endl;
    std::vector<std::pair<int, int>> empty_path;
    return empty_path;
}

