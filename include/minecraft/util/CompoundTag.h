#pragma once

#include "gsl/string_span"

typedef gsl::basic_string_span<const char> string_span;

class Tag {};

class CompoundTag : public Tag {
public:
#ifdef _WIN32
    typedef string_span StringView;
#else
    typedef const std::string& StringView;
#endif
    char filler[0x18];

    CompoundTag();
    virtual ~CompoundTag();
    float& putFloat(std::string, float);
    float getFloat(StringView) const;
    int& putInt(std::string, int);
    int getInt(StringView) const;
    short& putShort(std::string, short);
    short getShort(StringView) const;
    bool contains(StringView) const;
};