#include "double_key.h"

/// @brief to store a smart pointer to point the original value.
/// @param s_ptr a shared pointer double
DoubleKey::DoubleKey(std::shared_ptr<double> s_ptr) : ref_key_to_origin(s_ptr) {
    std::cout << "DoubleKey refer to -> " << this->ref_key_to_origin << std::endl;
}
