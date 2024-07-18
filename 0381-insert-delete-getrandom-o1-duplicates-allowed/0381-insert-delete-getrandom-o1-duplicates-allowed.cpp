#include <unordered_map>
#include <vector>
#include <cstdlib> 
#include <ctime>   

class RandomizedCollection {
public:
    std::unordered_map<int, int> mp;
    std::vector<int> elements; 
    
    RandomizedCollection() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if (mp[val] > 0) {
            mp[val]++;
            elements.push_back(val); 
            return false;
        } else {
            mp[val]++;
            elements.push_back(val); 
            return true;
        }
    }
    
    bool remove(int val) {
        if (mp[val] > 0) {
            mp[val]--;
          
            for (auto it = elements.begin(); it != elements.end(); ++it) {
                if (*it == val) {
                    elements.erase(it);
                    break;
                }
            }
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        int randomIndex = rand() % elements.size();
        return elements[randomIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
