#include <iostream>
#include <vector>

using std::vector;
using std::string;

// первое вхождение элемента в вектор
// return: индекс, либо size, если такого нет
int find(const vector<string>, const string);

int main() {
    // 1. test find
    

    return 0;
}

int find(const vector<string> &a_vector, const string &target) {
    int size = a_vector.size(), i = 0;
    for (vector<string>::const_iterator it = a_vector.begin(); it < a_vector.end(); it++, i++) {
        if ((*it).compare(target) == 0)
            return i;
    }
    return size;
}