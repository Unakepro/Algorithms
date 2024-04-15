#include <iostream>
#include <vector>

std::vector<int> dijkstra_search(const std::vector<std::vector<int>>& matrix) {
    size_t start_node = 0;

    // set -1 unvisited
    std::vector<int> visited_nodes(matrix.size(), -1);
    std::vector<int> shortest_path(matrix[start_node]);

    visited_nodes[start_node] = 0;


    std::pair<size_t, int> next_line{0, -1};
    for(size_t i = 0; i < matrix.size()-1; ++i) {
        // set start value

        for(size_t j = 0; j < matrix.size(); ++j) {
            if(visited_nodes[j] == -1 && shortest_path[j] > 0 && (next_line.second == -1 || shortest_path[j] < next_line.second)) {
                next_line.first = j;
                next_line.second = shortest_path[j];
            } 
            //std::cout << next_line.second << ' ';
        }        
        //std::cout << "\n\n";
        
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



 


int main() {
    std::vector<std::vector<int>> adj_matrix;

    adj_matrix.push_back(std::vector<int>{ 0, 4, 0, 0, 0, 0, 0, 8, 0 });
    adj_matrix.push_back(std::vector<int>{ 4, 0, 8, 0, 0, 0, 0, 11, 0 });
    adj_matrix.push_back(std::vector<int>{ 0, 8, 0, 7, 0, 4, 0, 0, 2 });
    adj_matrix.push_back(std::vector<int>{ 0, 0, 7, 0, 9, 14, 0, 0, 0 });
    adj_matrix.push_back(std::vector<int>{ 0, 0, 0, 9, 0, 10, 0, 0, 0 });
    adj_matrix.push_back(std::vector<int>{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }); 
    adj_matrix.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 2, 0, 1, 6 });
    adj_matrix.push_back(std::vector<int> { 8, 11, 0, 0, 0, 0, 1, 0, 7 });
    adj_matrix.push_back(std::vector<int> { 0, 0, 2, 0, 0, 0, 6, 7, 0 } );


    for(auto line: adj_matrix) {
        for (auto elem: line) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "\nShortest path: \n";

    for(auto elem: dijkstra_search(adj_matrix)) {
        std::cout << elem << " ";
    }

    return 0;
}