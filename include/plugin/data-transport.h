#pragma once
#include <core.h>
#include <dicom-file.h>

#include <mutex>
#include <unordered_map>
#include <unordered_set>

using Uuid = std::string;
using Md5 = std::string;

class DataTransport {
private:
    static std::mutex checksum_lock;
    static std::mutex uuid_lock;
    static std::mutex file_lock;
    static std::mutex hashes_lock;
    static std::unordered_map<const void*, std::tuple<Md5, size_t>> checksum_map;
    static std::unordered_map<const void*, Uuid> uuid_map;
    static std::unordered_map<const void*, DicomFile> file_map;
    static std::unordered_set<Md5> hashes_map;
public:
    static void Emplace(const void* instance_data, std::string md5, size_t size);
    static void Emplace(const void* instance_data, std::string uuid);
    static void Emplace(const void* instance_data, const DicomFile& file);
    static bool Emplace(std::string md5);
    static DicomFile PopFile(const void* instance_data);
    static DicomFile PeekFile(const void* instance_data);
    static bool UpdateDatabase(const void* instance_data);
};