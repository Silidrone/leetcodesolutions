#include <unordered_map>

class min_heap {
private:
    int *_heap;
    int _end;
    int _capacity;

    bool valid(int i) {
        return i >= 0 && i < _end;
    }

    int left(int index) {
        return 2 * index + 1;
    }

    int right(int index) {
        return 2 * index + 2;
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    void swap(int i, int j) {
        int tmp = _heap[i];
        _heap[i] = _heap[j];
        _heap[j] = tmp;
    }
public:
    min_heap() {
        _capacity = 10;
        _heap = new int[_capacity];
        _end = 0;
    }

    ~min_heap() {
        delete[] _heap;
    }

    void insert(int n) {
        if(_end == _capacity) {
            int *tmp = _heap;
            _heap = new int[_capacity * 2];

            for(int i = 0; i < _capacity; i++) {
                _heap[i] = tmp[i];
            }

            _capacity *= 2;
            delete[] tmp;
        }

        _heap[_end++] = n;
        swim();
    }

    int poll() {
        if(empty()) throw std::logic_error("The heap is empty, you cannot poll anything!");

        int min = _heap[0];
        swap(0, --_end);
        sink();
        return min;
    }

    void swim() {
        int i = _end - 1;
        while(valid(parent(i)) && _heap[i] < _heap[parent(i)]) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    void sink() {
        int i = 0;

        while(valid(left(i))) {
            int min_child_i = left(i);
            if(valid(right(i)) && _heap[right(i)] < _heap[left(i)]) {
                min_child_i = right(i);
            }

            if(_heap[min_child_i] < _heap[i]) {
                swap(min_child_i, i);
                i = min_child_i;
            } else {
                break;
            }
        }
    }

    bool empty() {
        return _end == 0;
    }
};

class Solution {
public:
    int power(int b, int e) {
        if(e == 0) return 1;
        return b * power(b, e - 1);
    }

    int findLeastNumOfUniqueInts(std::vector<int> arr, int k) {
        if(arr.empty() || arr.size() > power(10, 5) || k < 0 || k > arr.size()) return -1;
        if(k == arr.size()) return 0;

        std::unordered_map<int, int> occurrences;

        for(int &n : arr) {
            occurrences[n]++;
        }

        min_heap mh;
        for(auto &it : occurrences) {
            mh.insert(it.second);
        }

        int removed = 0;
        while(!mh.empty()) {
            int min_occurrence = mh.poll();
            if(min_occurrence > k) break;

            k -= min_occurrence;
            removed++;
        }

        return occurrences.size() - removed;
    }
};