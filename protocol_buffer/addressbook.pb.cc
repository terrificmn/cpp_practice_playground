// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: addressbook.proto

#include "addressbook.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace tutorial {
constexpr Person_PhoneNumber::Person_PhoneNumber(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : number_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , type_(0)
{}
struct Person_PhoneNumberDefaultTypeInternal {
  constexpr Person_PhoneNumberDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~Person_PhoneNumberDefaultTypeInternal() {}
  union {
    Person_PhoneNumber _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT Person_PhoneNumberDefaultTypeInternal _Person_PhoneNumber_default_instance_;
constexpr Person::Person(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : phones_()
  , name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , email_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , id_(0){}
struct PersonDefaultTypeInternal {
  constexpr PersonDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~PersonDefaultTypeInternal() {}
  union {
    Person _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PersonDefaultTypeInternal _Person_default_instance_;
constexpr AddressBook::AddressBook(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : people_(){}
struct AddressBookDefaultTypeInternal {
  constexpr AddressBookDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~AddressBookDefaultTypeInternal() {}
  union {
    AddressBook _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT AddressBookDefaultTypeInternal _AddressBook_default_instance_;
}  // namespace tutorial
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_addressbook_2eproto[3];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_addressbook_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_addressbook_2eproto = nullptr;

const uint32_t TableStruct_addressbook_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::tutorial::Person_PhoneNumber, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person_PhoneNumber, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::tutorial::Person_PhoneNumber, number_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person_PhoneNumber, type_),
  0,
  1,
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, name_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, id_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, email_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, phones_),
  ~0u,
  0,
  ~0u,
  ~0u,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tutorial::AddressBook, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::tutorial::AddressBook, people_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, -1, sizeof(::tutorial::Person_PhoneNumber)},
  { 10, 20, -1, sizeof(::tutorial::Person)},
  { 24, -1, -1, sizeof(::tutorial::AddressBook)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tutorial::_Person_PhoneNumber_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tutorial::_Person_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tutorial::_AddressBook_default_instance_),
};

const char descriptor_table_protodef_addressbook_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021addressbook.proto\022\010tutorial\"\274\002\n\006Person"
  "\022\014\n\004name\030\001 \001(\t\022\017\n\002id\030\002 \001(\005H\000\210\001\001\022\r\n\005email"
  "\030\003 \001(\t\022,\n\006phones\030\004 \003(\0132\034.tutorial.Person"
  ".PhoneNumber\032e\n\013PhoneNumber\022\023\n\006number\030\001 "
  "\001(\tH\000\210\001\001\022-\n\004type\030\002 \001(\0162\032.tutorial.Person"
  ".PhoneTypeH\001\210\001\001B\t\n\007_numberB\007\n\005_type\"h\n\tP"
  "honeType\022\032\n\026PHONE_TYPE_UNSPECIFIED\020\000\022\025\n\021"
  "PHONE_TYPE_MOBILE\020\001\022\023\n\017PHONE_TYPE_HOME\020\002"
  "\022\023\n\017PHONE_TYPE_WORK\020\003B\005\n\003_id\"/\n\013AddressB"
  "ook\022 \n\006people\030\001 \003(\0132\020.tutorial.Personb\006p"
  "roto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_addressbook_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_addressbook_2eproto = {
  false, false, 405, descriptor_table_protodef_addressbook_2eproto, "addressbook.proto", 
  &descriptor_table_addressbook_2eproto_once, nullptr, 0, 3,
  schemas, file_default_instances, TableStruct_addressbook_2eproto::offsets,
  file_level_metadata_addressbook_2eproto, file_level_enum_descriptors_addressbook_2eproto, file_level_service_descriptors_addressbook_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_addressbook_2eproto_getter() {
  return &descriptor_table_addressbook_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_addressbook_2eproto(&descriptor_table_addressbook_2eproto);
namespace tutorial {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Person_PhoneType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_addressbook_2eproto);
  return file_level_enum_descriptors_addressbook_2eproto[0];
}
bool Person_PhoneType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr Person_PhoneType Person::PHONE_TYPE_UNSPECIFIED;
constexpr Person_PhoneType Person::PHONE_TYPE_MOBILE;
constexpr Person_PhoneType Person::PHONE_TYPE_HOME;
constexpr Person_PhoneType Person::PHONE_TYPE_WORK;
constexpr Person_PhoneType Person::PhoneType_MIN;
constexpr Person_PhoneType Person::PhoneType_MAX;
constexpr int Person::PhoneType_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class Person_PhoneNumber::_Internal {
 public:
  using HasBits = decltype(std::declval<Person_PhoneNumber>()._has_bits_);
  static void set_has_number(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_type(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

Person_PhoneNumber::Person_PhoneNumber(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:tutorial.Person.PhoneNumber)
}
Person_PhoneNumber::Person_PhoneNumber(const Person_PhoneNumber& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  number_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    number_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_number()) {
    number_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_number(), 
      GetArenaForAllocation());
  }
  type_ = from.type_;
  // @@protoc_insertion_point(copy_constructor:tutorial.Person.PhoneNumber)
}

inline void Person_PhoneNumber::SharedCtor() {
number_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  number_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
type_ = 0;
}

Person_PhoneNumber::~Person_PhoneNumber() {
  // @@protoc_insertion_point(destructor:tutorial.Person.PhoneNumber)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Person_PhoneNumber::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  number_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Person_PhoneNumber::ArenaDtor(void* object) {
  Person_PhoneNumber* _this = reinterpret_cast< Person_PhoneNumber* >(object);
  (void)_this;
}
void Person_PhoneNumber::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Person_PhoneNumber::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Person_PhoneNumber::Clear() {
// @@protoc_insertion_point(message_clear_start:tutorial.Person.PhoneNumber)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    number_.ClearNonDefaultToEmpty();
  }
  type_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Person_PhoneNumber::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // optional string number = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_number();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "tutorial.Person.PhoneNumber.number"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional .tutorial.Person.PhoneType type = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_type(static_cast<::tutorial::Person_PhoneType>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Person_PhoneNumber::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.Person.PhoneNumber)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // optional string number = 1;
  if (_internal_has_number()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_number().data(), static_cast<int>(this->_internal_number().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tutorial.Person.PhoneNumber.number");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_number(), target);
  }

  // optional .tutorial.Person.PhoneType type = 2;
  if (_internal_has_type()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      2, this->_internal_type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tutorial.Person.PhoneNumber)
  return target;
}

size_t Person_PhoneNumber::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tutorial.Person.PhoneNumber)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // optional string number = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_number());
    }

    // optional .tutorial.Person.PhoneType type = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_type());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Person_PhoneNumber::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Person_PhoneNumber::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Person_PhoneNumber::GetClassData() const { return &_class_data_; }

void Person_PhoneNumber::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Person_PhoneNumber *>(to)->MergeFrom(
      static_cast<const Person_PhoneNumber &>(from));
}


void Person_PhoneNumber::MergeFrom(const Person_PhoneNumber& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tutorial.Person.PhoneNumber)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_number(from._internal_number());
    }
    if (cached_has_bits & 0x00000002u) {
      type_ = from.type_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Person_PhoneNumber::CopyFrom(const Person_PhoneNumber& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tutorial.Person.PhoneNumber)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person_PhoneNumber::IsInitialized() const {
  return true;
}

void Person_PhoneNumber::InternalSwap(Person_PhoneNumber* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &number_, lhs_arena,
      &other->number_, rhs_arena
  );
  swap(type_, other->type_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Person_PhoneNumber::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_addressbook_2eproto_getter, &descriptor_table_addressbook_2eproto_once,
      file_level_metadata_addressbook_2eproto[0]);
}

