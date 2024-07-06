#include "henon.hpp"
#include <string>
#include<iostream>
#include<fstream>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    std::string filename = ("data.txt");
    std::ofstream file;
    file.open(filename);
    
    double row{0.1};
    int n_iter{600};
    double angle{0.4};

    while (row < 0.6){
        Point start_p{row,0};
        for (int iter = 0; iter < n_iter; iter++)
        {
            file << start_p.x << ";" << start_p.y << '\n';
            start_p = henon(start_p, 2*M_PI*angle);
            if (start_p.x > 1 || start_p.y > 1)
            {
                break;
            }
            
        }
        
        row += 0.05;
    }
    
    file.close();        
}

