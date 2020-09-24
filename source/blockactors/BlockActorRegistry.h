#pragma once

#include "minecraft/blockactor/BlockActor.h"
#include "minecraft/block/ActorBlock.h"

namespace Zenova {
	class BlockActorRegistry {
	public:
		class BlockActorDeclaration {
		public:
			std::string mNameId;
			BlockActorType mType;
			WeakPtr<BlockLegacy>* mActorBlock;

			BlockActorDeclaration(const std::string& nameId, BlockActorType type, WeakPtr<BlockLegacy>* actorBlock)
				: mNameId(nameId), mType(type), mActorBlock(actorBlock) {}

			void setId() {
				BlockActor::setId(mType, mNameId);
			}

			std::shared_ptr<BlockActor> createBlockEntity(const BlockPos& pos) {
				return dynamic_cast<ActorBlock*>(mActorBlock->get())->newBlockEntity(pos);
			}
		};

		static std::vector<BlockActorDeclaration*> mBlockActors;

		static void registerBlockActor(const std::string& nameId, BlockActorType type, WeakPtr<BlockLegacy>* actorBlock) {
			mBlockActors.push_back(new BlockActorDeclaration(nameId, type, actorBlock));
		}

		static std::shared_ptr<BlockActor> createBlockEntity(BlockActorType type, const BlockPos& pos) {
			for (BlockActorDeclaration* blockActor : mBlockActors)
				if (blockActor->mType == type)
					return blockActor->createBlockEntity(pos);
			return nullptr;
		}

		static void initBlockEntities() {
			for (BlockActorDeclaration* blockActor : mBlockActors)
				blockActor->setId();
		}
	};

	inline std::vector<BlockActorRegistry::BlockActorDeclaration*> BlockActorRegistry::mBlockActors{};
}