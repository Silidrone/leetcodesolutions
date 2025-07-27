class Allocator {
public:
    std::vector<int> memory;

    Allocator(int n) {
        memory.resize(n, 0);
    }

    int firstFreeSpot(int size) {
        for(int i = 0, free_idx = 0, free_count = 0; i < memory.size(); i++) {
            if(!memory[i]) {
                free_count++;
            } else {
                free_idx = i + 1;
                free_count = 0;
            }

            if(free_count == size) return free_idx;
        }

        return -1;
    }
    
    int allocate(int size, int mID) {
        int idx = firstFreeSpot(size);

        if(idx != -1) {
            for(int i = idx; i < idx + size; i++) {
                memory[i] = mID;
            }
        }

        return idx;
    }
    
    int freeMemory(int mID) {
        int freed = 0;
        for(int i = 0; i < memory.size(); i++) {
            if(memory[i] == mID) {
                memory[i] = 0;
                freed++;
            }
        }

        return freed;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */