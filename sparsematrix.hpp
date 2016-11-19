#ifndef SPARSEMATRIX_HPP
#define	SPARSEMATRIX_HPP

#include <map>
#include <utility>
#include <stdexcept>
#include <iostream>
using namespace std;

class sparse_matrix {
    map<pair<int, int>, double> m;
    int dimension;

public:

    sparse_matrix() : dimension(3) {}
    sparse_matrix(int dim) : dimension(dim) {}

    void put(const int &row, const int &column, const double &value) {
        if (row < 0 || row >= dimension || column < 0 || column >= dimension) {
            cout << "\nWrong row or column\n";
            return;
        }
        m[make_pair(row, column)] = value;
    }

    double get(const int &row, const int &column) {
        if (row < 0 || row >= dimension || column < 0 || column >= dimension) {
            throw range_error("\nWrong row or column\n");
        }
        return m.find(make_pair(row, column));
    }

    // TODO: finish cout printing
    // void operator<< ()
};

#endif