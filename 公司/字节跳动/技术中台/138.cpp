class Solution {
public:
    unordered_map<Node*,Node*> dic;
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        if(dic.find(head)!=dic.end())
            return dic[head];
        Node* newNode = new Node(head->val);
        visited[head] = newNode;

        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        return newNode;
    }
};