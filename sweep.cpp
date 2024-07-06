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

    Point start_p{0.1,0};
    double angle{0};
    double end_angle{0.4};

    while (angle < end_angle)
    {
        file << start_p.x << ";" << start_p.y << '\n';
        start_p = henon(start_p, 2*M_PI*angle);
        if (start_p.x > 1 || start_p.y > 1)
        {
            break;
        }
        angle += 0.0001;
    }
    file.close();
}


