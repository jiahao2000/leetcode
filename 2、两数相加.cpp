
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0),*cur = dummy;
        int sum = 0; //记录每一位置相加的和
        while(l1||l2||sum){ //sum值如果不为零的话，说明需要新增加一个节点来存储剩余的sum值，因此需要在条件中加入最后一个判断
            if(l1) sum+=l1->val,l1 = l1->next;
            if(l2) sum+=l2->val,l2 = l2->next;
            cur->next = new ListNode(sum % 10); //创建一个新的节点，其中存储的值为sum值%10
            cur = cur->next;
            sum/=10;
        }
        return dummy->next; //返回虚拟头节点的下一个节点
    }
};