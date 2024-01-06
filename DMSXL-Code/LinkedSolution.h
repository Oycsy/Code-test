#pragma once
#include <iostream>
#include <istream>
#include<algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class LinkedSolution {
public:
    /**
     * 删除链表中等于给定值 val 的所有节点.
     * 
     * \param head
     * \param val
     * \return 
     */
	ListNode* removeElements(ListNode* head, int val) {
        ListNode* dpHead = new ListNode(0,head);
        ListNode* cur = dpHead;
        while (cur->next) {
            if (cur->next->val != val) {
                cur = cur->next;
            }
            else {
                cur->next = cur->next->next;
            }            
        }
        return dpHead->next;
	}
    /**
     * 反转链表.
     * 
     * \param head
     * \return 
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = new ListNode(0);
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    /**
     * 链表A和链表B是否有相交.
     * 
     * \param headA
     * \param headB
     * \return 
     */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;

        int sizeA = 0;
        while (cur1) {
            cur1 = cur1->next;
            sizeA++;
        }
        int sizeB = 0;
        while (cur2) {
            cur2 = cur2->next;
            sizeB++;
        }
        cur1 = headA;
        cur2 = headB;

        if (sizeA < sizeB) {
            swap(sizeA, sizeB);
            swap(cur1, cur2);
        }
        int dif = sizeA - sizeB;
        while ((dif)--) {
            cur1 = cur1->next;
        }

        while (sizeB--) {
            if (cur1 == cur2) return cur1;

            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return nullptr;
    }

    /**
     * 删除倒数第n个节点.
     * 
     * \param head
     * \param n
     * \return 
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* tmp = head;
        while (tmp) {
            size++;
            tmp = tmp->next;
        }

        int dif = size - n;

        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        for (int i = 1; i < size - n + 1; ++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
    /**
     * 环形链表.
     * 
     * \param head
     * \return 
     */
    ListNode* detectCycle(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = head;
        while (pre && cur && pre->next) {
            pre = pre->next->next;
            cur = cur->next;
            if (pre == cur) {
                ListNode* index1 = head;
                ListNode* index2 = pre;
                while (index1 && index2) {
                    if (index1 == index2) return index2;
                    index1 = index1->next;
                    index2 = index2->next;
                }
            }
        }        
        return nullptr;
    }
    /**
     * 反转某个区间内的链表.
     * 
     * \param head
     * \param left
     * \param right
     * \return 
     */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dp = new ListNode(0, head);
        ListNode* pre = dp;
        ListNode* cur = head;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
            cur = cur->next;
        }
        for (int i = 0; i < right - left; i++) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dp->next;
    }
    /**
     * 回文链表.
     * 
     * \param head
     * \return 
     */
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        if (head->next->next == nullptr) return head->val == head->next->val;
             
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* leftHead = head;
        ListNode* rightHead = reverseList(slow->next);
        while (rightHead) {
            if (rightHead->val != leftHead->val) return false;
            rightHead = rightHead->next;
            leftHead = leftHead->next;
        }
        return true;
    }

    /**
     * 链表的中间节点.
     * 
     * \param head
     * \return 
     */
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = new ListNode(0, head);
        ListNode* fast = new ListNode(0, head);
        int count = 0;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            count++;
        }
        if (fast == nullptr) return slow;
        else return slow->next;
    }
    /**
     * 分裂链表.
     * 
     * \param head
     * \param x
     * \return 
     */
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* bigHead = big;
        ListNode* cur = head;
        while (cur) {
            if (cur->val < x) {
                small->next = cur;
                small = cur;
            }
            else {
                big->next = cur;
                big = cur;
            }
            cur = cur->next;
        }
        if (bigHead->next != nullptr) {
            small->next = bigHead->next;
            big->next = nullptr;
        }      
        return smallHead->next;
    }
    /**
     * 旋转链表.
     * 
     * \param head
     * \param k
     * \return 
     */
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        //统计链表数量
        int size = 0;
        ListNode* cur = head;
        while (cur) {
            size++;
            cur = cur->next;
        }
        //计算要要拿取的数量
        int realK = k % size;
        if (realK == 0) return head;
        //指向要前半部分的尾结点
        ListNode* LeftTrail = new ListNode(0, head);
        for (int i = 0; i < size - realK - 1; i++) {
            LeftTrail = LeftTrail->next;
        }        
        ListNode* rightHead = LeftTrail->next;
        LeftTrail->next = nullptr;
        //翻转完的尾节点指向head头结点
        ListNode* tmp = new ListNode(0, rightHead);
        while (tmp->next) tmp = tmp->next;
        tmp->next = head;
        return rightHead;
    }
    /**
     * 重排链表.
     * 
     * \param head
     */
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* rightHead = reverseList(slow->next);
        slow->next = nullptr;

        ListNode* l1 = head;
        ListNode* l2 = rightHead;

        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
    /**
     * 删除排序链表中的重复元素(保留重复数据）.
     * 
     * \param head
     * \return 
     */
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> res;
        ListNode* dp = new ListNode(0, head);
        ListNode* cur = dp;
        while (cur->next) {
            if (res.count(cur->next->val) <= 0)
            {
                res.insert(cur->next->val);
                cur = cur->next;
            }
            else cur->next = cur->next->next;            
        }
        return dp->next;
    }
    /**
     * 删除排序链表中的重复元素(不保留重复数据）.
     *
     * \param head
     * \return
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dp = new ListNode(0, head);
        ListNode* cur = dp;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int value = cur->next->val;
                while (cur->next && cur->next->val == value) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        return dp->next;
    }
    /**
     * 合并两个有序链表.
     * 
     * \param list1
     * \param list2
     * \return 
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur = new ListNode(0);
        ListNode* dp = cur;
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                dp->next = head1;
                head1 = head1->next;
            }
            else {
                dp->next = head2;
                head2 = head2->next;
            }
            dp = dp->next;
        }
        if (head1) {
            dp->next = head1;
        }
        if (head2) {
            dp->next = head2;
        }
        return cur->next;
    }

    /**
     * 复制随机链表.
     * 
     * \param head
     * \return 
     */
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
    /**
     * 每k组旋转一次.
     * 
     * \param head
     * \param k
     * \return 
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dp = new ListNode(0, head);
        ListNode* pre = dp;
        ListNode* end = dp;
        while (end->next) {
            for (int i = 0; i < k && end; i++) {
                end = end->next;
            }

            if (end == nullptr) break;
            ListNode* next = end->next;
            end->next = nullptr;//断开
            ListNode* start = pre->next;
            pre->next = nullptr;
            pre->next = reverseList(start);
            start->next = next;
            pre = start;
            end = start;
        }
        return dp->next;
    }
};
