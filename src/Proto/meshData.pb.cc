// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: meshData.proto

#include "meshData.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr meshData_proto::meshData_proto(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : pname_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , vbo_vert_(nullptr)
  , vbo_norm_(nullptr)
  , vbo_uv_(nullptr)
  , vbo_index_(nullptr)
  , vbo_color_(nullptr)
  , vbo_weights_(nullptr)
  , vbo_joints_(nullptr)
  , vbo_invbind_(nullptr)
  , enabled_(false)
  , mode_(0)

  , tricount_(0u)
  , vertcount_(0u)
  , materialindex_(0u)
  , jointindex_(0)
  , parentjointindex_(0){}
struct meshData_protoDefaultTypeInternal {
  constexpr meshData_protoDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~meshData_protoDefaultTypeInternal() {}
  union {
    meshData_proto _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT meshData_protoDefaultTypeInternal _meshData_proto_default_instance_;
bool meshData_proto_RENDER_MODE_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> meshData_proto_RENDER_MODE_strings[7] = {};

static const char meshData_proto_RENDER_MODE_names[] =
  "MODE_LINE"
  "MODE_LINE_LOOP"
  "MODE_LINE_STRIP"
  "MODE_POINTS"
  "MODE_TRIANGLES"
  "MODE_TRIANGLE_FAN"
  "MODE_TRIANGLE_STRIP";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry meshData_proto_RENDER_MODE_entries[] = {
  { {meshData_proto_RENDER_MODE_names + 0, 9}, 1 },
  { {meshData_proto_RENDER_MODE_names + 9, 14}, 2 },
  { {meshData_proto_RENDER_MODE_names + 23, 15}, 3 },
  { {meshData_proto_RENDER_MODE_names + 38, 11}, 0 },
  { {meshData_proto_RENDER_MODE_names + 49, 14}, 4 },
  { {meshData_proto_RENDER_MODE_names + 63, 17}, 6 },
  { {meshData_proto_RENDER_MODE_names + 80, 19}, 5 },
};

static const int meshData_proto_RENDER_MODE_entries_by_number[] = {
  3, // 0 -> MODE_POINTS
  0, // 1 -> MODE_LINE
  1, // 2 -> MODE_LINE_LOOP
  2, // 3 -> MODE_LINE_STRIP
  4, // 4 -> MODE_TRIANGLES
  6, // 5 -> MODE_TRIANGLE_STRIP
  5, // 6 -> MODE_TRIANGLE_FAN
};

const std::string& meshData_proto_RENDER_MODE_Name(
    meshData_proto_RENDER_MODE value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          meshData_proto_RENDER_MODE_entries,
          meshData_proto_RENDER_MODE_entries_by_number,
          7, meshData_proto_RENDER_MODE_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      meshData_proto_RENDER_MODE_entries,
      meshData_proto_RENDER_MODE_entries_by_number,
      7, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     meshData_proto_RENDER_MODE_strings[idx].get();
}
bool meshData_proto_RENDER_MODE_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, meshData_proto_RENDER_MODE* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      meshData_proto_RENDER_MODE_entries, 7, name, &int_value);
  if (success) {
    *value = static_cast<meshData_proto_RENDER_MODE>(int_value);
  }
  return success;
}
#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr meshData_proto_RENDER_MODE meshData_proto::MODE_POINTS;
constexpr meshData_proto_RENDER_MODE meshData_proto::MODE_LINE;
constexpr meshData_proto_RENDER_MODE meshData_proto::MODE_LINE_LOOP;
constexpr meshData_proto_RENDER_MODE meshData_proto::MODE_LINE_STRIP;
constexpr meshData_proto_RENDER_MODE meshData_proto::MODE_TRIANGLES;
constexpr meshData_proto_RENDER_MODE meshData_proto::MODE_TRIANGLE_STRIP;
constexpr meshData_proto_RENDER_MODE meshData_proto::MODE_TRIANGLE_FAN;
constexpr meshData_proto_RENDER_MODE meshData_proto::RENDER_MODE_MIN;
constexpr meshData_proto_RENDER_MODE meshData_proto::RENDER_MODE_MAX;
constexpr int meshData_proto::RENDER_MODE_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

