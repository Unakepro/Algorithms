#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <chrono>
#include <thread>

std::chrono::milliseconds timespan(1000); // or whatever

template <size_t side>
class Square {
    std::pair<double, double> center;
    std::pair<size_t, size_t> gf_cost{0, 0};
    bool blocked = 0;
    
    Square* parent = nullptr;


public:
    Square(std::pair<double, double> center, bool isBlocked = 0): center(center), blocked(blocked) {}

    std::pair<double, double> getCenter() const {
        return center;
    }

    bool isBlocked() const {
        return blocked;
    }

    void setParent(Square* ptr) {
        parent = ptr;
    }

    void setF(size_t h) {
        gf_cost.second = gf_cost.first + h;
    }
    
    void setG(size_t g) {
        gf_cost.first = g;
    }

    Square<side>* getParent() {
        return parent;
    }

    size_t getG() {
        return gf_cost.first;
    }

    size_t getF() {
        return gf_cost.second;
    }

    bool operator==(const Square<side>& obj) const {
        return center.first == obj.center.first && center.second == obj.center.second;
    }

};

template <size_t square_side>
class Area {
    std::vector<Square<square_side>> values;
    size_t width = 0;
    size_t height = 0;

public:
    Area(size_t width, size_t height): width(width), height(height) {
        for(size_t i = 0; i < height; ++i) {
            for(size_t j = 0; j < width; ++j) {
                values.push_back(std::pair<double, double>((j*square_side) + square_side/2.0, (i*square_side) + square_side/2.0));
            }
        }              
    }

    size_t getWidth() const {
        return width;
    }

    size_t getHeight() const {
        return height;
    }
    
    Square<square_side>* getSquare(size_t i, size_t j) {
        return &values[j * width + i];
    }
    

    bool SquareExist(const std::pair<double, double>& center) const {
        if(center.first < square_side/2.0 || center.first > width*square_side-square_side/2.0 || center.second < square_side/2.0 || center.second > height*square_side-square_side/2.0) {
            return 0;
        }
        return 1;
    }


    void add_neighbor(std::vector<Square<square_side>*>& square_values, const std::pair<double, double>& position) {
        if(SquareExist(position) && !(getSquare(position.first, position.second)->isBlocked())) {
            square_values.push_back(getSquare(position.first, position.second));
        }
    }


    std::vector<Square<square_side>*> getNeighbors(const Square<square_side>& current) {
        std::vector<Square<square_side>*> square_values;
        std::pair<double, double> neighbor;
        
        neighbor = getUpperCenter(current);
        add_neighbor(square_values, neighbor);

        neighbor = getUpperRightCenter(current);
        add_neighbor(square_values, neighbor);

        neighbor = getRightCenter(current);
        add_neighbor(square_values, neighbor);

        neighbor = getBottomRightCenter(current);
        add_neighbor(square_values, neighbor);

        neighbor = getBottomCenter(current);
        add_neighbor(square_values, neighbor);
   
        neighbor = getBottomLeftCenter(current);
        add_neighbor(square_values, neighbor);

        neighbor = getLeftCenter(current);
        add_neighbor(square_values, neighbor);

        neighbor = getUpperLeftCenter(current);
        add_neighbor(square_values, neighbor);


        return square_values;
    }



    static std::pair<double, double> getUpperCenter(const Square<square_side>& obj) {
        return std::pair<double, double>(obj.getCenter().first, obj.getCenter().second+square_side);
    }

    static std::pair<double, double> getUpperRightCenter(const Square<square_side>& obj) {
        return std::pair<double, double>(obj.getCenter().first+square_side, obj.getCenter().second+square_side);
    }

    static std::pair<double, double> getRightCenter(const Square<square_side>& obj) { 
        return std::pair<double, double>(obj.getCenter().first+square_side, obj.getCenter().second);
    }

    static std::pair<double, double> getBottomRightCenter(const Square<square_side>& obj) { 
        return std::pair<double, double>(obj.getCenter().first+square_side, obj.getCenter().second-square_side);
    }

    static std::pair<double, double> getBottomCenter(const Square<square_side>& obj) {
        return std::pair<double, double>(obj.getCenter().first, obj.getCenter().second-square_side);
    }

