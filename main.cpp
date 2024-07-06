#include "henon.hpp"
#include<vector>
#include <string>
#include<iostream>
#include<algorithm>
#include<fstream>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    double row{0};
    while (row < 0.9){
        std::vector<Point> point_vec = henon_iterate(Point{row, 0}, 2*M_PI*0.2525, 600);
        std::string filename = (std::to_string(row) + ".txt");
        std::ofstream file;
        file.open(filename);
        std::for_each(point_vec.begin(), point_vec.end(), [&](Point p){
            file << p.x << " " << p.y << '\n';
        });  
        file.close();        
        row += 0.1;
    }
}

