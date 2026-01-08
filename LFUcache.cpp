// Q84 https://leetcode.com/problems/lfu-cache/

struct Node{
    int key,value,cnt;
    Node *next;
    Node* prev;
    Node(int _key,int _value){
        key=_key;
        value=_value;
        cnt=1;
    }
};
struct List{
    int size;
    Node *head;
    Node* tail;
    List(){
        head =new Node(0,0);
        tail= new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(Node* newnode){
        Node*t=head->next;
        newnode->next=t;
        newnode->prev=head;
        head->next=newnode;
        t->prev=newnode;
        size++;
    }
    
    void removeNode(Node* delnode){
        Node* delprev=delnode->prev;
        Node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};

class LFUCache {
    map<int,Node*> keyNode;
    map<int,List*>freqListMap;
    int maxsize;
    int minfreq;
    int cursize;
public:
    LFUCache(int capacity) {
        maxsize=capacity;
        minfreq=0;
        cursize=0;
    }
    
    void updateFreqListMap(Node *node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minfreq&&freqListMap[node->cnt]->size==0){
            minfreq++;
        }
        
        List* nextHigherFreqList=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherFreqList=freqListMap[node->cnt+1];
        }
        node->cnt++;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt]=nextHigherFreqList;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            int val=node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsize==0)
            return;
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->value=value;
            updateFreqListMap(node);
        }
        else{
            if(cursize==maxsize){
                List *list=freqListMap[minfreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minfreq]->removeNode(list->tail->prev);
                cursize--;
            }
            cursize++;
            minfreq=1;
            List *listFreq=new List();
            if(freqListMap.find(minfreq)!=freqListMap.end()){
                listFreq=freqListMap[minfreq];
            }

            Node* node=new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minfreq]=listFreq;

            
        }
    }
};
    // int maxsize;
    // int minfreq;
    // int cursize;

    // int maxSizeCache;
    // int minFreq; 
    // int curSize; 
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