class meshData_proto::_Internal {
 public:
  static const ::vboData_proto& vbo_vert(const meshData_proto* msg);
  static const ::vboData_proto& vbo_norm(const meshData_proto* msg);
  static const ::vboData_proto& vbo_uv(const meshData_proto* msg);
  static const ::vboData_proto& vbo_index(const meshData_proto* msg);
  static const ::vboData_proto& vbo_color(const meshData_proto* msg);
  static const ::vboData_proto& vbo_weights(const meshData_proto* msg);
  static const ::vboData_proto& vbo_joints(const meshData_proto* msg);
  static const ::vboData_proto& vbo_invbind(const meshData_proto* msg);
};

const ::vboData_proto&
meshData_proto::_Internal::vbo_vert(const meshData_proto* msg) {
  return *msg->vbo_vert_;
}
const ::vboData_proto&
meshData_proto::_Internal::vbo_norm(const meshData_proto* msg) {
  return *msg->vbo_norm_;
}
const ::vboData_proto&
meshData_proto::_Internal::vbo_uv(const meshData_proto* msg) {
  return *msg->vbo_uv_;
}
const ::vboData_proto&
meshData_proto::_Internal::vbo_index(const meshData_proto* msg) {
  return *msg->vbo_index_;
}
const ::vboData_proto&
meshData_proto::_Internal::vbo_color(const meshData_proto* msg) {
  return *msg->vbo_color_;
}
const ::vboData_proto&
meshData_proto::_Internal::vbo_weights(const meshData_proto* msg) {
  return *msg->vbo_weights_;
}
const ::vboData_proto&
meshData_proto::_Internal::vbo_joints(const meshData_proto* msg) {
  return *msg->vbo_joints_;
}
const ::vboData_proto&
meshData_proto::_Internal::vbo_invbind(const meshData_proto* msg) {
  return *msg->vbo_invbind_;
}
void meshData_proto::clear_vbo_vert() {
  if (GetArenaForAllocation() == nullptr && vbo_vert_ != nullptr) {
    delete vbo_vert_;
  }
  vbo_vert_ = nullptr;
}
void meshData_proto::clear_vbo_norm() {
  if (GetArenaForAllocation() == nullptr && vbo_norm_ != nullptr) {
    delete vbo_norm_;
  }
  vbo_norm_ = nullptr;
}
void meshData_proto::clear_vbo_uv() {
  if (GetArenaForAllocation() == nullptr && vbo_uv_ != nullptr) {
    delete vbo_uv_;
  }
  vbo_uv_ = nullptr;
}
void meshData_proto::clear_vbo_index() {
  if (GetArenaForAllocation() == nullptr && vbo_index_ != nullptr) {
    delete vbo_index_;
  }
  vbo_index_ = nullptr;
}
void meshData_proto::clear_vbo_color() {
  if (GetArenaForAllocation() == nullptr && vbo_color_ != nullptr) {
    delete vbo_color_;
  }
  vbo_color_ = nullptr;
}
void meshData_proto::clear_vbo_weights() {
  if (GetArenaForAllocation() == nullptr && vbo_weights_ != nullptr) {
    delete vbo_weights_;
  }
  vbo_weights_ = nullptr;
}
void meshData_proto::clear_vbo_joints() {
  if (GetArenaForAllocation() == nullptr && vbo_joints_ != nullptr) {
    delete vbo_joints_;
  }
  vbo_joints_ = nullptr;
}
void meshData_proto::clear_vbo_invbind() {
  if (GetArenaForAllocation() == nullptr && vbo_invbind_ != nullptr) {
    delete vbo_invbind_;
  }
  vbo_invbind_ = nullptr;
}
meshData_proto::meshData_proto(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:meshData_proto)
}
meshData_proto::meshData_proto(const meshData_proto& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite() {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  pname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_pname().empty()) {
    pname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_pname(), 
      GetArenaForAllocation());
  }
  if (from._internal_has_vbo_vert()) {
    vbo_vert_ = new ::vboData_proto(*from.vbo_vert_);
  } else {
    vbo_vert_ = nullptr;
  }
  if (from._internal_has_vbo_norm()) {
    vbo_norm_ = new ::vboData_proto(*from.vbo_norm_);
  } else {
    vbo_norm_ = nullptr;
  }
  if (from._internal_has_vbo_uv()) {
    vbo_uv_ = new ::vboData_proto(*from.vbo_uv_);
  } else {
    vbo_uv_ = nullptr;
  }
  if (from._internal_has_vbo_index()) {
    vbo_index_ = new ::vboData_proto(*from.vbo_index_);
  } else {
    vbo_index_ = nullptr;
  }
  if (from._internal_has_vbo_color()) {
    vbo_color_ = new ::vboData_proto(*from.vbo_color_);
  } else {
    vbo_color_ = nullptr;
  }
  if (from._internal_has_vbo_weights()) {
    vbo_weights_ = new ::vboData_proto(*from.vbo_weights_);
  } else {
    vbo_weights_ = nullptr;
  }
  if (from._internal_has_vbo_joints()) {
    vbo_joints_ = new ::vboData_proto(*from.vbo_joints_);
  } else {
    vbo_joints_ = nullptr;
  }
  if (from._internal_has_vbo_invbind()) {
    vbo_invbind_ = new ::vboData_proto(*from.vbo_invbind_);
  } else {
    vbo_invbind_ = nullptr;
  }
  ::memcpy(&enabled_, &from.enabled_,
    static_cast<size_t>(reinterpret_cast<char*>(&parentjointindex_) -
    reinterpret_cast<char*>(&enabled_)) + sizeof(parentjointindex_));
  // @@protoc_insertion_point(copy_constructor:meshData_proto)
}

