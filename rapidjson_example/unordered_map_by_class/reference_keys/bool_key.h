#ifndef BOOL_KEY_H
#define BOOL_KEY_H

#include "reference_key.h"
#include <iostream>
#include <memory>

class BoolKey : public ReferenceKeys {
public:
    BoolKey(std::shared_ptr<bool> s_ptr);
    
private: 
    std::shared_ptr<bool> ref_key_to_origin;
};
#endif