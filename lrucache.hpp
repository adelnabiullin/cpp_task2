#ifndef LRUCACHE_HPP
#define	LRUCACHE_HPP

#include <utility>
#include <list>
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename K, typename V>
class lru_cache {
    list<pair<K,V>> cache;
    int size;
    int capacity;

    void print() {
        auto it = cache.begin();
        if (size == 0) {
            cout << "Cache is empty\n";
            return;
        }
        cout << endl << "Cache (size = " << size << "): \n";
        for (it; it != cache.end(); ++it) {
            cout << it->first << " : " << it->second << "    ";
        }
        cout << endl;
    }

public:

    lru_cache(int m) : size(0), capacity(m) {}

    void put(const K &key,const V &value) {
        auto it = cache.begin();
        for (it; it != cache.end(); ++it) {
            if (it->first == key) {
                cache.splice(cache.begin(), cache, it);
                cache.begin()->second = value;
                print();
                return;
            }
        }
        if (size == capacity) {
            cache.pop_back();
        } else {
            ++size;
        }
        cache.push_front(make_pair(key, value));
        print();
    }

    const V& get(const K& key) {
        auto it = cache.begin();
        for (it; it != cache.end(); ++it) {
            if (it->first == key) {
                cache.splice(cache.begin(), cache, it);
                print();
                return it->second;
            }
        }
        throw range_error("\nThere is no such key in cache");
    }
};

#endif