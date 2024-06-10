#ifndef DOUBLE_KEY_H
#define DOUBLE_KEY_H

#include "reference_key.h"
#include <iostream>
#include <memory>

class DoubleKey : public ReferenceKeys {
public:
    DoubleKey(std::shared_ptr<double> s_ptr);
    
private: 
    std::shared_ptr<double> ref_key_to_origin;
};
#endif