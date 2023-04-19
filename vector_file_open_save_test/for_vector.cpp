
#include <iostream>
#include <vector>


std::vector<std::vector<double>> vec_waypoints = { {1.5, 1.6, 1.7}, {0.1, 0.2, 0.3, 0.4} };
double x, y, z, ox, oy, oz, ow;

int main(int argc, char** argv) {
    int turn = 0;
    for (std::vector<double> waypoint : vec_waypoints) {
        if(turn == 0) {
            x = waypoint[0];
            y = waypoint[1];
            z = waypoint[2];
        } else {
            ox = waypoint[0];
            oy = waypoint[1];
            oz = waypoint[2];
            ow = waypoint[3];
        }
        // for (int i=0; i < waypoint.size(); i++) {
        //     // std::cout << waypoint[i] << " ";
        
        // }
        turn = 1;
        std::cout << turn << std::endl;
    }

    std::cout <<  "result:  " << std::endl;
    std::cout <<  "x: " << x << std::endl;
    std::cout <<  "y: " << y << std::endl;
    std::cout <<  "z: " << z << std::endl;
    std::cout <<  "ox: " << ox << std::endl;
    std::cout <<  "oy: " << oy << std::endl;
    std::cout <<  "oz: " << oz << std::endl;
    std::cout <<  "ow: " << ow << std::endl;

    return 0;
}


