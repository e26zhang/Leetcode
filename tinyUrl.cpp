#include <map>
#include <string>
#include <sstream>

class Solution {
	const std::string tinyUrl = "http://tinyurl.com/";
	std::map<int, std::string> m;
public:

	// Encodes a URL to a shortened URL.
	std::string encode(std::string longUrl) {
		for(int i = 0; i < m.size(); ++i) {
			if(m[i] == longUrl) {
				return std::to_string(i);
			}
		}
		int size = m.size();
		m[size] = longUrl;

		return tinyUrl + std::to_string(size);
	}

	// Decodes a shortened URL to its original URL.
	std::string decode(std::string shortUrl) {
		shortUrl.erase(0, 19);
		std::istringstream iss{shortUrl};
		int c;
		iss >> c;
		return m[c];
	}
};