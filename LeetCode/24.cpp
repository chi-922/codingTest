// Swap Nodes in Pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;       // 첫 번째 노드
            ListNode* b = prev->next->next; // 두 번째 노드

            // 링크 재배선
            // 앞에 노드 도착지가 뒤의 노드 도착지 바라보기
            a->next = b->next;
            // 뒤의 노드 도착지가 앞 노드 바라보게
            b->next = a;
            // 기준점도 swap된 노드 바라보게
            prev->next = b;

            // 다음 쌍으로 이동
            prev = a;  // 이젠 a가 뒤 노드 됐고, a가 기준점으로 앞, 앞앞노드 바꾸면 됨
        }

        return dummy.next;
    }
};


// 재귀방식

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* a = head;
        ListNode* b = head->next;

        a->next = swapPairs(b->next);
        b->next = a;

        return b;
    }
};
