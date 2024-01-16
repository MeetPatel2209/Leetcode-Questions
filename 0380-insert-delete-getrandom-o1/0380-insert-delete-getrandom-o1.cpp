class RandomizedSet {
public:
    unordered_set<int> ele;
    int size;
    RandomizedSet() {
        size=0;
    }
    
    bool insert(int val) {
        if(ele.find(val) == ele.end()) {
            ele.insert(val);
            return true;
        }
        else {
            return false;
        }
    }
    
    bool remove(int val) {
        if(ele.find(val) != ele.end()) {
            ele.erase(val);
            return true;
        }
        else {
            return false;
        }
    }
    
    int getRandom() {
        int n = ele.size();
        int ind = (rand()%n);
        auto it = ele.begin();
        while(ind--) {
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */