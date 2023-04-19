#include <fstream>
#include <iostream>
#include <vector>



std::string file_path = "path/wp_pose";
std::vector<std::vector<double>> vec_waypoints = { {1.0, 1.5, 0.0}, {0.1, 0.2, 0.3, 0.9} };


bool openFile() {
        std::fstream wpFile;
        // wpFile.open(this->originFileName, std::ios::in); //ios::in read
        wpFile.open(file_path, std::ios::out);  // ios::out write
        if (wpFile.is_open()) {
            for(std::vector<double> current_pose : vec_waypoints) {
                for(int i=0; i < current_pose.size(); i++) {
                    wpFile << std::to_string(current_pose.at(i)) << ",";
                }
            }
            wpFile.close();
        } else {
            std::cout << "failed to save file\n";
            return false;
        }
        std::cout << file_path << " file is saved" << std::endl;

        return true;
    }

int main() {

    openFile();

    return 0;
}