    static std::pair<double, double> getBottomLeftCenter(const Square<square_side>& obj) {
        return std::pair<double, double>(obj.getCenter().first-square_side, obj.getCenter().second-square_side);
    }

    static std::pair<double, double> getLeftCenter(const Square<square_side>& obj) { 
        return std::pair<double, double>(obj.getCenter().first-square_side, obj.getCenter().second);
    }

    static std::pair<double, double> getUpperLeftCenter(const Square<square_side>& obj) { 
        return std::pair<double, double>(obj.getCenter().first-square_side, obj.getCenter().second+square_side);
    }


    void print_points() {
        for(int64_t i = height-1; i >= 0; --i) {
            for(size_t j = 0; j < width; ++j) {
                std::cout << " (" << values[i*width+j].get_lu_point().first << " ; " << values[i*width+j].get_lu_point().second << ") "; 
                std::cout << " (" << values[i*width+j].get_ru_point().first << " ; " << values[i*width+j].get_ru_point().second << ") "; 
                std::cout << " (" << values[i*width+j].get_ld_point().first << " ; " << values[i*width+j].get_ld_point().second << ") "; 
                std::cout << " (" << values[i*width+j].get_rd_point().first << " ; " << values[i*width+j].get_rd_point().second << ") "; 

            }
            std::cout << "\n";
        }
    }


};

template <size_t square_size>
size_t manhattan_distance(const Square<square_size>& obj1, const Square<square_size>& obj2) {
    return std::abs(obj1.getCenter().first - obj2.getCenter().first) + std::abs(obj1.getCenter().second - obj2.getCenter().second);
}


template <size_t square_size>
size_t distance(const Square<square_size>& obj1, const Square<square_size>& obj2) {
    return std::sqrt(std::pow(obj1.getCenter().first - obj1.getCenter().first, 2) + std::pow(obj2.getCenter().second - obj1.getCenter().second, 2));
}


template <size_t square_size>
class Compare {
    public:
        bool operator()(Square<square_size>* obj1, Square<square_size>* obj2) {
            return obj1->getF() < obj2->getF();
        }
};

template <size_t square_size>
Square<square_size>* a_search(Area<square_size>& obj, std::pair<size_t, size_t> start_square, std::pair<size_t, size_t> end_square) {
    
    std::priority_queue<Square<square_size>*, std::vector<Square<square_size>*>, Compare<square_size>> open_list;
    std::set<Square<square_size>*> closed_list;

    if(start_square.first > obj.getWidth() || end_square.first > obj.getWidth()) {
        throw std::logic_error("Wrong width!");
    }

    if(start_square.first > obj.getHeight() || end_square.first > obj.getHeight()) {
        throw std::logic_error("Wrong height!");
    }

    open_list.push(obj.getSquare(start_square.first, start_square.second));

    while(true) {
        auto* current = open_list.top();
        open_list.pop();
        closed_list.insert(current);

        if(current == obj.getSquare(end_square.first, end_square.second)) {
            return current;
        }

        
        for(auto* square: obj.getNeighbors(*current)) {            
 
            bool inOpen = square->getF();
                
            size_t h = distance(*square, *obj.getSquare(end_square.first, end_square.second)) + square->getG();
            size_t g = current->getG() + distance(*current, *square);
            
            // search not optimal
            if(closed_list.find(square) != closed_list.end()) {
                continue;
            }


            if(h+g < square->getF() || !inOpen) {
                
                square->setG(g);
                square->setF(h);

                square->setParent(current);
                if(!inOpen) {
                    open_list.push(square);
                }
            }
        
            //std::this_thread::sleep_for(timespan);

        }


   }   
        
}





int main() {
    Area<1> xs(5, 4);

    std::pair<size_t, size_t> start{0, 0};
    std::pair<size_t, size_t> end{2, 2};

    //std::cout << xs.getSquare(start.first, start.second);

    // for(auto* square: xs.getNeighbors(*xs.getSquare(start.first, start.second))) {
    //     std::cout << square << ' ';
    // }

    Square<1>* result = a_search<1>(xs, start, end);

    while(result != 0) {
        std::cout << result->getCenter().first << ' ' << result->getCenter().second;
        result = result->getParent();
        std::cout << '\n';


    }
} 