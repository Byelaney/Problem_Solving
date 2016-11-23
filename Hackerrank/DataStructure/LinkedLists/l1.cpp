/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
    Node* prev = head;
    if (head != NULL) {
        Node* cur = prev->next;
        while (cur != NULL) {
            prev = cur;
            cur = cur->next;
        }
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if (head == NULL)
        head = node;
    else
        prev->next = node;
    return head;
}
