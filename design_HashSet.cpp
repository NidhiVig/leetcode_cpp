class MyHashSet {
    unordered_set<int> s;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        s.erase(key);
    }
    
    bool contains(int key) {
        if(s.find(key)==s.end())return false;
        return true;
    }
};
