//
//  xBlock.hpp
//  xLSM
//
//  Created by Akshive Pandey on 15/10/23.
//

#ifndef xBlock_hpp
#define xBlock_hpp

#include<iostream>
#include "stdint.h"
#include<vector>

/// A block is the smallest unit of read and caching in LSM tree.
/// It is a collection of sorted key-value pairs.
///
/// ----------------------------------------------------------------------------------------------------
/// |               Data Section                   |                  Offset Section                  |         Extra             |
/// ----------------------------------------------------------------------------------------------------
/// | Entry #1 | Entry #2 | ... | Entry #N | Offset #1 | Offset #2 | ... | Offset #N | num_of_elements |
/// ----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------
//|                           Entry #1                            | ... |
//-----------------------------------------------------------------------
//| key_len (2B) | key (keylen) | value_len (2B) | value (varlen) | ... |
//-----------------------------------------------------------------------

class xBlock
{
private:
    std::vector<uint8_t> data;
    std::vector<uint16_t> offsets;
    uint16_t blockCapacity;
    
public:
    xBlock(uint16_t capacity);
    void Push(uint8_t* key, uint8_t* value);
    uint16_t size();
};


class xBlockIterator
{
private:
    xBlock* block;
    uint16_t index;
public:
    xBlockIterator(xBlock &block);
    xBlockIterator(xBlock &block, uint8_t key);
    void next();
    uint8_t* Key();
    uint8_t* Value();
};

#endif /* xBlock_hpp */
