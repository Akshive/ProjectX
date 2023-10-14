//
//  Bucket.hpp
//  xHashTable
//
//  Created by Akshive Pandey on 15/10/23.
//

#ifndef Bucket_hpp
#define Bucket_hpp

template <typename K, typename V>
class Bucket
{
    public:
        K Key;
        V Value;
        bool IsOccupied;
        Bucket();
        Bucket(K key, V value);
};

#endif /* Bucket_hpp */
