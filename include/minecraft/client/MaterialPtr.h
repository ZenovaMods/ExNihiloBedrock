#pragma once

namespace mce {
	class MaterialPtr {
	public:
		char mMaterialInfo[0x10];

		~MaterialPtr();
	};
}