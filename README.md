# RK4_Rossler_Eigen
Rössler equation solved by the Runge–Kutta 4th-Order Method with Eigen Library (https://eigen.tuxfamily.org/index.php?title=Main_Page) (g++, Windows).


# Code

./source/main.cpp
````
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
````

./source/RK4.cpp
````
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

````


