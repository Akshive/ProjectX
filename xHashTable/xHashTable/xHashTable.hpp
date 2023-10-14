//
//  xHashTable.hpp
//  xHashTable
//
//  Created by Akshive Pandey on 14/10/23.
//
#include<iostream>
#include "Bucket.hpp"

#ifndef xHashTable_
#define xHashTable_

/* The classes below are exported */
#pragma GCC visibility push(default)

template <typename K, typename V>
class xHashTable
{
    private:
        Bucket<K, V>* buckets;
        size_t size;
        size_t capacity;
        std::hash<K> hash_obj;
        size_t GetHash(K key);
        void Resize(size_t newCapacity);
        
    public:
        xHashTable();
        ~xHashTable();
        void Put(K key, V value);
        bool Get(K key, V &value);
};

#pragma GCC visibility pop
#endif
