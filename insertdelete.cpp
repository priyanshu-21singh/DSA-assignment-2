class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> map;

    RandomizedSet() {
        v.clear();
        map.clear();
    }

    bool insert(int val) {
        if (map.find(val) != map.end())  // agar  element  available hai , return false
            return false;
        map[val] = v.size();
        v.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (map.find(val) == map.end())  // agar elemrnt hai hi nahi toh, return false
            return false;
        
        // yaha se index find karlijiye
        int i = map[val];
        
        // phir swap karlo delete karne ke liye last meh o(1) hojayega
        int lastElement = v.back();
        v[i] = lastElement;
        map[lastElement] = i;
        
        // Remove
        v.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom() {
        int i = rand() % v.size();
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */