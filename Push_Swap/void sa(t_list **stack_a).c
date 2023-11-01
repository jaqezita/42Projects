void sa(t_list **stack_a)
{
    if (*stack_a && (*stack_a)->next)
    {
        int temp = *(int *)((*stack_a)->content);
        (*stack_a)->content = (*stack_a)->next->content;
        (*stack_a)->next->content = (void *)temp;
    }
}

void sb(t_list **stack_b)
{
    // Similar to sa, but for stack_b
}

void ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void pa(t_list **stack_a, t_list **stack_b)
{
    if (*stack_b)
    {
        t_list *temp = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next = *stack_a;
        *stack_a = temp;
    }
}

void pb(t_list **stack_a, t_list **stack_b)
{
    // Similar to pa, but for stack_a and stack_b reversed
}

void ra(t_list **stack_a)
{
    if (*stack_a && (*stack_a)->next)
    {
        t_list *temp = *stack_a;
        while (temp->next)
            temp = temp->next;
        temp->next = *stack_a;
        *stack_a = (*stack_a)->next;
        temp->next->next = NULL;
    }
}

void rb(t_list **stack_b)
{
    // Similar to ra, but for stack_b
}

void rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(t_list **stack_a)
{
    // Similar to ra, but in reverse order
}

void rrb(t_list **stack_b)
{
    // Similar to rra, but for stack_b
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}