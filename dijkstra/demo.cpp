#include <iostream>
#include <vector>

std::vector<int> dijkstra_search(const std::vector<std::vector<int>>& matrix) {
    size_t start_node = 0;

    // set -1 unvisited
    std::vector<int> visited_nodes(matrix.size(), -1);
    std::vector<int> shortest_path(matrix[start_node]);

    visited_nodes[start_node] = 0;


    for(size_t i = 0; i < matrix.size()-1; ++i) {
        // set start value
        std::pair<size_t, int> next_line{};

        for(size_t j = 0; j < matrix.size(); ++j) {
            if(shortest_path[j] > 0 && shortest_path[j] < next_line.second && visited_nodes[j] == -1) {
                next_line.first = j;
                next_line.second = shortest_path[j];
                visited_nodes[j] = 0;
            } 
        }        

        for(size_t elem_id = 0; elem_id < matrix.size(); ++elem_id) {
            if(matrix[next_line.first][elem_id] > 0 && matrix[next_line.first][elem_id] + next_line.second < shortest_path[elem_id]) {
                shortest_path[elem_id] = next_line.second + matrix[next_line.first][elem_id];
            }
        }

    }
    




    return shortest_path;
}






void put_elem(std::vector<int>& obj, size_t num) {
    int number;
    for(size_t i = 0; i < num; ++i) {    
        std::cin >> number; 
        obj.push_back(number);
    }
}
 


int main() {
    std::vector<std::vector<int>> adj_matrix;

    // size_t n_rows;

    // std::cout << "Enter number of rows" << '\n';
    // std::cin >> n_rows;
    
    // std::vector<int> line;
    // for(size_t i = 0; i < n_rows; ++i) {
    //     put_elem(line, n_rows);
    //     adj_matrix.push_back(std::move(line));
    // }

    adj_matrix.push_back(std::vector<int>{0, 7, 5, 2, 0, 0});
    adj_matrix.push_back(std::vector<int>{7, 0, 0, 0, 3, 0});
    adj_matrix.push_back(std::vector<int>{5, 0, 0, 10, 4, 0});
    adj_matrix.push_back(std::vector<int>{2, 0, 10, 0, 0, 2});
    adj_matrix.push_back(std::vector<int>{0, 3, 4, 0, 0, 6});
    adj_matrix.push_back(std::vector<int>{0, 8, 0, 2, 6, 0});


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