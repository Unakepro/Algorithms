#ifndef DIJKSTRA
#define DIJKSTRA

#include <iostream>
#include <vector>

std::vector<int> dijkstra_search(const std::vector<std::vector<int>>& matrix, size_t start_node) {

    std::vector<int> visited_nodes(matrix.size(), -1);
    std::vector<int> shortest_path(matrix[start_node]);

    visited_nodes[start_node] = 0;


    std::pair<size_t, int> next_line{0, -1};
    for(size_t i = 0; i < matrix.size()-1; ++i) {

        for(size_t j = 0; j < matrix.size(); ++j) {
            if(visited_nodes[j] == -1 && shortest_path[j] > 0 && (next_line.second == -1 || shortest_path[j] < next_line.second)) {
                next_line.first = j;
                next_line.second = shortest_path[j];
            } 
        }        
        
        visited_nodes[next_line.first] = 0;
        for(size_t elem_id = 0; elem_id < matrix.size(); ++elem_id) {
            if(matrix[next_line.first][elem_id] > 0 && matrix[next_line.first][elem_id] + next_line.second < shortest_path[elem_id]) {
                shortest_path[elem_id] = next_line.second + matrix[next_line.first][elem_id];
            }
            if(matrix[next_line.first][elem_id] > 0 && elem_id != start_node && shortest_path[elem_id] == 0) {
                shortest_path[elem_id] = next_line.second + matrix[next_line.first][elem_id];
            }
        }
        next_line.second = -1;
    }

    return shortest_path;
}

#endif