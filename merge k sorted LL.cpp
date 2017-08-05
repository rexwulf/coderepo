/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* L1, ListNode *L2)
    {
        if(!L1)
            return L2;
        
        if(!L2)
            return L1;
        
        if(L1->val < L2->val)
        {
            L1->next= merge( L1->next , L2);
            return L1;
        }
        
        else
        {
            L2->next= merge( L1 , L2->next);
            return L2;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& A) {
        
        if(!A.size())
            return NULL;
        
        while(A.size()>1)
        {
            A.push_back( merge(A[0],A[1]) );
            A.erase(A.begin());
            A.erase(A.begin());
        }
        
        return A[0];
    }
};