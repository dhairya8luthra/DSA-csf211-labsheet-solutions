void display(struct node *head)
{
    struct node *start = head;
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->next;
    }
}