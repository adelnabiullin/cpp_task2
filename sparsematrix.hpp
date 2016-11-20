#ifndef SPARSEMATRIX_HPP
#define	SPARSEMATRIX_HPP

#include <map>
#include <utility>
#include <stdexcept>
#include <iostream>
using namespace std;

class sparse_matrix {
public:
    typedef map<pair<int, int>, double> arr_map;

    sparse_matrix() : dimension(3) {}
    sparse_matrix(int dim) : dimension(dim) {}

    void put(const int &row, const int &column, const double &value) {
        if (row < 0 || row >= dimension || column < 0 || column >= dimension) {
            cout << "\nWrong row or column\n";
            return;
        }
        m[make_pair(row, column)] = value;
    }

    double get(const int &row, const int &column) const {
        if (row < 0 || row >= dimension || column < 0 || column >= dimension) {
            throw range_error("\nWrong row or column\n");
        }
        arr_map::const_iterator it;
        it = m.find(make_pair(row, column));
        if (it != m.end()) {
            return it->second;
        }
        return 0;
    }

    friend ostream& operator<<(ostream &os, const sparse_matrix &sm) {
        for (int i = 0; i < sm.dimension; ++i) {
            for (int j = 0; j < sm.dimension; ++j) {
                os << sm.get(i, j) << ' ';
            }
            os << endl;
        }
        return os;
    }

private:
    arr_map m;
    int dimension;
};

#endif