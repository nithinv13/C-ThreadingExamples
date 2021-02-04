#include <cassert>
#include "rocksdb/db.h"

int main() {
    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;
    rocksdb::Status status = rocksdb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());
}

#include <iostream>
#include <cassert>
#include "rocksdb/db.h"
#include "rocksdb/env.h"
#include "rocksdb/sst_file_writer.h"
#include "rocksdb/sst_file_reader.h"
#include "rocksdb/iterator.h"
#include "rocksdb/rocksdb_namespace.h"

using namespace std;

int main() {
    // rocksdb::DB* db;
    rocksdb::Options options;
    // rocksdb::WriteOptions w_options;
    // rocksdb::EnvOptions env_options;
    // options.create_if_missing = true;
    // options.write_buffer_size = 2 << 10;  
    // rocksdb::Status status = rocksdb::DB::Open(options, "/tmp/testdb", &db);
    // assert(status.ok());
    // for (int i = 0; i < 1000000; i++) {
    //     status = db->Put(w_options, rocksdb::Slice(to_string(i)), rocksdb::Slice(to_string(i)));
    //     assert(status.ok());
    // }
    // rocksdb::SstFileWriter writer(env_options, options);
    // assert(writer.Open("temp.sst").ok());
    // std::vector<std::string> keys = {"one", "two"};
    // for (size_t i = 0; i < keys.size(); i++) {
    //   assert(writer.Put(keys[i], keys[i]).ok());
    // }
    // assert(writer.Finish().ok());
    options.compression = rocksdb::kSnappyCompression;
    rocksdb::SstFileReader reader(options);
    assert(reader.Open("temp.sst").ok());
    std::unique_ptr<rocksdb::Iterator> iter;
    {
        rocksdb::ReadOptions ropts;
        iter.reset(reader.NewIterator(ropts));
    }
    iter->SeekToFirst();
    while (iter->Valid()) {
        cout << iter->key().data() << iter->value().ToString() << endl;
        iter->Next();
    }
}