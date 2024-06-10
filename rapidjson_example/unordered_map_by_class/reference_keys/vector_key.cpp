#include "vector_key.h"

/// @brief to store a smart pointer to point the original value.
/// @param s_ptr a shared pointer vector<int>
VectorKey::VectorKey(std::shared_ptr<std::vector<int>> s_ptr) : ref_key_to_origin(s_ptr) {
    std::cout << "VectorKey refer to -> " << this->ref_key_to_origin << std::endl;
}
