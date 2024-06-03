struct Node {
    string data;
    Node* next;
    Node* back;
    
    Node(string val) : data(val), next(nullptr), back(nullptr) {}
};

class BrowserHistory {
    Node* currentpage;
    
public:
    BrowserHistory(string homepage) {
        currentpage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        currentpage->next = newNode;
        newNode->back = currentpage;
        currentpage = newNode;
    }
    
    string back(int steps) {
        while (steps > 0 && currentpage->back != nullptr) {
            currentpage = currentpage->back;
            steps--;
        }
        return currentpage->data;
    }
    
    string forward(int steps) {
        while (steps > 0 && currentpage->next != nullptr) {
            currentpage = currentpage->next;
            steps--;
        }
        return currentpage->data;
    }
};


