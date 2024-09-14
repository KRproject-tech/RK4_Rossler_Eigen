#include "Eigen/Dense"
#include "Eigen/Core"

#include "RK4.hpp"



using namespace Eigen;

MatrixXd func( MatrixXd X, Params params){

	double a, b, c;
	MatrixXd dt_X(3,1);

	a = params.a;
	b = params.b;
	c = params.c;

	dt_X << -X(1,0) - X(2,0),
			X(0,0) + a*X(1,0),
			b + X(0,0)*X(2,0) - c*X(2,0);

	return dt_X;
}

void RungeKutta( MatrixXd &X, double dt, Params params) {

    MatrixXd k1 = func( X, params);
    MatrixXd k2 = func(X + 0.5*k1*dt, params);
    MatrixXd k3 = func(X + 0.5*k2*dt, params);
    MatrixXd k4 = func(X + k3*dt, params);
    MatrixXd k = (k1 + 2.0*k2 + 2.0*k3 + k4)*dt / 6.0;
    X = X + k;
}
