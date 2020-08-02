struct Node{
    Node* pre;
    Node* next;
    int key,value;
    Node():key(0),value(0),pre(nullptr),next(nullptr){}
    Node(int _key ,int _value):key(_key),value(_value),pre(nullptr),next(nullptr){}
};

class DoubleDirctList{
public:
    DoubleDirctList(){
        m_head = new Node;
        m_tail = new Node;
        m_head->next = m_tail;
        m_tail->pre = m_head;
    }
    void addFirst(Node* pNode){
        pNode->pre = m_head;
        pNode->next = m_head->next;
        m_head->next->pre = pNode;
        m_head->next = pNode;
    }
    void removeOne(Node* pNode){
        pNode->pre->next = pNode->next;
        pNode->next->pre = pNode->pre;
    }
    Node* removeLast(){
        Node* tmp = m_tail->pre;
        removeOne(tmp);
        return tmp;
    }
private:
    Node* m_head;
    Node* m_tail;
};

class LRUCache {
public:
    LRUCache(int _capacity):capacity(_capacity), size(0) {
    }
    int get(int key) {
        if(!m_hashMap.count(key))
            return -1;
        Node* pNode = m_hashMap[key];
        doubList.removeOne(pNode);
        doubList.addFirst(pNode);
        return pNode->value;
    }
    
    void put(int key, int value) {
        if(m_hashMap.count(key)){
            Node* tmp = m_hashMap[key];
            tmp->value = value;
            doubList.removeOne(tmp);
            doubList.addFirst(tmp);
        }
        else{
            Node* pNode = new Node(key,value);
            doubList.addFirst(pNode);
            m_hashMap.insert(make_pair(key, pNode));
            size++;
            if(size > capacity){
                Node* tmp = doubList.removeLast();
                m_hashMap.erase(tmp->key);
                delete tmp;
            }
        }
    }
private:
    int size;
    int capacity;
    DoubleDirctList doubList;
    unordered_map<int,Node*> m_hashMap;
};