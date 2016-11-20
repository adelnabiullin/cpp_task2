#include <iostream>
#include <vector>
#include "lrucache.hpp"
#include "sparsematrix.hpp"

using namespace std;
using std::vector;
using std::string;

// 1. первое вхождение элемента в вектор
// return: индекс, либо size, если такого нет
int find(const vector<string>&, const string&);

// 2. заменить каждое вхождение элемента
void replace(vector<string>&, const string&, const string&);

// 3. удалить первое вхождение элемента в векторе
template <typename T> void delete_elem(vector<T>&, const T&);

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

    // 3. test delete
    str1 = "el2";
    vect1 = { "el1", "el2", "el2", "el3", "el1", "el4", "el3", "el1" };
    cout << "\nTask 3:\n";
    delete_elem(vect1, str1);
    for (vector<string>::iterator it = vect1.begin(); it < vect1.end(); it++)
        cout << *it << ' ';
    cout << endl;

    // 4. test LRUcache
    cout << "\nTask 4:";
    lru_cache<int, int> cache1(10);
    cache1.put(1, 2);
    cache1.put(2, 4);
    cache1.put(3, 6);
    cache1.put(2, 7);
    cache1.put(4, 2);
    cache1.get(3);
    try {
        cache1.get(5);
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    cache1.put(5, 0);

    // 5. test sparse matrix
    cout << "\nTask 5:\n";
    sparse_matrix matrix1;
    matrix1.put(0, 0, 2.2);
    matrix1.put(0, 2, 7);
    matrix1.put(2, 1, 2.3);
    cout << matrix1;

    return 0;
}

int find(const vector<string> &a_vector, const string &target) {
    int i = 0;
    for (vector<string>::const_iterator it = a_vector.begin(); it < a_vector.end(); it++, i++)
        if (it->compare(target) == 0)
            return i;
    return a_vector.size();
}

void replace(vector<string> &a_vector, const string &old_item, const string &new_item) {
    for (vector<string>::iterator it = a_vector.begin(); it < a_vector.end(); it++)
        if (it->compare(old_item) == 0)
            *it = new_item;
}

template <typename T> void delete_elem(vector<T> &a_vector, const T &target) {
    for (vector<string>::iterator it = a_vector.begin(); it < a_vector.end(); it++)
        if ((*it) == target) {
            a_vector.erase(it);
            return;
        }
}