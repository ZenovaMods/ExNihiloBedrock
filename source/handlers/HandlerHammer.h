#pragma once

class Block;
class Player;
class BlockPos;

class HandlerHammer {
public:
	static bool hammer(const Block&, const BlockPos&, Player&);
};
