#pragma once

#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include "VertexFormat.h"

namespace mce {
	class MeshData {
	public:
		unsigned char mFormat;
		std::vector<glm::tvec3<float>> mVec1;
		std::vector<glm::tvec4<float>> mVec2;
		std::vector<unsigned int> mVec3;
		std::vector<unsigned int> mVec4;
		std::vector<unsigned short> mVec5;
		std::vector<glm::tvec2<float>> mVec6;
		std::vector<glm::tvec2<float>> mVec7;
		std::vector<glm::tvec2<float>> mVec8;
		mce::VertexFormat mFields;
		int mUnknown;

		MeshData();
		void clear();
		void reserveVertices();
		
		bool hasField(mce::VertexField field) const {
			return mFields.hasField(field);
		}

		bool enableField(mce::VertexField field) {
			mFields.enableField(field);
			return enum_cast(field);
		}
	};
}