inline void meshData_proto::SharedCtor() {
pname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&vbo_vert_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&parentjointindex_) -
    reinterpret_cast<char*>(&vbo_vert_)) + sizeof(parentjointindex_));
}

meshData_proto::~meshData_proto() {
  // @@protoc_insertion_point(destructor:meshData_proto)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

inline void meshData_proto::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  pname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete vbo_vert_;
  if (this != internal_default_instance()) delete vbo_norm_;
  if (this != internal_default_instance()) delete vbo_uv_;
  if (this != internal_default_instance()) delete vbo_index_;
  if (this != internal_default_instance()) delete vbo_color_;
  if (this != internal_default_instance()) delete vbo_weights_;
  if (this != internal_default_instance()) delete vbo_joints_;
  if (this != internal_default_instance()) delete vbo_invbind_;
}

void meshData_proto::ArenaDtor(void* object) {
  meshData_proto* _this = reinterpret_cast< meshData_proto* >(object);
  (void)_this;
}
void meshData_proto::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void meshData_proto::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void meshData_proto::Clear() {
// @@protoc_insertion_point(message_clear_start:meshData_proto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  pname_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && vbo_vert_ != nullptr) {
    delete vbo_vert_;
  }
  vbo_vert_ = nullptr;
  if (GetArenaForAllocation() == nullptr && vbo_norm_ != nullptr) {
    delete vbo_norm_;
  }
  vbo_norm_ = nullptr;
  if (GetArenaForAllocation() == nullptr && vbo_uv_ != nullptr) {
    delete vbo_uv_;
  }
  vbo_uv_ = nullptr;
  if (GetArenaForAllocation() == nullptr && vbo_index_ != nullptr) {
    delete vbo_index_;
  }
  vbo_index_ = nullptr;
  if (GetArenaForAllocation() == nullptr && vbo_color_ != nullptr) {
    delete vbo_color_;
  }
  vbo_color_ = nullptr;
  if (GetArenaForAllocation() == nullptr && vbo_weights_ != nullptr) {
    delete vbo_weights_;
  }
  vbo_weights_ = nullptr;
  if (GetArenaForAllocation() == nullptr && vbo_joints_ != nullptr) {
    delete vbo_joints_;
  }
  vbo_joints_ = nullptr;
  if (GetArenaForAllocation() == nullptr && vbo_invbind_ != nullptr) {
    delete vbo_invbind_;
  }
  vbo_invbind_ = nullptr;
  ::memset(&enabled_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&parentjointindex_) -
      reinterpret_cast<char*>(&enabled_)) + sizeof(parentjointindex_));
  _internal_metadata_.Clear<std::string>();
}

