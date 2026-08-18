class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v)
            : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;  // dummy head -> MRU side
    Node* tail;  // dummy tail -> LRU side

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    // Add node immediately after head
    // => node becomes MRU
    void addNodeToHead(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Remove node from its current position
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Remove LRU node
    Node* removeNodeFromTail() {
        Node* node = tail->prev;

        if (node == head)
            return nullptr;

        removeNode(node);
        return node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // This node was just used -> make it MRU
        removeNode(node);
        addNodeToHead(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            // Update value
            node->value = value;

            // Make it MRU
            removeNode(node);
            addNodeToHead(node);

            return;
        }

        // New key
        Node* node = new Node(key, value);

        mp[key] = node;
        addNodeToHead(node);

        // Capacity exceeded
        if (mp.size() > capacity) {
            Node* lru = removeNodeFromTail();

            mp.erase(lru->key);
            delete lru;
        }
    }
};