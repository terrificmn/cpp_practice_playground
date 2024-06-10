#ifndef INT_KEY_H
#define INT_KEY_H

#include "reference_key.h"
#include <iostream>
#include <memory>

class IntKey : public ReferenceKeys {
public:
    IntKey(std::shared_ptr<int> s_ptr);
    
private: 
    std::shared_ptr<int> ref_key_to_origin;
};
#endif