const char* meshData_proto::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool enabled = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          enabled_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes pName = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_pname();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .meshData_proto.RENDER_MODE mode = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_mode(static_cast<::meshData_proto_RENDER_MODE>(val));
        } else goto handle_unusual;
        continue;
      // .vboData_proto vbo_vert = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_vbo_vert(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .vboData_proto vbo_norm = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ctx->ParseMessage(_internal_mutable_vbo_norm(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .vboData_proto vbo_uv = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr = ctx->ParseMessage(_internal_mutable_vbo_uv(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .vboData_proto vbo_index = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58)) {
          ptr = ctx->ParseMessage(_internal_mutable_vbo_index(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .vboData_proto vbo_color = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 66)) {
          ptr = ctx->ParseMessage(_internal_mutable_vbo_color(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .vboData_proto vbo_weights = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 74)) {
          ptr = ctx->ParseMessage(_internal_mutable_vbo_weights(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .vboData_proto vbo_joints = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 82)) {
          ptr = ctx->ParseMessage(_internal_mutable_vbo_joints(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .vboData_proto vbo_invBind = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 90)) {
          ptr = ctx->ParseMessage(_internal_mutable_vbo_invbind(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 triCount = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 96)) {
          tricount_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 vertCount = 13;
      case 13:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 104)) {
          vertcount_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 materialIndex = 14;
      case 14:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 112)) {
          materialindex_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // sint32 jointIndex = 15;
      case 15:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 120)) {
          jointindex_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // sint32 parentJointIndex = 16;
      case 16:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 128)) {
          parentjointindex_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarintZigZag32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<std::string>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* meshData_proto::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:meshData_proto)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool enabled = 1;
  if (this->_internal_enabled() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_enabled(), target);
  }

  // bytes pName = 2;
  if (!this->_internal_pname().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_pname(), target);
  }

  // .meshData_proto.RENDER_MODE mode = 3;
  if (this->_internal_mode() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      3, this->_internal_mode(), target);
  }

  // .vboData_proto vbo_vert = 4;
  if (this->_internal_has_vbo_vert()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::vbo_vert(this), target, stream);
  }

  // .vboData_proto vbo_norm = 5;
  if (this->_internal_has_vbo_norm()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        5, _Internal::vbo_norm(this), target, stream);
  }

  // .vboData_proto vbo_uv = 6;
  if (this->_internal_has_vbo_uv()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        6, _Internal::vbo_uv(this), target, stream);
  }

  // .vboData_proto vbo_index = 7;
  if (this->_internal_has_vbo_index()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        7, _Internal::vbo_index(this), target, stream);
  }

  // .vboData_proto vbo_color = 8;
  if (this->_internal_has_vbo_color()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        8, _Internal::vbo_color(this), target, stream);
  }

  // .vboData_proto vbo_weights = 9;
  if (this->_internal_has_vbo_weights()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        9, _Internal::vbo_weights(this), target, stream);
  }

  // .vboData_proto vbo_joints = 10;
  if (this->_internal_has_vbo_joints()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        10, _Internal::vbo_joints(this), target, stream);
  }

  // .vboData_proto vbo_invBind = 11;
  if (this->_internal_has_vbo_invbind()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        11, _Internal::vbo_invbind(this), target, stream);
  }

  // uint32 triCount = 12;
  if (this->_internal_tricount() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(12, this->_internal_tricount(), target);
  }

  // uint32 vertCount = 13;
  if (this->_internal_vertcount() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(13, this->_internal_vertcount(), target);
  }

  // uint32 materialIndex = 14;
  if (this->_internal_materialindex() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(14, this->_internal_materialindex(), target);
  }

  // sint32 jointIndex = 15;
  if (this->_internal_jointindex() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(15, this->_internal_jointindex(), target);
  }

  // sint32 parentJointIndex = 16;
  if (this->_internal_parentjointindex() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteSInt32ToArray(16, this->_internal_parentjointindex(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:meshData_proto)
  return target;
}

size_t meshData_proto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:meshData_proto)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes pName = 2;
  if (!this->_internal_pname().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_pname());
  }

  // .vboData_proto vbo_vert = 4;
  if (this->_internal_has_vbo_vert()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *vbo_vert_);
  }

  // .vboData_proto vbo_norm = 5;
  if (this->_internal_has_vbo_norm()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *vbo_norm_);
  }

  // .vboData_proto vbo_uv = 6;
  if (this->_internal_has_vbo_uv()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *vbo_uv_);
  }

  // .vboData_proto vbo_index = 7;
  if (this->_internal_has_vbo_index()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *vbo_index_);
  }

  // .vboData_proto vbo_color = 8;
  if (this->_internal_has_vbo_color()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *vbo_color_);
  }

  // .vboData_proto vbo_weights = 9;
  if (this->_internal_has_vbo_weights()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *vbo_weights_);
  }

  // .vboData_proto vbo_joints = 10;
  if (this->_internal_has_vbo_joints()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *vbo_joints_);
  }

  // .vboData_proto vbo_invBind = 11;
  if (this->_internal_has_vbo_invbind()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *vbo_invbind_);
  }

  // bool enabled = 1;
  if (this->_internal_enabled() != 0) {
    total_size += 1 + 1;
  }

  // .meshData_proto.RENDER_MODE mode = 3;
  if (this->_internal_mode() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_mode());
  }

  // uint32 triCount = 12;
  if (this->_internal_tricount() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_tricount());
  }

  // uint32 vertCount = 13;
  if (this->_internal_vertcount() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_vertcount());
  }

  // uint32 materialIndex = 14;
  if (this->_internal_materialindex() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_materialindex());
  }

  // sint32 jointIndex = 15;
  if (this->_internal_jointindex() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_jointindex());
  }

  // sint32 parentJointIndex = 16;
  if (this->_internal_parentjointindex() != 0) {
    total_size += 2 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SInt32Size(
        this->_internal_parentjointindex());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void meshData_proto::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const meshData_proto*>(
      &from));
}

