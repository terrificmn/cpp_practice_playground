#ifndef VECTOR_KEY_H
#define VECTOR_KEY_H

#include "reference_key.h"
#include <iostream>
#include <memory>
#include <vector>

class VectorKey : public ReferenceKeys {
public:
    VectorKey(std::shared_ptr<std::vector<int>> s_ptr);
    
private: 
    std::shared_ptr<std::vector<int>> ref_key_to_origin;
};
#endif