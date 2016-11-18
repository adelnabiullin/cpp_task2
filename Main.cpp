#include <iostream>
#include <vector>

using namespace std;
using std::vector;
using std::string;

// 1. первое вхождение элемента в вектор
// return: индекс, либо size, если такого нет
int find(const vector<string>&, const string&);

int main() {
    // 1. test find
    const string str1 = "el3", str2 = "el6";
    const vector<string> vect1 = { "el1", "el2", "el2", "el3", "el4", "el3", "el5" };
    cout << "Task 1:\n";
    cout << find(vect1, str1) << endl;
    cout << find(vect1, str2) << endl;

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