#include "string_key.h"

/// @brief to store a smart pointer to point the original value.
/// @param s_ptr a shared pointer string
StringKey::StringKey(std::shared_ptr<std::string> s_ptr) : ref_key_to_origin(s_ptr) {
    std::cout << "StringKey refer to -> " << this->ref_key_to_origin << std::endl;
}
