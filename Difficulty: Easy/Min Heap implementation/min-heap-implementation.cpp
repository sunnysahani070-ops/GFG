class minHeap {
private:
    vector<int> arr;
    int s;

public:
    minHeap() {
        arr.push_back(-1);   // dummy element for 1-based indexing
        s = 0;
    }

    void push(int x) {
        arr.push_back(x);
        s++;

        int index = s;

        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void pop() {
        if (s == 0)
            return;

        arr[1] = arr[s];
        arr.pop_back();
        s--;

        int i = 1;

        while (true) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int smallest = i;

            if (leftIndex <= s && arr[leftIndex] < arr[smallest])
                smallest = leftIndex;

            if (rightIndex <= s && arr[rightIndex] < arr[smallest])
                smallest = rightIndex;

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

    int peek() {
        if (s == 0)
            return -1;
        return arr[1];
    }

    int size() {
        return s;
    }

    bool empty() {
        return s == 0;
    }
};