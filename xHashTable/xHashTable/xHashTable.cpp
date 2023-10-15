//
//  xHashTable.cpp
//  xHashTable
//
//  Created by Akshive Pandey on 14/10/23.
//

#include "xHashTable.hpp"

#pragma region Constructor

template <typename K, typename V>
xHashTable<K, V>::xHashTable()
{
    this->size = 0;
    this->capacity = 16;
    this->buckets = new Bucket<K, V>[this->capacity];
};

template <typename K, typename V>
xHashTable<K, V>::~xHashTable()
{
    delete [] this->buckets;
};

#pragma endregion Constructor

#pragma region PublicMethods

template <typename K, typename V>
void xHashTable<K, V>::Put(K key, V value)
{
    if (this->size >= this->capacity)
    {
        this->Resize(2*this->capacity);
    }
    
    size_t index = this->GetHash(key);
    
    if (this->buckets[index].IsOccupied)
    {
        size_t home = index;
        index = (index+1) % this->capacity;
        
        while (index != home && this->buckets[index].IsOccupied)
        {
            index = (index+1) % this->capacity;
        }
    }
    
    this->buckets[index] = Bucket<K, V>(key, value);
    this->size += 1;
};

template <typename K, typename V>
bool xHashTable<K, V>::Get(K key, V &value)
{
    size_t index = this->GetHash(key);
    
    // Change this ...
    while (index < this->capacity && this->buckets[index].IsOccupied)
    {
        // update this ...
        if (this->buckets[index].Key == key)
        {
            value = this->buckets[index].Value;
            return true;
        }
        
        index++;
    }
    
    return false;
};

#pragma endregion PrivateMethods

template <typename K, typename V>
size_t xHashTable<K, V>::GetHash(K key)
{
    return this->hash_obj(key) % this->capacity;
};

template <typename K, typename V>
void xHashTable<K, V>::Resize(size_t newCapacity)
{
    Bucket<K, V>* newBuckets = new Bucket<K, V>[newCapacity];
    size_t oldCapacity = this->capacity;
    this->capacity = newCapacity;
    
    for (size_t i = 0; i < oldCapacity; i++)
    {
        if (this->buckets[i].IsOccupied)
        {
            size_t index = this->GetHash(buckets[i].Key);
            
            if (newBuckets[index].IsOccupied)
            {
                size_t home = index;
                index = (index+1) % this->capacity;
                
                while (index != home && this->buckets[index].IsOccupied)
                {
                    index = (index+1) % this->capacity;
                }
            }

            newBuckets[index] = this->buckets[i];
        }
    }
    
    // Fix this ...
    delete [] this->buckets;
    this->buckets = newBuckets;
};

#pragma endregion PrivateMethods
