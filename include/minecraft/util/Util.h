#pragma once

#include <string>

namespace Util {
	std::string toLower(const std::string&);
	std::string toUpper(const std::string&);
	uint64_t u64FromString(const std::string&);

	class HashString {
		std::string mText;
		uint64_t mHash;

	public:
		HashString() = default;
		HashString(const std::string& rha) {
			mText = rha;
			mHash = u64FromString(toLower(rha));
		}
		HashString& operator=(const std::string& rha) {
			mText = rha;
			mHash = u64FromString(toLower(rha));
			return *this;
		}
		HashString& operator=(const HashString& rha) {
			mText = rha.mText;
			mHash = rha.mHash;
			return *this;
		}
		bool operator==(const HashString& rha) const {
			return mHash == rha.mHash;
		}
		bool operator!=(const HashString& rha) const {
			return mHash != rha.mHash;
		}
		bool operator<(const HashString& rha) const {
			return mHash < rha.mHash;
		}
		const std::string& getString() const { return mText; }
	};
}