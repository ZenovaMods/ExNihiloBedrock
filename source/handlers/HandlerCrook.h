#pragma once

class Block;
class Player;
class BlockPos;

class HandlerCrook {
public:
	static bool crook(const Block&, const BlockPos&, Player&);
};
