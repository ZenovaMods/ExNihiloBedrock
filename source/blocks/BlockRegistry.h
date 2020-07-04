#pragma once

#include <vector>
#include <string>

#include "minecraft/util/SharedPtr.h"
#include "minecraft/block/BlockTypeRegistry.h"
#include "minecraft/block/BlockDefinitionGroup.h"
#include "minecraft/client/BlockGraphics.h"

namespace Zenova {
	class BlockRegistry {
	public:
		class BlockDeclaration {
		public:
			std::string nameId;
			BlockShape blockShape;

			BlockDeclaration(std::string name, BlockShape shape) : nameId(name), blockShape(shape) {}

			virtual void initBlock(BlockDefinitionGroup* blockGroup) = 0;
			virtual void initBlockGraphics(std::vector<Json::Value>&) = 0;
		};

		template<class T, typename... Args>
		class BlockRegistryDeclaration : public BlockDeclaration {
		public:
			WeakPtr<BlockLegacy>* blockPointer;
			std::tuple<Args...> arguments;

			BlockRegistryDeclaration(std::string name, BlockShape shape, Args&&... args) : BlockDeclaration(name, shape), arguments(args...), blockPointer(new WeakPtr<BlockLegacy>()) {}

			virtual void initBlock(BlockDefinitionGroup* blockGroup) {
				*blockPointer = registerBlock(blockGroup, std::index_sequence_for<Args...>{});
			}

			virtual void initBlockGraphics(std::vector<Json::Value>& json) {
				BlockGraphics::registerBlockGraphics(json, nameId, blockShape);
			}

			template<std::size_t ...I>
			WeakPtr<BlockLegacy> registerBlock(BlockDefinitionGroup* blockGroup, std::index_sequence<I...>) {
				return BlockTypeRegistry::registerBlock<T>("exnihilo:" + nameId, blockGroup->getNextBlockId(), std::get<I>(arguments)...)
					.setIsVanillaBlock(false)
					.createWeakPtr();
			}
		};

		static std::vector<BlockDeclaration*> BlockRegistryList;

		template<class T, typename... Args>
		static WeakPtr<BlockLegacy>* registerBlock(std::string name, BlockShape shape, Args&&... args) {
			BlockRegistryDeclaration<T, Args...>* decl = new BlockRegistryDeclaration<T, Args...>(name, shape, std::forward<Args>(args)...);
			BlockRegistryList.push_back(decl);
			return decl->blockPointer;
		}
	};
	inline std::vector<BlockRegistry::BlockDeclaration*> BlockRegistry::BlockRegistryList{};
}