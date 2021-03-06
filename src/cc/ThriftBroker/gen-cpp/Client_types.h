/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef Client_TYPES_H
#define Client_TYPES_H

#include <Thrift.h>
#include <TApplicationException.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>



namespace Hypertable { namespace ThriftGen {

enum KeyFlag {
  DELETE_ROW = 0,
  DELETE_CF = 1,
  DELETE_CELL = 2,
  INSERT = 255
};

enum MutatorFlag {
  NO_LOG_SYNC = 1,
  IGNORE_UNKNOWN_CFS = 2
};

typedef int64_t Namespace;

typedef int64_t Scanner;

typedef int64_t Mutator;

typedef std::string Value;

typedef std::vector<std::string>  CellAsArray;

typedef std::string CellsSerialized;

typedef struct _RowInterval__isset {
  _RowInterval__isset() : start_row(false), start_inclusive(false), end_row(false), end_inclusive(false) {}
  bool start_row;
  bool start_inclusive;
  bool end_row;
  bool end_inclusive;
} _RowInterval__isset;

class RowInterval {
 public:

  static const char* ascii_fingerprint; // = "E1A4BCD94F003EFF8636F1C98591705A";
  static const uint8_t binary_fingerprint[16]; // = {0xE1,0xA4,0xBC,0xD9,0x4F,0x00,0x3E,0xFF,0x86,0x36,0xF1,0xC9,0x85,0x91,0x70,0x5A};

  RowInterval() : start_row(""), start_inclusive(true), end_row(""), end_inclusive(true) {
  }

  virtual ~RowInterval() throw() {}

  std::string start_row;
  bool start_inclusive;
  std::string end_row;
  bool end_inclusive;

  _RowInterval__isset __isset;

  bool operator == (const RowInterval & rhs) const
  {
    if (__isset.start_row != rhs.__isset.start_row)
      return false;
    else if (__isset.start_row && !(start_row == rhs.start_row))
      return false;
    if (__isset.start_inclusive != rhs.__isset.start_inclusive)
      return false;
    else if (__isset.start_inclusive && !(start_inclusive == rhs.start_inclusive))
      return false;
    if (__isset.end_row != rhs.__isset.end_row)
      return false;
    else if (__isset.end_row && !(end_row == rhs.end_row))
      return false;
    if (__isset.end_inclusive != rhs.__isset.end_inclusive)
      return false;
    else if (__isset.end_inclusive && !(end_inclusive == rhs.end_inclusive))
      return false;
    return true;
  }
  bool operator != (const RowInterval &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RowInterval & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CellInterval__isset {
  _CellInterval__isset() : start_row(false), start_column(false), start_inclusive(false), end_row(false), end_column(false), end_inclusive(false) {}
  bool start_row;
  bool start_column;
  bool start_inclusive;
  bool end_row;
  bool end_column;
  bool end_inclusive;
} _CellInterval__isset;

class CellInterval {
 public:

  static const char* ascii_fingerprint; // = "D8C6D6FAE68BF8B6CA0EB2AB01E82C6C";
  static const uint8_t binary_fingerprint[16]; // = {0xD8,0xC6,0xD6,0xFA,0xE6,0x8B,0xF8,0xB6,0xCA,0x0E,0xB2,0xAB,0x01,0xE8,0x2C,0x6C};

  CellInterval() : start_row(""), start_column(""), start_inclusive(true), end_row(""), end_column(""), end_inclusive(true) {
  }

  virtual ~CellInterval() throw() {}

  std::string start_row;
  std::string start_column;
  bool start_inclusive;
  std::string end_row;
  std::string end_column;
  bool end_inclusive;

  _CellInterval__isset __isset;

  bool operator == (const CellInterval & rhs) const
  {
    if (__isset.start_row != rhs.__isset.start_row)
      return false;
    else if (__isset.start_row && !(start_row == rhs.start_row))
      return false;
    if (__isset.start_column != rhs.__isset.start_column)
      return false;
    else if (__isset.start_column && !(start_column == rhs.start_column))
      return false;
    if (__isset.start_inclusive != rhs.__isset.start_inclusive)
      return false;
    else if (__isset.start_inclusive && !(start_inclusive == rhs.start_inclusive))
      return false;
    if (__isset.end_row != rhs.__isset.end_row)
      return false;
    else if (__isset.end_row && !(end_row == rhs.end_row))
      return false;
    if (__isset.end_column != rhs.__isset.end_column)
      return false;
    else if (__isset.end_column && !(end_column == rhs.end_column))
      return false;
    if (__isset.end_inclusive != rhs.__isset.end_inclusive)
      return false;
    else if (__isset.end_inclusive && !(end_inclusive == rhs.end_inclusive))
      return false;
    return true;
  }
  bool operator != (const CellInterval &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CellInterval & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ScanSpec__isset {
  _ScanSpec__isset() : row_intervals(false), cell_intervals(false), return_deletes(false), revs(false), row_limit(false), start_time(false), end_time(false), columns(false), keys_only(false), cell_limit(false) {}
  bool row_intervals;
  bool cell_intervals;
  bool return_deletes;
  bool revs;
  bool row_limit;
  bool start_time;
  bool end_time;
  bool columns;
  bool keys_only;
  bool cell_limit;
} _ScanSpec__isset;

class ScanSpec {
 public:

  static const char* ascii_fingerprint; // = "91DF708E7D26454C6B44234FDA883528";
  static const uint8_t binary_fingerprint[16]; // = {0x91,0xDF,0x70,0x8E,0x7D,0x26,0x45,0x4C,0x6B,0x44,0x23,0x4F,0xDA,0x88,0x35,0x28};

  ScanSpec() : return_deletes(false), revs(0), row_limit(0), start_time(0), end_time(0), keys_only(false), cell_limit(0) {
  }

  virtual ~ScanSpec() throw() {}

  std::vector<RowInterval>  row_intervals;
  std::vector<CellInterval>  cell_intervals;
  bool return_deletes;
  int32_t revs;
  int32_t row_limit;
  int64_t start_time;
  int64_t end_time;
  std::vector<std::string>  columns;
  bool keys_only;
  int32_t cell_limit;

  _ScanSpec__isset __isset;

  bool operator == (const ScanSpec & rhs) const
  {
    if (__isset.row_intervals != rhs.__isset.row_intervals)
      return false;
    else if (__isset.row_intervals && !(row_intervals == rhs.row_intervals))
      return false;
    if (__isset.cell_intervals != rhs.__isset.cell_intervals)
      return false;
    else if (__isset.cell_intervals && !(cell_intervals == rhs.cell_intervals))
      return false;
    if (__isset.return_deletes != rhs.__isset.return_deletes)
      return false;
    else if (__isset.return_deletes && !(return_deletes == rhs.return_deletes))
      return false;
    if (__isset.revs != rhs.__isset.revs)
      return false;
    else if (__isset.revs && !(revs == rhs.revs))
      return false;
    if (__isset.row_limit != rhs.__isset.row_limit)
      return false;
    else if (__isset.row_limit && !(row_limit == rhs.row_limit))
      return false;
    if (__isset.start_time != rhs.__isset.start_time)
      return false;
    else if (__isset.start_time && !(start_time == rhs.start_time))
      return false;
    if (__isset.end_time != rhs.__isset.end_time)
      return false;
    else if (__isset.end_time && !(end_time == rhs.end_time))
      return false;
    if (__isset.columns != rhs.__isset.columns)
      return false;
    else if (__isset.columns && !(columns == rhs.columns))
      return false;
    if (__isset.keys_only != rhs.__isset.keys_only)
      return false;
    else if (__isset.keys_only && !(keys_only == rhs.keys_only))
      return false;
    if (__isset.cell_limit != rhs.__isset.cell_limit)
      return false;
    else if (__isset.cell_limit && !(cell_limit == rhs.cell_limit))
      return false;
    return true;
  }
  bool operator != (const ScanSpec &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ScanSpec & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Key__isset {
  _Key__isset() : row(false), column_family(false), column_qualifier(false), timestamp(false), revision(false), flag(false) {}
  bool row;
  bool column_family;
  bool column_qualifier;
  bool timestamp;
  bool revision;
  bool flag;
} _Key__isset;

class Key {
 public:

  static const char* ascii_fingerprint; // = "052C5786CACCF64BCAAB76EA122375F2";
  static const uint8_t binary_fingerprint[16]; // = {0x05,0x2C,0x57,0x86,0xCA,0xCC,0xF6,0x4B,0xCA,0xAB,0x76,0xEA,0x12,0x23,0x75,0xF2};

  Key() : row(""), column_family(""), column_qualifier(""), timestamp(0), revision(0), flag(255) {
  }

  virtual ~Key() throw() {}

  std::string row;
  std::string column_family;
  std::string column_qualifier;
  int64_t timestamp;
  int64_t revision;
  int16_t flag;

  _Key__isset __isset;

  bool operator == (const Key & rhs) const
  {
    if (!(row == rhs.row))
      return false;
    if (!(column_family == rhs.column_family))
      return false;
    if (!(column_qualifier == rhs.column_qualifier))
      return false;
    if (__isset.timestamp != rhs.__isset.timestamp)
      return false;
    else if (__isset.timestamp && !(timestamp == rhs.timestamp))
      return false;
    if (__isset.revision != rhs.__isset.revision)
      return false;
    else if (__isset.revision && !(revision == rhs.revision))
      return false;
    if (!(flag == rhs.flag))
      return false;
    return true;
  }
  bool operator != (const Key &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Key & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MutateSpec {
 public:

  static const char* ascii_fingerprint; // = "28C2ECC89260BADB9C70330FBF47BFA8";
  static const uint8_t binary_fingerprint[16]; // = {0x28,0xC2,0xEC,0xC8,0x92,0x60,0xBA,0xDB,0x9C,0x70,0x33,0x0F,0xBF,0x47,0xBF,0xA8};

  MutateSpec() : appname(""), flush_interval(1000), flags(2) {
  }

  virtual ~MutateSpec() throw() {}

  std::string appname;
  int32_t flush_interval;
  int32_t flags;

  bool operator == (const MutateSpec & rhs) const
  {
    if (!(appname == rhs.appname))
      return false;
    if (!(flush_interval == rhs.flush_interval))
      return false;
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const MutateSpec &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MutateSpec & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Cell__isset {
  _Cell__isset() : key(false), value(false) {}
  bool key;
  bool value;
} _Cell__isset;

class Cell {
 public:

  static const char* ascii_fingerprint; // = "E89C732825E6CBAB4D286303434183C3";
  static const uint8_t binary_fingerprint[16]; // = {0xE8,0x9C,0x73,0x28,0x25,0xE6,0xCB,0xAB,0x4D,0x28,0x63,0x03,0x43,0x41,0x83,0xC3};

  Cell() : value("") {
  }

  virtual ~Cell() throw() {}

  Key key;
  Value value;

  _Cell__isset __isset;

  bool operator == (const Cell & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (__isset.value != rhs.__isset.value)
      return false;
    else if (__isset.value && !(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const Cell &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Cell & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class NamespaceListing {
 public:

  static const char* ascii_fingerprint; // = "7D61C9AA00102AB4D8F72A1DA58297DC";
  static const uint8_t binary_fingerprint[16]; // = {0x7D,0x61,0xC9,0xAA,0x00,0x10,0x2A,0xB4,0xD8,0xF7,0x2A,0x1D,0xA5,0x82,0x97,0xDC};

  NamespaceListing() : name(""), is_namespace(0) {
  }

  virtual ~NamespaceListing() throw() {}

  std::string name;
  bool is_namespace;

  bool operator == (const NamespaceListing & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(is_namespace == rhs.is_namespace))
      return false;
    return true;
  }
  bool operator != (const NamespaceListing &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NamespaceListing & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TableSplit__isset {
  _TableSplit__isset() : start_row(false), end_row(false), location(false), ip_address(false) {}
  bool start_row;
  bool end_row;
  bool location;
  bool ip_address;
} _TableSplit__isset;

class TableSplit {
 public:

  static const char* ascii_fingerprint; // = "7F96769A10DED7E9839D38968220F75A";
  static const uint8_t binary_fingerprint[16]; // = {0x7F,0x96,0x76,0x9A,0x10,0xDE,0xD7,0xE9,0x83,0x9D,0x38,0x96,0x82,0x20,0xF7,0x5A};

  TableSplit() : start_row(""), end_row(""), location(""), ip_address("") {
  }

  virtual ~TableSplit() throw() {}

  std::string start_row;
  std::string end_row;
  std::string location;
  std::string ip_address;

  _TableSplit__isset __isset;

  bool operator == (const TableSplit & rhs) const
  {
    if (__isset.start_row != rhs.__isset.start_row)
      return false;
    else if (__isset.start_row && !(start_row == rhs.start_row))
      return false;
    if (__isset.end_row != rhs.__isset.end_row)
      return false;
    else if (__isset.end_row && !(end_row == rhs.end_row))
      return false;
    if (__isset.location != rhs.__isset.location)
      return false;
    else if (__isset.location && !(location == rhs.location))
      return false;
    if (__isset.ip_address != rhs.__isset.ip_address)
      return false;
    else if (__isset.ip_address && !(ip_address == rhs.ip_address))
      return false;
    return true;
  }
  bool operator != (const TableSplit &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TableSplit & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ColumnFamily__isset {
  _ColumnFamily__isset() : name(false), ag(false), max_versions(false), ttl(false) {}
  bool name;
  bool ag;
  bool max_versions;
  bool ttl;
} _ColumnFamily__isset;

class ColumnFamily {
 public:

  static const char* ascii_fingerprint; // = "0EDE17B70FBE0133B4243A5167158E5C";
  static const uint8_t binary_fingerprint[16]; // = {0x0E,0xDE,0x17,0xB7,0x0F,0xBE,0x01,0x33,0xB4,0x24,0x3A,0x51,0x67,0x15,0x8E,0x5C};

  ColumnFamily() : name(""), ag(""), max_versions(0), ttl("") {
  }

  virtual ~ColumnFamily() throw() {}

  std::string name;
  std::string ag;
  int32_t max_versions;
  std::string ttl;

  _ColumnFamily__isset __isset;

  bool operator == (const ColumnFamily & rhs) const
  {
    if (__isset.name != rhs.__isset.name)
      return false;
    else if (__isset.name && !(name == rhs.name))
      return false;
    if (__isset.ag != rhs.__isset.ag)
      return false;
    else if (__isset.ag && !(ag == rhs.ag))
      return false;
    if (__isset.max_versions != rhs.__isset.max_versions)
      return false;
    else if (__isset.max_versions && !(max_versions == rhs.max_versions))
      return false;
    if (__isset.ttl != rhs.__isset.ttl)
      return false;
    else if (__isset.ttl && !(ttl == rhs.ttl))
      return false;
    return true;
  }
  bool operator != (const ColumnFamily &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ColumnFamily & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _AccessGroup__isset {
  _AccessGroup__isset() : name(false), in_memory(false), replication(false), blocksize(false), compressor(false), bloom_filter(false), columns(false) {}
  bool name;
  bool in_memory;
  bool replication;
  bool blocksize;
  bool compressor;
  bool bloom_filter;
  bool columns;
} _AccessGroup__isset;

class AccessGroup {
 public:

  static const char* ascii_fingerprint; // = "17108017AF8680A78499DB15024EC92B";
  static const uint8_t binary_fingerprint[16]; // = {0x17,0x10,0x80,0x17,0xAF,0x86,0x80,0xA7,0x84,0x99,0xDB,0x15,0x02,0x4E,0xC9,0x2B};

  AccessGroup() : name(""), in_memory(0), replication(0), blocksize(0), compressor(""), bloom_filter("") {
  }

  virtual ~AccessGroup() throw() {}

  std::string name;
  bool in_memory;
  int16_t replication;
  int32_t blocksize;
  std::string compressor;
  std::string bloom_filter;
  std::vector<ColumnFamily>  columns;

  _AccessGroup__isset __isset;

  bool operator == (const AccessGroup & rhs) const
  {
    if (__isset.name != rhs.__isset.name)
      return false;
    else if (__isset.name && !(name == rhs.name))
      return false;
    if (__isset.in_memory != rhs.__isset.in_memory)
      return false;
    else if (__isset.in_memory && !(in_memory == rhs.in_memory))
      return false;
    if (__isset.replication != rhs.__isset.replication)
      return false;
    else if (__isset.replication && !(replication == rhs.replication))
      return false;
    if (__isset.blocksize != rhs.__isset.blocksize)
      return false;
    else if (__isset.blocksize && !(blocksize == rhs.blocksize))
      return false;
    if (__isset.compressor != rhs.__isset.compressor)
      return false;
    else if (__isset.compressor && !(compressor == rhs.compressor))
      return false;
    if (__isset.bloom_filter != rhs.__isset.bloom_filter)
      return false;
    else if (__isset.bloom_filter && !(bloom_filter == rhs.bloom_filter))
      return false;
    if (__isset.columns != rhs.__isset.columns)
      return false;
    else if (__isset.columns && !(columns == rhs.columns))
      return false;
    return true;
  }
  bool operator != (const AccessGroup &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AccessGroup & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Schema__isset {
  _Schema__isset() : access_groups(false), column_families(false) {}
  bool access_groups;
  bool column_families;
} _Schema__isset;

class Schema {
 public:

  static const char* ascii_fingerprint; // = "69B5DA4C91BFF355857D905B1B5A3A03";
  static const uint8_t binary_fingerprint[16]; // = {0x69,0xB5,0xDA,0x4C,0x91,0xBF,0xF3,0x55,0x85,0x7D,0x90,0x5B,0x1B,0x5A,0x3A,0x03};

  Schema() {
  }

  virtual ~Schema() throw() {}

  std::map<std::string, AccessGroup>  access_groups;
  std::map<std::string, ColumnFamily>  column_families;

  _Schema__isset __isset;

  bool operator == (const Schema & rhs) const
  {
    if (__isset.access_groups != rhs.__isset.access_groups)
      return false;
    else if (__isset.access_groups && !(access_groups == rhs.access_groups))
      return false;
    if (__isset.column_families != rhs.__isset.column_families)
      return false;
    else if (__isset.column_families && !(column_families == rhs.column_families))
      return false;
    return true;
  }
  bool operator != (const Schema &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Schema & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientException__isset {
  _ClientException__isset() : code(false), message(false) {}
  bool code;
  bool message;
} _ClientException__isset;

class ClientException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "3F5FC93B338687BC7235B1AB103F47B3";
  static const uint8_t binary_fingerprint[16]; // = {0x3F,0x5F,0xC9,0x3B,0x33,0x86,0x87,0xBC,0x72,0x35,0xB1,0xAB,0x10,0x3F,0x47,0xB3};

  ClientException() : code(0), message("") {
  }

  virtual ~ClientException() throw() {}

  int32_t code;
  std::string message;

  _ClientException__isset __isset;

  bool operator == (const ClientException & rhs) const
  {
    if (!(code == rhs.code))
      return false;
    if (!(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const ClientException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

}} // namespace

#endif
