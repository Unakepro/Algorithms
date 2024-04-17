#include <iostream>
#include <vector>

template <size_t side>
class Square {
    std::pair<double, double> center;

public:
    Square(std::pair<double, double> center): center(center) {}

    std::pair<double, double> get_lu_point() {
        std::pair<double, double> lu_side;
        
        lu_side.first = center.first - side/2.0;
        lu_side.second = center.second + side/2.0;

        return lu_side;
    }

    std::pair<double, double> get_ru_point() {
        std::pair<double, double> ru_side;
        
        ru_side.first = center.first + side/2.0;
        ru_side.second = center.second + side/2.0;

        return ru_side;
    }
    
    std::pair<double, double> get_ld_point() {
        std::pair<double, double> ld_side;
        
        ld_side.first = center.first - side/2.0;
        ld_side.second = center.second - side/2.0;

        return ld_side;
    }

    std::pair<double, double> get_rd_point() {
        std::pair<double, double> rd_side;
        
        rd_side.first = center.first + side/2.0;
        rd_side.second = center.second - side/2.0;

        return rd_side;
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


int main() {
    Area<1> xs(6, 2);
    xs.print_points();
}