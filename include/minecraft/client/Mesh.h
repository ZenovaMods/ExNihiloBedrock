#pragma once

namespace mce {
	class Mesh {
	public:
		char filler[0x198];

		Mesh();
		~Mesh();
		bool isValid() const;
		void reset();
	};
}