#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_list
{
    char c;
    struct s_list *next;
}list;

int is_empty(list *stack)
{
    if (!stack)
        return 1;
    return 0;
}

list	*pop(list **stack)
{
	list *top;

	top = NULL;
	if (!is_empty(*stack))
	{
		top = *stack;
		*stack = (*stack)->next;
	}
	return (top);
}

void lstadd(list **stack, list *new_item)
{
    if (!*stack)
        *stack = new_item;
    else
    {
        new_item->next = *stack;
        *stack = new_item;
    }
}

void	push(list **stack, char new)
{
	list *new_item = malloc(sizeof(list));
    new_item->c = new;
    new_item->next = NULL;
    lstadd(stack, new_item);
}

bool is_balanced(char expression[])
{
    list *stack = NULL;
    while (*expression)
    {
        char cur = *expression++;
        if (cur == '(' || cur == '{' || cur == '[')
            push(&stack, cur);
        else
        {
            list *tmp = pop(&stack);
            if (!tmp)
                return false;
            if (cur == ')' && tmp->c == '(')
                continue;
            else if (cur == ']' && tmp->c == '[')
                continue;
            else if (cur == '}' && tmp->c == '{')
                continue;
            else
                return false;
        }
    }
    if (!is_empty(stack))
        return false;
    return true;
}

int main()
    {
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++)
    {
        char* expression = (char *)malloc(512000 * sizeof(char));
        scanf("%s",expression);
         bool answer = is_balanced(expression);
         if(answer)
          printf("YES\n");
         else
          printf("NO\n");
    }
    return 0;
}