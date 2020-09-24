#pragma once

#include <gsl/span>

namespace mce {
	class ClientTexture;
	class MaterialPtr;
	class MeshContext;
	class IndexBufferContainer;

	class Mesh {
	public:
		char filler[0x198];

		Mesh();
		~Mesh();
		bool isValid() const;
		void reset();
		void renderMesh(MeshContext&, const MaterialPtr&, gsl::span<const ClientTexture*>, unsigned int, unsigned int, const IndexBufferContainer*) const;
	};
}