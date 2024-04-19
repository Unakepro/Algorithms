#include <iostream>
#include <vector>
#include <queue>

template <size_t side>
class Square {
    std::pair<double, double> center;
    bool blocked = 0;
    size_t f_cost = 0;

public:
    Square(std::pair<double, double> center, bool isBlocked = 0): center(center), blocked(blocked), f_cost(0) {}

    std::pair<double, double> getCenter() const {
        return center;
    }

    bool isBlocked() const {
        return blocked;
    }

    void setF(size_t f) {
        f_cost = f;
    }


    bool operator==(const Square<side>& obj) const {
        return center.first == obj.center.first && center.second == obj.center.second;
    }

    bool operator<(const Square<side>& obj) const {
        return f_cost < obj.f_cost;
    }

    bool operator>(const Square<side>& obj) const {
        return obj < *this;
    }


    // std::pair<double, double> get_lu_point() {
    //     std::pair<double, double> lu_side;
        
    //     lu_side.first = center.first - side/2.0;
    //     lu_side.second = center.second + side/2.0;

    //     return lu_side;
    // }

    // std::pair<double, double> get_ru_point() {
    //     std::pair<double, double> ru_side;
        
    //     ru_side.first = center.first + side/2.0;
    //     ru_side.second = center.second + side/2.0;

    //     return ru_side;
    // }
    
    // std::pair<double, double> get_ld_point() {
    //     std::pair<double, double> ld_side;
        
    //     ld_side.first = center.first - side/2.0;
    //     ld_side.second = center.second - side/2.0;

    //     return ld_side;
    // }

    // std::pair<double, double> get_rd_point() {
    //     std::pair<double, double> rd_side;
        
    //     rd_side.first = center.first + side/2.0;
    //     rd_side.second = center.second - side/2.0;

    //     return rd_side;
    // }
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
    
    const Square<square_side>& getSquare(size_t i, size_t j) const {
        return values[j * width + i];
    }
    

    bool SquareExist(const std::pair<double, double>& center) const {
        if(center.first < square_side/2.0 || center.first > width*square_side-square_side/2.0 || center.second < square_side/2.0 || center.second > height*square_side-square_side/2.0) {
            return 0;
        }
        return 1;
    }


    void add_neighbor(std::vector<Square<square_side>&>& square_values, const std::pair<double, double>& position) {
        if(SquareExist(position) && !(getSquare(position).isBlocked())) {
            square_values.push_back(getSquare(position));
        }
    }


    std::vector<Square<square_side>&> getNeighbors() {
        std::vector<Square<square_side>&> square_values(8);
        std::pair<double, double> neighbor;
        
        neighbor = getUpperCenter();
        add_neighbor(square_values, neighbor);

        neighbor = getUpperRightCenter();
        add_neighbor(square_values, neighbor);

        neighbor = getRightCenter();
        add_neighbor(square_values, neighbor);

        neighbor = getBottomRightCenter();
        add_neighbor(square_values, neighbor);

        neighbor = getBottomCenter();
        add_neighbor(square_values, neighbor);
   
        neighbor = getBottomLeftCenter();
        add_neighbor(square_values, neighbor);

        neighbor = getLeftCenter();
        add_neighbor(square_values, neighbor);

        neighbor = getUpperLeftCenter();
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
void a_search(const Area<square_size>& obj, std::pair<size_t, size_t> start_square, std::pair<size_t, size_t> end_square) {
    
    
    std::priority_queue<Square<square_size>&, std::greater<Square<square_size>&>> open_list;
    std::vector<const Square<square_size>&> closed_list;


    if(start_square.first > obj.getWidth() || end_square.first > obj.getWidth()) {
        throw std::logic_error("Wrong width!");
    }

    if(start_square.first > obj.getHeight() || end_square.first > obj.getHeight()) {
        throw std::logic_error("Wrong height!");
    }

    size_t start_index = start_square.second * start_square.first + start_square.first;


    while(true) {
        auto current = open_list.dequeue();
        closed_list.push_back(current);

        if(current == end_square) {
            return ;
        }

        for(auto square: obj.getNeighbors()) {

        
        }   
        

    }
}



int main() {
    Area<1> xs(5, 4);

    Square<1> one(std::pair<double, double>(1, 2));
    Square<1> two(std::pair<double, double>(1, 1));
}