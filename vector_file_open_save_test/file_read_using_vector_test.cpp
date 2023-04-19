#include <fstream>
#include <iostream>
#include <vector>


std::string file_path = "path/wp_pose";
std::vector<std::vector<double>> vec_waypoints = { {1.0, 1.5, 0.0}, {0.1, 0.2, 0.3, 0.9} };
std::vector<double> readTxt {};

bool readFile() {
    std::fstream wpFile;
    
    // geometry_msgs::PoseWithCovarianceStamped current_pose;
    wpFile.open(file_path, std::ios::in); 
    if (wpFile.is_open()) {
        std::string aline;
            while (getline(wpFile, aline, ',')) { // until no line, it loops
            std::cout << aline << "\n";
            readTxt.push_back(std::stod(aline));
        }

        wpFile.close();
    } else {
        return false;
    }
    return true;
}

int main() {

    readFile();

    for (double num : readTxt) {
        std::cout << num << "\n";
    }
    return 0;
}