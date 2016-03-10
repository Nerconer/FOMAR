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
// ./p1 < final/prova


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

void checkAngles(double a,double b,double c){

    vector<vector<double> > RotationMatrix(3, vector<double>(3));

    RotationMatrix[0][0] = cos(b)*cos(c);
    RotationMatrix[0][1] = -sin(c)*cos(b);
    RotationMatrix[0][2] = sin(b);

    RotationMatrix[1][0] = sin(a)*sin(b)*cos(c)+cos(a)*sin(c);
    RotationMatrix[1][1] = -sin(a)*sin(b)*sin(c)+cos(a)*cos(c);
    RotationMatrix[1][2] = -sin(a)*cos(b);

    RotationMatrix[2][0] = -cos(a)*sin(b)*cos(c) + sin(a)*sin(c);
    RotationMatrix[2][1] = sin(b)*cos(a)*sin(c)+sin(a)*cos(c);
    RotationMatrix[2][2] = cos(a)*cos(b);
    printMatrix(RotationMatrix);


}

void writeAngles(double alpha, double beta, double gamma)
{
    cout << "Final angles: " << alpha*360/(2*pi) << ", " << beta*360/(2*pi) << ", " << gamma*360/(2*pi) << endl;

    ofstream myfile;
    myfile.open("fisef.out");
    myfile << alpha*360/(2*pi) << ", " << beta*360/(2*pi) << ", " << gamma*360/(2*pi);
    myfile.close();
}

void getAngles(vector<vector<double> > matrix)
{
    double alpha, beta, gamma;
    beta = asin(matrix[0][2]);
    alpha = acos(matrix[2][2]/cos(beta));
    if(-sin(alpha)*cos(beta) - matrix[1][2] < 0.05);
    else alpha *= -1;
    gamma = -asin(matrix[0][1]/cos(beta));
    if (-sin(gamma)*cos(beta) - matrix[0][1] < 0.05);
    else gamma = pi - gamma;

    writeAngles(alpha, beta, gamma);
    checkAngles(alpha,beta,gamma);
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
            matrix[j][i] = atof(s.c_str());
        }
        //cout << endl;
    }

    printMatrix(matrix);
    getAngles(matrix);

}