// ===================================================================

class Person::_Internal {
 public:
  using HasBits = decltype(std::declval<Person>()._has_bits_);
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

Person::Person(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  phones_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:tutorial.Person)
}
Person::Person(const Person& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_),
      phones_(from.phones_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArenaForAllocation());
  }
  email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    email_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_email().empty()) {
    email_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_email(), 
      GetArenaForAllocation());
  }
  id_ = from.id_;
  // @@protoc_insertion_point(copy_constructor:tutorial.Person)
}

inline void Person::SharedCtor() {
name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  email_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
id_ = 0;
}

Person::~Person() {
  // @@protoc_insertion_point(destructor:tutorial.Person)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Person::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  email_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Person::ArenaDtor(void* object) {
  Person* _this = reinterpret_cast< Person* >(object);
  (void)_this;
}
void Person::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Person::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Person::Clear() {
// @@protoc_insertion_point(message_clear_start:tutorial.Person)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  phones_.Clear();
  name_.ClearToEmpty();
  email_.ClearToEmpty();
  id_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Person::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "tutorial.Person.name"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional int32 id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _Internal::set_has_id(&has_bits);
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string email = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_email();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "tutorial.Person.email"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .tutorial.Person.PhoneNumber phones = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_phones(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Person::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.Person)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tutorial.Person.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // optional int32 id = 2;
  if (_internal_has_id()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_id(), target);
  }

  // string email = 3;
  if (!this->_internal_email().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_email().data(), static_cast<int>(this->_internal_email().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tutorial.Person.email");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_email(), target);
  }

  // repeated .tutorial.Person.PhoneNumber phones = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_phones_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, this->_internal_phones(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tutorial.Person)
  return target;
}

size_t Person::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tutorial.Person)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .tutorial.Person.PhoneNumber phones = 4;
  total_size += 1UL * this->_internal_phones_size();
  for (const auto& msg : this->phones_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string email = 3;
  if (!this->_internal_email().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_email());
  }

  // optional int32 id = 2;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Person::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Person::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Person::GetClassData() const { return &_class_data_; }

void Person::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Person *>(to)->MergeFrom(
      static_cast<const Person &>(from));
}


void Person::MergeFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tutorial.Person)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  phones_.MergeFrom(from.phones_);
  if (!from._internal_name().empty()) {
    _internal_set_name(from._internal_name());
  }
  if (!from._internal_email().empty()) {
    _internal_set_email(from._internal_email());
  }
  if (from._internal_has_id()) {
    _internal_set_id(from._internal_id());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Person::CopyFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tutorial.Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person::IsInitialized() const {
  return true;
}

void Person::InternalSwap(Person* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  phones_.InternalSwap(&other->phones_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &name_, lhs_arena,
      &other->name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &email_, lhs_arena,
      &other->email_, rhs_arena
  );
  swap(id_, other->id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Person::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_addressbook_2eproto_getter, &descriptor_table_addressbook_2eproto_once,
      file_level_metadata_addressbook_2eproto[1]);
}

// ===================================================================

class AddressBook::_Internal {
 public:
};

AddressBook::AddressBook(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  people_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:tutorial.AddressBook)
}
AddressBook::AddressBook(const AddressBook& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      people_(from.people_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:tutorial.AddressBook)
}

inline void AddressBook::SharedCtor() {
}

AddressBook::~AddressBook() {
  // @@protoc_insertion_point(destructor:tutorial.AddressBook)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void AddressBook::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void AddressBook::ArenaDtor(void* object) {
  AddressBook* _this = reinterpret_cast< AddressBook* >(object);
  (void)_this;
}
void AddressBook::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void AddressBook::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void AddressBook::Clear() {
// @@protoc_insertion_point(message_clear_start:tutorial.AddressBook)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  people_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* AddressBook::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .tutorial.Person people = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_people(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* AddressBook::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.AddressBook)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .tutorial.Person people = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_people_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_people(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tutorial.AddressBook)
  return target;
}

size_t AddressBook::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tutorial.AddressBook)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .tutorial.Person people = 1;
  total_size += 1UL * this->_internal_people_size();
  for (const auto& msg : this->people_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData AddressBook::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    AddressBook::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*AddressBook::GetClassData() const { return &_class_data_; }

void AddressBook::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<AddressBook *>(to)->MergeFrom(
      static_cast<const AddressBook &>(from));
}


void AddressBook::MergeFrom(const AddressBook& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tutorial.AddressBook)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  people_.MergeFrom(from.people_);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void AddressBook::CopyFrom(const AddressBook& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tutorial.AddressBook)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddressBook::IsInitialized() const {
  return true;
}

void AddressBook::InternalSwap(AddressBook* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  people_.InternalSwap(&other->people_);
}

::PROTOBUF_NAMESPACE_ID::Metadata AddressBook::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_addressbook_2eproto_getter, &descriptor_table_addressbook_2eproto_once,
      file_level_metadata_addressbook_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace tutorial
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::tutorial::Person_PhoneNumber* Arena::CreateMaybeMessage< ::tutorial::Person_PhoneNumber >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tutorial::Person_PhoneNumber >(arena);
}
template<> PROTOBUF_NOINLINE ::tutorial::Person* Arena::CreateMaybeMessage< ::tutorial::Person >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tutorial::Person >(arena);
}
template<> PROTOBUF_NOINLINE ::tutorial::AddressBook* Arena::CreateMaybeMessage< ::tutorial::AddressBook >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tutorial::AddressBook >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>