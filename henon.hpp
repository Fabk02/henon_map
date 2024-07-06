#include <iostream>
#include <vector>

#ifndef HENON_HPP
#define HENON_HPP

struct Point
{
    double x{};
    double y{};
};

Point rotate(double x, double y, double angle){
    double end_x {x*cos(angle) + y*sin(angle)};
    double end_y {-x*sin(angle) + y*cos(angle)};
    Point result{end_x,end_y};
    return result;
}

Point rotate(Point p, double angle){
    return rotate(p.x, p.y, angle);
}

Point henon(double x, double y, double angle){
    return rotate(x, y + pow(x,2), angle);
}

Point henon(Point p, double angle){
    return henon(p.x, p.y, angle);
}

std::vector<Point> henon_iterate(Point start_p, double angle, int n_iter){
    std::vector<Point> points_vec = {start_p};
    for (size_t iter = 0; iter < n_iter; iter++)
    {
        points_vec.push_back(henon(points_vec[iter], angle));
        if (points_vec[iter+1].x > 1 || points_vec[iter+1].y > 1)
        {
            break;
        }
    }
    return points_vec;
}

#endif