void meshData_proto::MergeFrom(const meshData_proto& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:meshData_proto)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_pname().empty()) {
    _internal_set_pname(from._internal_pname());
  }
  if (from._internal_has_vbo_vert()) {
    _internal_mutable_vbo_vert()->::vboData_proto::MergeFrom(from._internal_vbo_vert());
  }
  if (from._internal_has_vbo_norm()) {
    _internal_mutable_vbo_norm()->::vboData_proto::MergeFrom(from._internal_vbo_norm());
  }
  if (from._internal_has_vbo_uv()) {
    _internal_mutable_vbo_uv()->::vboData_proto::MergeFrom(from._internal_vbo_uv());
  }
  if (from._internal_has_vbo_index()) {
    _internal_mutable_vbo_index()->::vboData_proto::MergeFrom(from._internal_vbo_index());
  }
  if (from._internal_has_vbo_color()) {
    _internal_mutable_vbo_color()->::vboData_proto::MergeFrom(from._internal_vbo_color());
  }
  if (from._internal_has_vbo_weights()) {
    _internal_mutable_vbo_weights()->::vboData_proto::MergeFrom(from._internal_vbo_weights());
  }
  if (from._internal_has_vbo_joints()) {
    _internal_mutable_vbo_joints()->::vboData_proto::MergeFrom(from._internal_vbo_joints());
  }
  if (from._internal_has_vbo_invbind()) {
    _internal_mutable_vbo_invbind()->::vboData_proto::MergeFrom(from._internal_vbo_invbind());
  }
  if (from._internal_enabled() != 0) {
    _internal_set_enabled(from._internal_enabled());
  }
  if (from._internal_mode() != 0) {
    _internal_set_mode(from._internal_mode());
  }
  if (from._internal_tricount() != 0) {
    _internal_set_tricount(from._internal_tricount());
  }
  if (from._internal_vertcount() != 0) {
    _internal_set_vertcount(from._internal_vertcount());
  }
  if (from._internal_materialindex() != 0) {
    _internal_set_materialindex(from._internal_materialindex());
  }
  if (from._internal_jointindex() != 0) {
    _internal_set_jointindex(from._internal_jointindex());
  }
  if (from._internal_parentjointindex() != 0) {
    _internal_set_parentjointindex(from._internal_parentjointindex());
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void meshData_proto::CopyFrom(const meshData_proto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:meshData_proto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool meshData_proto::IsInitialized() const {
  return true;
}

void meshData_proto::InternalSwap(meshData_proto* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &pname_, GetArenaForAllocation(),
      &other->pname_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(meshData_proto, parentjointindex_)
      + sizeof(meshData_proto::parentjointindex_)
      - PROTOBUF_FIELD_OFFSET(meshData_proto, vbo_vert_)>(
          reinterpret_cast<char*>(&vbo_vert_),
          reinterpret_cast<char*>(&other->vbo_vert_));
}

std::string meshData_proto::GetTypeName() const {
  return "meshData_proto";
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::meshData_proto* Arena::CreateMaybeMessage< ::meshData_proto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::meshData_proto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
