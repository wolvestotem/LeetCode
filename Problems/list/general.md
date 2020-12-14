## list

list兼具迭代性和递归性，应该观察题目特点，使用合适方法
list题目很常使用几种经典方法拼凑出一道复杂的题目，应该对list经典方法烂熟于心
list经常使用dummy node，使得之后的步骤具有步进特点，同时记录初始点返回

## Reverse Linked list

### Iteration

```C++
ListNode* reverse(ListNode* head) {
    if (!head) return nullptr;
    ListNode* curr = head;
    ListNode* pre = nullptr;
    ListNode* fu=head;
    while (curr!=nullptr) {
        fu = curr->next;
        curr->next = pre;
        pre = curr;
        curr = fu;
    }
    return(pre);
}
```

### Reverse K node [head, b)
```C++
ListNode* reverseK(ListNode* head, ListNode* b) {
    if (!head) return nullptr;
    ListNode* curr = head;
    ListNode* pre = b;
    ListNode* fu=head;
    while (curr!=b) {
        fu = curr->next;
        curr->next = pre;
        pre = curr;
        curr = fu;
    }
    return(pre);
}
```

### Recursion

```C++
ListNode* reverse(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* res = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return res;
}
```

### Reverse K node 
```C++
TreeNode* successor=nullptr;
ListNode* reverseK(ListNode* head, int K) {
    if(!head) return nullptr;
    if(K==1){
        successor = head->next;
        return head;
    }
    ListNode* res = reverseK(head->next, K-1);
    head->next->next = head;
    head->next = successor;
    return res;
}
```

## Linked list取中点
```C++
void mid(ListNode* head){
    if(!head || !head->next)
        return head;
    ListNode *sl(head),*fa(head->next);

    while(fa && fa->next){
        sl = sl->next;
        fa = fa->next->next;
    }
}
```
