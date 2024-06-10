#include "int_key.h"

/// @brief to store a smart pointer to point the original value.
/// @param s_ptr a shared pointer int
IntKey::IntKey(std::shared_ptr<int> s_ptr) : ref_key_to_origin(s_ptr) {
    std::cout << "IntKey refer to -> " << this->ref_key_to_origin << std::endl;
}
