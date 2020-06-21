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

    short& putShort(std::string, short);
    short getShort(StringView) const;
};