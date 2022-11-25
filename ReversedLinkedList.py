# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        while curr: # this will loop until curr is null 
            nxt = curr.next #this will be set to the current node to the right which will be used later
            curr.next = prev # this will set the next node to what ever the the prev was (starts as Null)
            prev = curr #this set prev one to the right of it
            curr = nxt #sets curr one to its right bc of the temp varaibel
        return prev #prev will end up being the new head which teh problem wants
