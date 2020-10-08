#pragma once

#include <glm/mat4x4.hpp>

#include "gsl/string_span"
#include "Mesh.h"
#include "MeshData.h"
#include "../util/Color.h"
#include "../util/Vec3.h"

typedef gsl::basic_string_span<const char> string_span;

class Tessellator {
public:
	enum class UploadMode : int {
		NONE
	};

    bool mHasMeshData;
    mce::MeshData mMeshData;
    Vec3 mNormal;
    float mNormalWeight;
    bool mHasNormal;
    Vec2 mVertexUV;
    bool mHasVertex;
    Vec2 mTex1UV;
    bool mHasTex1;
    Vec2 mTex2UV;
    bool mHasTex2;
    int mColor;
    bool mHasColor;
    char filler0[3];
    unsigned short mBone0;
    bool mHasBone0;
    unsigned short mIndexPhase;
    Vec3 mPostTransformOffset;
    char filler1[60];
    bool mShouldApplyTransform;
    glm::mat4 mTransform;
    bool mNoColor;
    bool mIsOverriden;
    bool mForceTessellateIntercept;
    char filler2[57];
    int64_t field_1F0;
    int field_1F8;
    bool mTessellating;
    bool mBuildFaceData;

    void addPostTransformOffset(float, float, float);
	void beginOverride();
	void color(const Color&);

	mce::Mesh endOverride(string_span str) {
		mIsOverriden = false;
		return end(UploadMode::NONE, str);
	}
	mce::Mesh end(UploadMode, string_span);

    bool _tex(const Vec2&, int);
};