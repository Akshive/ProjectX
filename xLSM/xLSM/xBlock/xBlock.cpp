//
//  xBlock.cpp
//  xLSM
//
//  Created by Akshive Pandey on 15/10/23.
//

#include "xBlock.hpp"

xBlock::xBlock(uint16_t capacity)
{
    this->data = std::vector<uint8_t>();
    this->offsets = std::vector<uint16_t>();
    this->blockCapacity = capacity;
}
