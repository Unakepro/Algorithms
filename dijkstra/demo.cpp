#include <iostream>
#include <vector>
#include "dijkstra.hpp"


int main() {
    std::vector<std::vector<int>> adj_matrix_test1;

    adj_matrix_test1.push_back(std::vector<int>{0, 7, 5, 2, 0, 0});
    adj_matrix_test1.push_back(std::vector<int>{7, 0, 0, 0, 3, 0});
    adj_matrix_test1.push_back(std::vector<int>{5, 0, 0, 10, 4, 0});
    adj_matrix_test1.push_back(std::vector<int>{2, 0, 10, 0, 0, 2});
    adj_matrix_test1.push_back(std::vector<int>{0, 3, 4, 0, 0, 6});
    adj_matrix_test1.push_back(std::vector<int>{0, 8, 0, 2, 6, 0});
    
    for(auto line: adj_matrix_test1) {
        for (auto elem: line) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "\nShortest path: \n";

    for(auto elem: dijkstra_search(adj_matrix_test1, 0)) {
        std::cout << elem << " ";
    }
    std::cout << "\n\n";

    std::vector<std::vector<int>> adj_matrix_test2;

    adj_matrix_test2.push_back(std::vector<int>{ 0, 4, 0, 0, 0, 0, 0, 8, 0 });
    adj_matrix_test2.push_back(std::vector<int>{ 4, 0, 8, 0, 0, 0, 0, 11, 0 });
    adj_matrix_test2.push_back(std::vector<int>{ 0, 8, 0, 7, 0, 4, 0, 0, 2 });
    adj_matrix_test2.push_back(std::vector<int>{ 0, 0, 7, 0, 9, 14, 0, 0, 0 });
    adj_matrix_test2.push_back(std::vector<int>{ 0, 0, 0, 9, 0, 10, 0, 0, 0 });
    adj_matrix_test2.push_back(std::vector<int>{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }); 
    adj_matrix_test2.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 2, 0, 1, 6 });
    adj_matrix_test2.push_back(std::vector<int> { 8, 11, 0, 0, 0, 0, 1, 0, 7 });
    adj_matrix_test2.push_back(std::vector<int> { 0, 0, 2, 0, 0, 0, 6, 7, 0 } );


    for(auto line: adj_matrix_test2) {
        for (auto elem: line) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "\nShortest path: \n";

    for(auto elem: dijkstra_search(adj_matrix_test2, 0)) {
        std::cout << elem << " ";
    }

    return 0;
}