//
//  xLSM.hpp
//  xLSM
//
//  Created by Akshive Pandey on 15/10/23.
//

#ifndef xLSM_
#define xLSM_

/* The classes below are exported */
#pragma GCC visibility push(default)

template <typename K, typename V>
class xLSM
{
    public:
    xLSM();
    void Put(K key, V value);
    bool Get(K key, V &value);
    void Delete(K key);
};

#pragma GCC visibility pop
#endif
