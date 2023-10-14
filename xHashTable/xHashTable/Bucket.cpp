//
//  Bucket.cpp
//  xHashTable
//
//  Created by Akshive Pandey on 15/10/23.
//

#include "Bucket.hpp"

#pragma region Constructor

template<typename K, typename V>
Bucket<K, V>::Bucket()
{
}

template<typename K, typename V>
Bucket<K, V>::Bucket(K key, V value)
{
    this->Key = key;
    this->Value = value;
    this->IsOccupied = true;
}

#pragma endregion Constructor
