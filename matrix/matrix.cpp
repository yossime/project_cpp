#include "matrix.hpp"

#include <iostream>

#include <cassert>

using namespace Eigen;
using namespace std;

namespace
{
    unsigned int constractor(unsigned int row, unsigned int column)
    {
        if (column == 0)
        {
            return row;
        }
        return column;
    }

}

matrix::matrix(unsigned int row, unsigned int column)
    : rows{row}, columns{constractor(row, column)}, values{new double[rows * columns]}

{
    becomezero();
}

matrix::~matrix()
{
    delete[] values;
}

void matrix::becomezero()
{
    for (unsigned int i = 0; i < rows * columns; i++)
    {
        values[i] = 0.0;
    }
}

bool matrix::operator==(const Eigen::matrix &m1)
{
    // assert(m1);
    unsigned int i;
    if (m1.columns != columns || m1.rows != rows)
    {
        return 0;
    }
    for (i = 0; i < rows * columns; i++)
    {
        if (values[i] != m1.values[i])
        {
            return 0;
        }
    }
    return 1;
}

void matrix::operator=(const Eigen::matrix &m1)
{
    assert(m1.columns == columns && m1.rows == rows);
    for (unsigned int i = 0; i < rows * columns; i++)
    {
        values[i] = m1.values[i];
    }
}

void matrix::operator+=(const Eigen::matrix &m1)
{
    assert(m1.columns == columns && m1.rows == rows);
    for (unsigned int i = 0; i < rows * columns; i++)
    {
        values[i] += m1.values[i];
    }
}

void matrix::operator-=(const Eigen::matrix &m1)
{
    assert(m1.columns == columns && m1.rows == rows);
    for (unsigned int i = 0; i < rows * columns; i++)
    {
        values[i] -= m1.values[i];
    }
}

matrix matrix::operator*(matrix const &other)
{
    assert(columns == other.rows);
    matrix new_m(rows, other.columns);
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < other.columns; ++j)
        {
            for (std::size_t k = 0; k < columns; ++k)
            {
                new_m(i, j) += values[i * columns + k] * other.values[k * other.columns + j];
            }
        }
    }
    return new_m;
}

void matrix::operator*=(int num)
{
    for (unsigned int i = 0; i < rows * columns; i++)
    {
        values[i] *= num;
    }
}

double &matrix::operator()(unsigned int i, unsigned int j)
{
    return values[i * columns + j];
}

void matrix::print()
{
    for (unsigned int i = 0; i < rows; i++)
    {
        cout << "|" << values[i * columns];
        for (unsigned int j = 1; j < columns; j++)
        {
            cout << "," << values[i * columns + j];
        }
        cout << "|"
             << "\n";
    }
    cout << "\n";
}

matrix matrix::operator+(const Eigen::matrix &m)
{
    assert(m.columns == columns && m.rows == rows);
    matrix mat(rows, columns);
    for (unsigned int i = 0; i < rows * columns; i++)
    {
        mat.values[i] = m.values[i] + values[i];
    }
    return mat;
}

matrix matrix::operator-(const Eigen::matrix &m)
{
    assert(m.columns == columns && m.rows == rows);
    matrix mat(rows, columns);
    for (unsigned int i = 0; i < rows * columns; i++)
    {
        mat.values[i] = m.values[i] - values[i];
    }
    return mat;
}

matrixinsert matrix::operator<<(double input)
{
    return matrixinsert(*this, input);
}

unsigned int matrix::getrow()
{
    return rows;
}

unsigned int matrix::col()
{
    return columns;
}



matrixinsert::matrixinsert(matrix &m, double values)
    : m_matrix{m}
{
    m_matrix(m_rows, m_cols) = values;
}

matrixinsert &matrixinsert::operator,(double values)
{
    m_rows == m_matrix.getrow() - 1 ? m_rows = 0, m_cols++ : m_rows++;
    m_matrix(m_rows, m_cols) = values;

    return *this;
}