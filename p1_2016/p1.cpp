#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define pi 3.1415926

//g++ p1.cpp -o p1
// ./p1 < final/rijxcolumnes.01


void printMatrix(vector<vector<double> > matrix)
{
    cout << endl;
    for(int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void writeAngles(double alpha, double beta, double gamma)
{
    ofstream myfile;
    myfile.open("fisef.out");
    myfile << alpha*360/(2*pi) << ", " << beta*360/(2*pi) << ", " << gamma*360/(2*pi);
    myfile.close();
}

void getAngles(vector<vector<double> > matrix)
{
    double alpha, beta, gamma;
    beta = -asin(matrix[2][0]);
    alpha = acos(matrix[0][0]/cos(beta));
    if(sin(alpha)*cos(beta) - matrix[1][0] < 0.0001);
    else alpha *= -1;
    gamma = acos(matrix[2][2]/cos(beta));
    if (sin(gamma)*cos(beta) - matrix[2][1] < 0.0001);
    else gamma = pi - gamma;

    writeAngles(alpha, beta, gamma);

    cout << "Final angles: " << alpha*360/(2*pi) << ", " << beta*360/(2*pi) << ", " << gamma*360/(2*pi) << endl;
}


int main()
{
    std::cout.precision(10);

    vector<vector<double> > matrix(3, vector<double>(3));

    int row = 3;

    for(int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            string s;
            cin >> s;
            s = s.substr (0,s.length()-1);

            //cout << s;
            matrix[i][j] = atof(s.c_str());
        }
        //cout << endl;
    }

    printMatrix(matrix);
    getAngles(matrix);

}
