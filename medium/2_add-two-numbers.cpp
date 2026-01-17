#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = nullptr;
    ListNode* tail = nullptr;

    int s = 0;
    while (l1 != nullptr || l2 != nullptr || s != 0) {
        if (l1 != nullptr) {
            s += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            s += l2->val;
            l2 = l2->next;
        }

        ListNode* n = new ListNode(s % 10);
        s = s / 10;

        if (res == nullptr) {
            res = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    return res;
}

int main() {
    int n1, n2;

    cin >> n1;
    ListNode* l1 = nullptr;

    ListNode* tail1 = nullptr;
    for (int i = 0; i < n1; i++) {
        int v;
        cin >> v;
        ListNode* n = new ListNode(v);
        if (l1 == nullptr) {
            l1 = n;
            tail1 = n;
        } else {
            tail1->next = n;
            tail1 = n;
        }
    }

    cin >> n2;
    ListNode* l2 = nullptr;
    ListNode* tail2 = nullptr;
    for (int i = 0; i < n2; i++) {
        int v;
        cin >> v;
        ListNode* n = new ListNode(v);
        if (l2 == nullptr) {
            l2 = n;
            tail2 = n;
        } else {
            tail2->next = n;
            tail2 = n;
        }
    }

    ListNode* res = addTwoNumbers(l1, l2);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}