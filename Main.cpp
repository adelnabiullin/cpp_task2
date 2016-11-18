#include <iostream>
#include <vector>

using namespace std;
using std::vector;
using std::string;

// 1. первое вхождение элемента в вектор
// return: индекс, либо size, если такого нет
int find(const vector<string>&, const string&);

// 2. заменить каждое вхождение элемента
void replace(vector<string>&, const string&, const string&);

int main() {
    // 1. test find
    string str1 = "el3", str2 = "el6";
    vector<string> vect1 = { "el1", "el2", "el2", "el3", "el4", "el3", "el5" };
    cout << "Task 1:\n";
    cout << find(vect1, str1) << endl;
    cout << find(vect1, str2) << endl;

    // 2. test replace
    str1 = "el1", str2 = "el0";
    vect1 = { "el1", "el2", "el2", "el3", "el1", "el4", "el3", "el1" };
    cout << "\nTask 2:\n";
    replace(vect1, str1, str2);
    for (vector<string>::iterator it = vect1.begin(); it < vect1.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}

int find(const vector<string> &a_vector, const string &target) {
    int i = 0;
    for (vector<string>::const_iterator it = a_vector.begin(); it < a_vector.end(); it++, i++) {
        if ((*it).compare(target) == 0)
            return i;
    }
    return a_vector.size();
}

void replace(vector<string> &a_vector, const string &old_item, const string &new_item) {
    for (vector<string>::iterator it = a_vector.begin(); it < a_vector.end(); it++) {
        if ((*it).compare(old_item) == 0)
            *it = new_item;
    }
}