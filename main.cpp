#include "henon.hpp"
#include <string>
#include<iostream>
#include<fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

int main(){
    
    int n_iter{600};
    std::vector<double> angles = {0.205};
/*     std::vector<double> angles(50);
    double start{0.2500};
    double step{0.0001};
    for (size_t i = 0; i < angles.size(); i++)
    {
        angles[i] = start + i*step;
    } */

    std::for_each(angles.begin(), angles.end(), [&](double angle){
        std::string filename = ("data/"+ std::to_string(angle) +"_data.txt");
        std::ofstream file;
        file.open(filename);

        double row{0.1};
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
    });
    
}

