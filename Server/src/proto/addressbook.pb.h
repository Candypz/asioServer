// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: addressbook.proto

#ifndef PROTOBUF_addressbook_2eproto__INCLUDED
#define PROTOBUF_addressbook_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_addressbook_2eproto();
void protobuf_AssignDesc_addressbook_2eproto();
void protobuf_ShutdownFile_addressbook_2eproto();

class Secret_Get_Req;
class helloworld;

// ===================================================================

class Secret_Get_Req : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Secret_Get_Req) */ {
 public:
  Secret_Get_Req();
  virtual ~Secret_Get_Req();

  Secret_Get_Req(const Secret_Get_Req& from);

  inline Secret_Get_Req& operator=(const Secret_Get_Req& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Secret_Get_Req& default_instance();

  void Swap(Secret_Get_Req* other);

  // implements Message ----------------------------------------------

  inline Secret_Get_Req* New() const { return New(NULL); }

  Secret_Get_Req* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Secret_Get_Req& from);
  void MergeFrom(const Secret_Get_Req& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Secret_Get_Req* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 version = 1;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // optional .helloworld msg_req_list = 2;
  bool has_msg_req_list() const;
  void clear_msg_req_list();
  static const int kMsgReqListFieldNumber = 2;
  const ::helloworld& msg_req_list() const;
  ::helloworld* mutable_msg_req_list();
  ::helloworld* release_msg_req_list();
  void set_allocated_msg_req_list(::helloworld* msg_req_list);

  // @@protoc_insertion_point(class_scope:Secret_Get_Req)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::helloworld* msg_req_list_;
  ::google::protobuf::uint32 version_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_addressbook_2eproto();
  friend void protobuf_AssignDesc_addressbook_2eproto();
  friend void protobuf_ShutdownFile_addressbook_2eproto();

  void InitAsDefaultInstance();
  static Secret_Get_Req* default_instance_;
};
// -------------------------------------------------------------------

class helloworld : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:helloworld) */ {
 public:
  helloworld();
  virtual ~helloworld();

  helloworld(const helloworld& from);

  inline helloworld& operator=(const helloworld& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const helloworld& default_instance();

  void Swap(helloworld* other);

  // implements Message ----------------------------------------------

  inline helloworld* New() const { return New(NULL); }

  helloworld* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const helloworld& from);
  void MergeFrom(const helloworld& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(helloworld* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // optional string str = 2;
  void clear_str();
  static const int kStrFieldNumber = 2;
  const ::std::string& str() const;
  void set_str(const ::std::string& value);
  void set_str(const char* value);
  void set_str(const char* value, size_t size);
  ::std::string* mutable_str();
  ::std::string* release_str();
  void set_allocated_str(::std::string* str);

  // optional int32 opt = 3;
  void clear_opt();
  static const int kOptFieldNumber = 3;
  ::google::protobuf::int32 opt() const;
  void set_opt(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:helloworld)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr str_;
  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 opt_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_addressbook_2eproto();
  friend void protobuf_AssignDesc_addressbook_2eproto();
  friend void protobuf_ShutdownFile_addressbook_2eproto();

  void InitAsDefaultInstance();
  static helloworld* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Secret_Get_Req

// optional uint32 version = 1;
inline void Secret_Get_Req::clear_version() {
  version_ = 0u;
}
inline ::google::protobuf::uint32 Secret_Get_Req::version() const {
  // @@protoc_insertion_point(field_get:Secret_Get_Req.version)
  return version_;
}
inline void Secret_Get_Req::set_version(::google::protobuf::uint32 value) {
  
  version_ = value;
  // @@protoc_insertion_point(field_set:Secret_Get_Req.version)
}

// optional .helloworld msg_req_list = 2;
inline bool Secret_Get_Req::has_msg_req_list() const {
  return !_is_default_instance_ && msg_req_list_ != NULL;
}
inline void Secret_Get_Req::clear_msg_req_list() {
  if (GetArenaNoVirtual() == NULL && msg_req_list_ != NULL) delete msg_req_list_;
  msg_req_list_ = NULL;
}
inline const ::helloworld& Secret_Get_Req::msg_req_list() const {
  // @@protoc_insertion_point(field_get:Secret_Get_Req.msg_req_list)
  return msg_req_list_ != NULL ? *msg_req_list_ : *default_instance_->msg_req_list_;
}
inline ::helloworld* Secret_Get_Req::mutable_msg_req_list() {
  
  if (msg_req_list_ == NULL) {
    msg_req_list_ = new ::helloworld;
  }
  // @@protoc_insertion_point(field_mutable:Secret_Get_Req.msg_req_list)
  return msg_req_list_;
}
inline ::helloworld* Secret_Get_Req::release_msg_req_list() {
  // @@protoc_insertion_point(field_release:Secret_Get_Req.msg_req_list)
  
  ::helloworld* temp = msg_req_list_;
  msg_req_list_ = NULL;
  return temp;
}
inline void Secret_Get_Req::set_allocated_msg_req_list(::helloworld* msg_req_list) {
  delete msg_req_list_;
  msg_req_list_ = msg_req_list;
  if (msg_req_list) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Secret_Get_Req.msg_req_list)
}

// -------------------------------------------------------------------

// helloworld

// optional int32 id = 1;
inline void helloworld::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 helloworld::id() const {
  // @@protoc_insertion_point(field_get:helloworld.id)
  return id_;
}
inline void helloworld::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:helloworld.id)
}

// optional string str = 2;
inline void helloworld::clear_str() {
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& helloworld::str() const {
  // @@protoc_insertion_point(field_get:helloworld.str)
  return str_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void helloworld::set_str(const ::std::string& value) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:helloworld.str)
}
inline void helloworld::set_str(const char* value) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:helloworld.str)
}
inline void helloworld::set_str(const char* value, size_t size) {
  
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:helloworld.str)
}
inline ::std::string* helloworld::mutable_str() {
  
  // @@protoc_insertion_point(field_mutable:helloworld.str)
  return str_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* helloworld::release_str() {
  // @@protoc_insertion_point(field_release:helloworld.str)
  
  return str_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void helloworld::set_allocated_str(::std::string* str) {
  if (str != NULL) {
    
  } else {
    
  }
  str_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), str);
  // @@protoc_insertion_point(field_set_allocated:helloworld.str)
}

// optional int32 opt = 3;
inline void helloworld::clear_opt() {
  opt_ = 0;
}
inline ::google::protobuf::int32 helloworld::opt() const {
  // @@protoc_insertion_point(field_get:helloworld.opt)
  return opt_;
}
inline void helloworld::set_opt(::google::protobuf::int32 value) {
  
  opt_ = value;
  // @@protoc_insertion_point(field_set:helloworld.opt)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_addressbook_2eproto__INCLUDED