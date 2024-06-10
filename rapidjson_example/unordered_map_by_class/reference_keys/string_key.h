#ifndef STRING_KEY_H
#define STRING_KEY_H

#include "reference_key.h"
#include <iostream>
#include <memory>

class StringKey : public ReferenceKeys {
public:
    StringKey(std::shared_ptr<std::string> s_ptr);
    
private: 
    std::shared_ptr<std::string> ref_key_to_origin;
};
#endif