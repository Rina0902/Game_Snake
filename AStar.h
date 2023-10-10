#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include "Snake.h"

struct Node
{
    Node* parent;
    pair<int, int> position;
    int g, h, f;

    Node(Node* parent, std::pair<int, int> position)
        : parent(parent), position(position), g(0), h(0), f(0) {}

    Node(Node* parent, pair<int, int> positions[])
        : parent(parent), g(0), h(0), f(0) {}

    bool operator==(const Node& other) const {
        return position == other.position;
    }
};


//Functions
std::vector<std::pair<int, int>> returnPath(Node* current_node, std::vector<std::vector<int>>& maze);
std::vector<std::pair<int, int>> search(std::vector<std::vector<int>>& maze, int cost, std::pair<int, int> start, std::pair<int, int> end);

