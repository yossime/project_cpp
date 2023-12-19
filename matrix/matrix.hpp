#pragma once


namespace Eigen
{
    class matrixinsert;
    class matrix
    {
    public:
        matrix(unsigned int row, unsigned int column = 0);
        ~matrix();

        void becomezero();
        bool operator==(const Eigen::matrix &m1);
        void operator=(const Eigen::matrix &m1);
        void operator+=(const Eigen::matrix &m1);
        void operator-=(const Eigen::matrix &m1);
        matrixinsert operator<<(double input);
        matrix operator*(const Eigen::matrix &m1);
        void operator*=(int num);
        double &operator()(unsigned int i, unsigned int j);
        void print();
        matrix operator+(const Eigen::matrix &m);
        matrix operator-(const Eigen::matrix &m);
        unsigned int getrow();
        unsigned int col();

    private:
        unsigned int rows;
        unsigned int columns;
        double *values;
    };

    class matrixinsert
    {
    public:
        matrixinsert(matrix &m, double values);

        Eigen::matrixinsert &operator,(double values);

    private:
        matrix & m_matrix;
        double m_rows{0};
        double m_cols{0};
    };

}
