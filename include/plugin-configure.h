#pragma once
#include <core.h>
#include <dicom-filter.h>

class PluginConfigurer {
private:
    static nlm::json config;
    static DicomFilter filter;
protected:
public:
    static int Initialize();
    static DicomFilter GetDicomFilter() { return {filter}; }
    static std::string GetDateFormat(uint64_t tag_code = 0);
};