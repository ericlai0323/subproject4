
#include <iostream>
#include <Eigen/Dense>

class KalmanFilter {
public:
    KalmanFilter(double dt, const Eigen::VectorXd& x0, const Eigen::MatrixXd& P0,
                 const Eigen::MatrixXd& F, const Eigen::MatrixXd& Q, const Eigen::MatrixXd& H,
                 const Eigen::MatrixXd& R);

    void predict();
    void update(const Eigen::VectorXd& z);

private:
    double dt_;
    Eigen::VectorXd x_;
    Eigen::MatrixXd P_;
    Eigen::MatrixXd F_;
    Eigen::MatrixXd Q_;
    Eigen::MatrixXd H_;
    Eigen::MatrixXd R_;
};


