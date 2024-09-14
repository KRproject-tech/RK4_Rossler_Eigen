using namespace Eigen;


class Params{

	public:
		double a;
		double b;
		double c;
};



extern void RungeKutta( MatrixXd &X, double dt, Params params);



