#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


int main()
{
    ifstream fin;
    fin.open("cordinates.txt");
    int count = 0;
    if (!fin.is_open()) {
        cout << "Error! File is not open\n";
		return 0;
    }
    else {
        string cordinates;
        while (!fin.eof()) {
            getline(fin, cordinates);
            stringstream ss(cordinates);
            double lat, lon;
            ss.ignore(1);
            ss >> lat;
            ss.ignore(2);
            ss >> lon;
            if ((lat >= 50 && lat <= 80) && (lon >= 20 && lon <= 45)) {
                cout << "Latitude: " << lat << ",\t Longitude: " << lon << "\n";
                count++;
            }
        }
    }
    if (count > 0) cout << count << " points included in the square bounded by coordinates: \nlatitude from 50 to 80, longitude from 20 to 45\n";
    else cout << "The obtained points are outside the square bounded by coordinates: \nlatitude from 50 to 80, longitude from 20 to 45\n";
    fin.close();
    return 0;
}
