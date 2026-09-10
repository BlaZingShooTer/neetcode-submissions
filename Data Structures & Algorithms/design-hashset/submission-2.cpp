class MyHashSet {
    vector<int> data;
public:
    MyHashSet() {
        data.resize(1e7,0);
    }
    
    void add(int key) {
        data[key]= 1;
    }
    
    void remove(int key) {
        data[key] = 0;
    }
    
    bool contains(int key) {
        return data[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */