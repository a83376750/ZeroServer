// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_arena.proto

#include <google/protobuf/unittest_arena.pb.h>

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_google_2fprotobuf_2funittest_5farena_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_google_2fprotobuf_2funittest_5farena_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_NestedMessage;
}  // namespace protobuf_google_2fprotobuf_2funittest_5farena_2eproto
namespace protobuf_google_2fprotobuf_2funittest_5fno_5farena_5fimport_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_google_2fprotobuf_2funittest_5fno_5farena_5fimport_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_ImportNoArenaNestedMessage;
}  // namespace protobuf_google_2fprotobuf_2funittest_5fno_5farena_5fimport_2eproto
namespace proto2_arena_unittest {
class NestedMessageDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<NestedMessage>
      _instance;
} _NestedMessage_default_instance_;
class ArenaMessageDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ArenaMessage>
      _instance;
} _ArenaMessage_default_instance_;
}  // namespace proto2_arena_unittest
namespace protobuf_google_2fprotobuf_2funittest_5farena_2eproto {
static void InitDefaultsNestedMessage() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::proto2_arena_unittest::_NestedMessage_default_instance_;
    new (ptr) ::proto2_arena_unittest::NestedMessage();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::proto2_arena_unittest::NestedMessage::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_NestedMessage =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsNestedMessage}, {}};

static void InitDefaultsArenaMessage() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::proto2_arena_unittest::_ArenaMessage_default_instance_;
    new (ptr) ::proto2_arena_unittest::ArenaMessage();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::proto2_arena_unittest::ArenaMessage::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<2> scc_info_ArenaMessage =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 2, InitDefaultsArenaMessage}, {
      &protobuf_google_2fprotobuf_2funittest_5farena_2eproto::scc_info_NestedMessage.base,
      &protobuf_google_2fprotobuf_2funittest_5fno_5farena_5fimport_2eproto::scc_info_ImportNoArenaNestedMessage.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_NestedMessage.base);
  ::google::protobuf::internal::InitSCC(&scc_info_ArenaMessage.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto2_arena_unittest::NestedMessage, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto2_arena_unittest::NestedMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto2_arena_unittest::NestedMessage, d_),
  0,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto2_arena_unittest::ArenaMessage, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto2_arena_unittest::ArenaMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto2_arena_unittest::ArenaMessage, repeated_nested_message_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::proto2_arena_unittest::ArenaMessage, repeated_import_no_arena_message_),
  ~0u,
  ~0u,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::proto2_arena_unittest::NestedMessage)},
  { 7, 14, sizeof(::proto2_arena_unittest::ArenaMessage)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::proto2_arena_unittest::_NestedMessage_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::proto2_arena_unittest::_ArenaMessage_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "google/protobuf/unittest_arena.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n$google/protobuf/unittest_arena.proto\022\025"
      "proto2_arena_unittest\032.google/protobuf/u"
      "nittest_no_arena_import.proto\"\032\n\rNestedM"
      "essage\022\t\n\001d\030\001 \001(\005\"\262\001\n\014ArenaMessage\022E\n\027re"
      "peated_nested_message\030\001 \003(\0132$.proto2_are"
      "na_unittest.NestedMessage\022[\n repeated_im"
      "port_no_arena_message\030\002 \003(\01321.proto2_are"
      "na_unittest.ImportNoArenaNestedMessageB\003"
      "\370\001\001"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 323);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "google/protobuf/unittest_arena.proto", &protobuf_RegisterTypes);
  ::protobuf_google_2fprotobuf_2funittest_5fno_5farena_5fimport_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_google_2fprotobuf_2funittest_5farena_2eproto
namespace proto2_arena_unittest {

// ===================================================================

void NestedMessage::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int NestedMessage::kDFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

NestedMessage::NestedMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_google_2fprotobuf_2funittest_5farena_2eproto::scc_info_NestedMessage.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto2_arena_unittest.NestedMessage)
}
NestedMessage::NestedMessage(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena) {
  ::google::protobuf::internal::InitSCC(&protobuf_google_2fprotobuf_2funittest_5farena_2eproto::scc_info_NestedMessage.base);
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:proto2_arena_unittest.NestedMessage)
}
NestedMessage::NestedMessage(const NestedMessage& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  d_ = from.d_;
  // @@protoc_insertion_point(copy_constructor:proto2_arena_unittest.NestedMessage)
}

void NestedMessage::SharedCtor() {
  d_ = 0;
}

NestedMessage::~NestedMessage() {
  // @@protoc_insertion_point(destructor:proto2_arena_unittest.NestedMessage)
  SharedDtor();
}

void NestedMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == NULL);
}

void NestedMessage::ArenaDtor(void* object) {
  NestedMessage* _this = reinterpret_cast< NestedMessage* >(object);
  (void)_this;
}
void NestedMessage::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void NestedMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* NestedMessage::descriptor() {
  ::protobuf_google_2fprotobuf_2funittest_5farena_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_google_2fprotobuf_2funittest_5farena_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const NestedMessage& NestedMessage::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_google_2fprotobuf_2funittest_5farena_2eproto::scc_info_NestedMessage.base);
  return *internal_default_instance();
}


void NestedMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:proto2_arena_unittest.NestedMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  d_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool NestedMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto2_arena_unittest.NestedMessage)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 d = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_d();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &d_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto2_arena_unittest.NestedMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto2_arena_unittest.NestedMessage)
  return false;
#undef DO_
}

void NestedMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto2_arena_unittest.NestedMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 d = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->d(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto2_arena_unittest.NestedMessage)
}

::google::protobuf::uint8* NestedMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:proto2_arena_unittest.NestedMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int32 d = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->d(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto2_arena_unittest.NestedMessage)
  return target;
}

size_t NestedMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto2_arena_unittest.NestedMessage)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // optional int32 d = 1;
  if (has_d()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->d());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void NestedMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:proto2_arena_unittest.NestedMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const NestedMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const NestedMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:proto2_arena_unittest.NestedMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:proto2_arena_unittest.NestedMessage)
    MergeFrom(*source);
  }
}

void NestedMessage::MergeFrom(const NestedMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto2_arena_unittest.NestedMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_d()) {
    set_d(from.d());
  }
}

void NestedMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:proto2_arena_unittest.NestedMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NestedMessage::CopyFrom(const NestedMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto2_arena_unittest.NestedMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NestedMessage::IsInitialized() const {
  return true;
}

void NestedMessage::Swap(NestedMessage* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    NestedMessage* temp = New(GetArenaNoVirtual());
    temp->MergeFrom(*other);
    other->CopyFrom(*this);
    InternalSwap(temp);
    if (GetArenaNoVirtual() == NULL) {
      delete temp;
    }
  }
}
void NestedMessage::UnsafeArenaSwap(NestedMessage* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void NestedMessage::InternalSwap(NestedMessage* other) {
  using std::swap;
  swap(d_, other->d_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata NestedMessage::GetMetadata() const {
  protobuf_google_2fprotobuf_2funittest_5farena_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_google_2fprotobuf_2funittest_5farena_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void ArenaMessage::InitAsDefaultInstance() {
}
void ArenaMessage::clear_repeated_import_no_arena_message() {
  repeated_import_no_arena_message_.Clear();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ArenaMessage::kRepeatedNestedMessageFieldNumber;
const int ArenaMessage::kRepeatedImportNoArenaMessageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ArenaMessage::ArenaMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_google_2fprotobuf_2funittest_5farena_2eproto::scc_info_ArenaMessage.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto2_arena_unittest.ArenaMessage)
}
ArenaMessage::ArenaMessage(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena),
  repeated_nested_message_(arena),
  repeated_import_no_arena_message_(arena) {
  ::google::protobuf::internal::InitSCC(&protobuf_google_2fprotobuf_2funittest_5farena_2eproto::scc_info_ArenaMessage.base);
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:proto2_arena_unittest.ArenaMessage)
}
ArenaMessage::ArenaMessage(const ArenaMessage& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      repeated_nested_message_(from.repeated_nested_message_),
      repeated_import_no_arena_message_(from.repeated_import_no_arena_message_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:proto2_arena_unittest.ArenaMessage)
}

void ArenaMessage::SharedCtor() {
}

ArenaMessage::~ArenaMessage() {
  // @@protoc_insertion_point(destructor:proto2_arena_unittest.ArenaMessage)
  SharedDtor();
}

void ArenaMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == NULL);
}

void ArenaMessage::ArenaDtor(void* object) {
  ArenaMessage* _this = reinterpret_cast< ArenaMessage* >(object);
  (void)_this;
}
void ArenaMessage::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void ArenaMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ArenaMessage::descriptor() {
  ::protobuf_google_2fprotobuf_2funittest_5farena_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_google_2fprotobuf_2funittest_5farena_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ArenaMessage& ArenaMessage::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_google_2fprotobuf_2funittest_5farena_2eproto::scc_info_ArenaMessage.base);
  return *internal_default_instance();
}


void ArenaMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:proto2_arena_unittest.ArenaMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  repeated_nested_message_.Clear();
  repeated_import_no_arena_message_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ArenaMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto2_arena_unittest.ArenaMessage)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_repeated_nested_message()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_repeated_import_no_arena_message()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto2_arena_unittest.ArenaMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto2_arena_unittest.ArenaMessage)
  return false;
#undef DO_
}

void ArenaMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto2_arena_unittest.ArenaMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->repeated_nested_message_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1,
      this->repeated_nested_message(static_cast<int>(i)),
      output);
  }

  // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->repeated_import_no_arena_message_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2,
      this->repeated_import_no_arena_message(static_cast<int>(i)),
      output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto2_arena_unittest.ArenaMessage)
}

::google::protobuf::uint8* ArenaMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:proto2_arena_unittest.ArenaMessage)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->repeated_nested_message_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->repeated_nested_message(static_cast<int>(i)), deterministic, target);
  }

  // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->repeated_import_no_arena_message_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, this->repeated_import_no_arena_message(static_cast<int>(i)), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto2_arena_unittest.ArenaMessage)
  return target;
}

size_t ArenaMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto2_arena_unittest.ArenaMessage)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->repeated_nested_message_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->repeated_nested_message(static_cast<int>(i)));
    }
  }

  // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->repeated_import_no_arena_message_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->repeated_import_no_arena_message(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ArenaMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:proto2_arena_unittest.ArenaMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const ArenaMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ArenaMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:proto2_arena_unittest.ArenaMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:proto2_arena_unittest.ArenaMessage)
    MergeFrom(*source);
  }
}

void ArenaMessage::MergeFrom(const ArenaMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto2_arena_unittest.ArenaMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  repeated_nested_message_.MergeFrom(from.repeated_nested_message_);
  repeated_import_no_arena_message_.MergeFrom(from.repeated_import_no_arena_message_);
}

void ArenaMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:proto2_arena_unittest.ArenaMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArenaMessage::CopyFrom(const ArenaMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto2_arena_unittest.ArenaMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArenaMessage::IsInitialized() const {
  return true;
}

void ArenaMessage::Swap(ArenaMessage* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    ArenaMessage* temp = New(GetArenaNoVirtual());
    temp->MergeFrom(*other);
    other->CopyFrom(*this);
    InternalSwap(temp);
    if (GetArenaNoVirtual() == NULL) {
      delete temp;
    }
  }
}
void ArenaMessage::UnsafeArenaSwap(ArenaMessage* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void ArenaMessage::InternalSwap(ArenaMessage* other) {
  using std::swap;
  CastToBase(&repeated_nested_message_)->InternalSwap(CastToBase(&other->repeated_nested_message_));
  CastToBase(&repeated_import_no_arena_message_)->InternalSwap(CastToBase(&other->repeated_import_no_arena_message_));
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ArenaMessage::GetMetadata() const {
  protobuf_google_2fprotobuf_2funittest_5farena_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_google_2fprotobuf_2funittest_5farena_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto2_arena_unittest
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::proto2_arena_unittest::NestedMessage* Arena::CreateMaybeMessage< ::proto2_arena_unittest::NestedMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto2_arena_unittest::NestedMessage >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::proto2_arena_unittest::ArenaMessage* Arena::CreateMaybeMessage< ::proto2_arena_unittest::ArenaMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::proto2_arena_unittest::ArenaMessage >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
