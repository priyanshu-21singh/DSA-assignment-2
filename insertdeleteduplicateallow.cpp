class RandomizedCollection {
public:
    std::unordered_map<int, std::set<int>> m;
    std::vector<int> v;

    RandomizedCollection() { }
    
    bool insert(int val) {
        v.push_back(val);
        m[val].insert(v.size() - 1);
        return m[val].size() == 1;
    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if (it != m.end()) {
            // Get the index of the value to remove
            auto pos = *it->second.begin();
            it->second.erase(it->second.begin());

            if (pos != v.size() - 1) {  // if not removing the last element
                // Move the last element to the position of the element to remove
                int lastElement = v.back();
                v[pos] = lastElement;
                // Update the indices in the map
                m[lastElement].erase(v.size() - 1);
                m[lastElement].insert(pos);
            }
            v.pop_back();  // remove the last element

            if (it->second.empty()) {
                m.erase(it);  // remove the entry from the map if no indices left
            }
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int i = rand() % v.size();
        return v[i];
    }
};
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */