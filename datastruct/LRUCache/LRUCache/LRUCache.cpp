#include <iostream>
#include <list>
#include <unordered_map>

template<typename K, typename V>
class LRUCache
{
public:
	explicit LRUCache(size_t capacity) :cap_(capacity) {}
	bool get(const K& key, V& out) {
		auto it = index_.find(key);
		if (it == index_.end()) {
			return false;
		}
		item_.splice(item_.begin(), item_, it->second);
		out = it->second->second;
		return true;
	}

	void put(const K& key, V value) {
		auto it = index_.find(key);
		if (it != index_.end()) {
			it->second->second = std::move(value);
			item_.splice(item_.begin(), item_, it->second);
			return;
		}
		if (item_.size() == cap_) {
			auto& old = item_.back();
			index_.erase(old.first);
			item_.pop_back();
		}
		item_.emplace_front(key, std::move(value));
		index_[item_.front().first] = item_.begin();
	}

	void debug_print() {
		std::cout << "MRU -> LRU";
		for (auto it = item_.begin(); it != item_.end(); ++it) {
			std::cout << "(" << it->first << ":" << it->second << ")";
		}
		std::cout << "\n";
	}
private:
	size_t cap_;
	std::list<std::pair<K, V>> item_;
	std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> index_;
};

int main()
{
	LRUCache<int, std::string> cache(3);
	cache.put(1, "A");
	cache.put(2, "B");
	cache.put(3, "C");
	cache.debug_print();

	std::string out;
	if (cache.get(2, out)) {
		std::cout << "get(2): " << out << std::endl;
	}
	cache.debug_print();

	cache.put(4, "D");
	cache.debug_print();

	return 0;
}
