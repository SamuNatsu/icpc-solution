template<class T>
struct LoopQueue {
    size_t maxSize; // Max size
    T *queue;       // Queue pointer
    size_t h, t;    // Head pointer & tail pointer

    LoopQueue(size_t mx): maxSize(mx), queue(new T[mx + 5]), h(0), t(0) {}    // Constructor
    ~LoopQueue() {  // Destructor
        delete[] queue;
    }
    bool empty() const {
        return h == t;
    }
    void push(const T& tmp) {    // Push
        queue[++h >= maxSize ? (h = 0) : h] = tmp;
    }
    T pop() {   // Pop
       return queue[++t >= maxSize ? (t = 0) : t];
    }
};
