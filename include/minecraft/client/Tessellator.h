#pragma once

#include "gsl/string_span"
#include "Mesh.h"
#include "../util/Color.h"

typedef gsl::basic_string_span<const char> string_span;

class Tessellator {
public:
	enum class UploadMode : int {
		NONE
	};

	char filler[0x1B5];
	bool mOverride;

	void addPostTransformOffset(float, float, float);
	void beginOverride();
	void color(const Color&);

	mce::Mesh endOverride(string_span str) {
		mOverride = false;
		return end(UploadMode::NONE, str);
	}
	mce::Mesh end(UploadMode, string_span);
};