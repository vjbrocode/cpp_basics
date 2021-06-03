#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::cout << "PROGRAM START...\n";
    std::string fileName = "/inputfiles/SampleFile.CSV";
    ifstream in(fileName);
    vector<vector<std::string> > fields;
    std::cout << "Reading csv file...\n";
    if (in) {
        string line;

        while (getline(in, line)) {
            stringstream sep(line);
            string field;
            std::cout<< "line = " + line << "\n";
            fields.push_back(vector<std::string>());

            while (getline(sep, field, ',')) {
                //std::cout<< "field = " + field << "\n";
                fields.back().push_back(field);
            }
        }
    }
    std::cout << "##############\n";

    std::cout << "Reading vector now...\n";
    for(std::size_t i = 1; i < fields.size(); i++) {
        vector<std::string> v = fields[i];
        std::cout << "i: " + std::to_string(i) + " -> " + v[0] + " " + v[1] + " " + v[2] + "\n";
    }

    std::cout << "PROGRAM END...\n";
}
