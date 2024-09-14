#include "Eigen/Dense"
#include "Eigen/Core"
#include <iostream>
#include <fstream>
#include "RK4.hpp"


using namespace Eigen;
using namespace std;



Params params = {	0.2,	// a
					0.2,	// b
					5.7};	// c



int main() {

	double t_max = 1000;
	double time = 0.0;
	double dt = 0.01;


    MatrixXd X(3, 1);
    X <<	1e-3,
			1e-3,
			0;

    
    ofstream ofs("./save/outdata.csv");
    ofs << "time, x1, x2, x3" << endl;

    for (time = 0; time < t_max; time += dt) {

        RungeKutta( X, dt, params);

        ofs << time << "," << X(0,0) << "," << X(1,0) << "," << X(2,0) << endl;
		//cout << time << " [s], [" << X.transpose() << "] [-]" << endl;

    }

    return 0;
}
