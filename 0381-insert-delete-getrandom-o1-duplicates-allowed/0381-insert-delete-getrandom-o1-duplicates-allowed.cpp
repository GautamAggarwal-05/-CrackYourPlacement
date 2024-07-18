#include <unordered_map>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

class RandomizedCollection {
public:
    std::unordered_map<int, int> mp;
    std::vector<int> elements; // Vector to store elements according to their frequency
    
    RandomizedCollection() {
        srand(time(nullptr)); // Initialize random seed
    }
    
    bool insert(int val) {
        if (mp[val] > 0) {
            mp[val]++;
            elements.push_back(val); // Add the element to the vector
            return false;
        } else {
            mp[val]++;
            elements.push_back(val); // Add the element to the vector
            return true;
        }
    }
    
    bool remove(int val) {
        if (mp[val] > 0) {
            mp[val]--;
            // Remove one occurrence of the element from the vector
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
