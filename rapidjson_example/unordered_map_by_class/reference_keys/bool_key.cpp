#include "bool_key.h"

/// @brief to store a smart pointer to point the original value.
/// @param s_ptr a shared pointer bool
BoolKey::BoolKey(std::shared_ptr<bool> s_ptr) : ref_key_to_origin(s_ptr) {
    std::cout << "BoolKey refer to -> " << this->ref_key_to_origin << std::endl;
}
