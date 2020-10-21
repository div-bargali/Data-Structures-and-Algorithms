/*****************************************************************
 * Circular Doubly Linked List
 *
 * Algorithm explanation:
 *  A double-linked circular list is a data structure made up of
 *  nodes. Each node has two pointers that point to the previous
 *  node and the next node in the circular list.
 *
 *****************************************************************/
#include <stdio.h>
#include <stdlib.h>

// structure of a node
typedef struct list
{
    double value;              ///< value stored in the node
    struct list *next, *prev;  ///< next/previous node pointing
} List;

// create list function
List *create(double value)
{
    List *new_list = (List *)malloc(sizeof(List));
    new_list->value = value;
    new_list->next = new_list;
    new_list->prev = new_list;
    return new_list;
}

// insert a value at the beginning of the list
List *insertBegin(List *list, double value)
{
    if (list == NULL)
        list = create(value);
    else
    {
        List *new_node = create(value);
        new_node->next = list;
        new_node->prev = list->prev;
        list->prev->next = new_node;
        list->prev = new_node;
        list = new_node;
    }
    return list;
}

// insert a value at the end of the list
List *insertEnd(List *list, double value)
{
    if (list == NULL)
        list = create(value);
    else
    {
        List *new_node = create(value);
        new_node->next = list;
        new_node->prev = list->prev;
        list->prev->next = new_node;
        list->prev = new_node;
    }
    return list;
}

// insert a value after other value in the list
List *insertAfter(List *list, double new_value, double value)
{
    if (list == NULL)
        list = create(value);
    else
    {
        List *new_node = create(new_value), *prior = list;

        while (prior->value != value && prior != list->prev)
            prior = prior->next;

        if (prior->value == value)
        {
            new_node->next = prior->next;
            new_node->prev = prior;
            prior->next->prev = new_node;
            prior->next = new_node;
        }
    }
    return list;
}

// insert a value by position in the list
List *insertPos(List *list, double value, int pos)
{
    if (list == NULL)
        list = create(value);

    // positive position case
    if (pos > 0)
    {
        // first position case
        if (pos == 1)
            return insertBegin(list, value);

        int it = 1;
        List *prior = list;

        while (it != pos && prior != list->prev)
        {
            prior = prior->next;
            it++;
        }

        // position in list range case
        if (it + 2 > pos)
        {
            // last position case
            if (prior == list->prev && it < pos)
                list = insertEnd(list, value);

            // general case
            else
            {
                List *new_node = create(value);
                new_node->next = prior;
                new_node->prev = prior->prev;
                prior->prev->next = new_node;
                prior->prev = new_node;
            }
        }
    }
    return list;
}

// delete a value at the beginning in the list
List *deleteBegin(List *list)
{
    if (list != NULL)
    {
        // one node case
        if(list == list->next)
            return NULL;
            
        // general case
        else
        {
            List *tmp = list;
            list = list->next;
            tmp->prev->next = list;
            list->prev = tmp->prev;
        }
    }
    return list;
}

// delete a  value at the end in the list
List *deleteEnd(List *list)
{
    if (list != NULL)
    {
        // one node case
        if (list == list->next)
            return NULL;
        
        // general case
        else
        {
            List *tmp = list->prev;
            tmp->prev->next = list;
            list->prev = tmp->prev;
        }     
    }
    return list;
}

// delete a value after other value in the list
List *deleteAfter(List *list, double value)
{
    if (list != NULL)
    {
        // one node case
        if (list == list->next)
            return NULL;
            
        // general case
        else
        {
            List *prior = list;
            while (prior->value != value && prior != list->prev)
                prior = prior->next;

            if (prior != list->prev && prior->value == value)
            {
                List *tmp = prior->next;
                tmp->next->prev = prior;
                prior->next = tmp->next;
            }
        }
    }
    return list;
}

// delete value by position in the list
List *deletePos(List *list, int pos)
{
    if (list != NULL)
    {
        // first position case
        if (pos == 1)
            return deleteBegin(list);

        List *prior = list;
        int it = 1;

        while (it != pos && prior != list->prev)
        {
            prior = prior->next;
            it++;
        }
        
        if(it + 1 > pos)
        {
            // last position case
            if (prior == list->prev && it == pos)
                list = deleteEnd(list);
    
            // general case
            else
            {
                List *tmp = prior->next;
                prior->prev->next = tmp;
                tmp->prev = prior->prev;
            }
        }
    }
    return list;
}

// search value function, `1` to exists and `0` to doesn't exist
int search(List *list, double value)
{
    if (list != NULL)
    {
        List *last_node = list->prev, *it = list;
        while (it != last_node)
        {
            if (it->value == value)
                return 1;
            it = it->next;
        }
        if (it->value == value)
            return 1;
        return 0;
    }
}

// print the circular doubly linked list
void display(List *list)
{
    if (list == NULL)
        printf("\n...-><-...");
    else
    {
        List *it = list;
        printf("\n...->");
        if (it == list->prev)
            printf("%f<-...", it->value);
        else
        {
            while (it != list->prev)
            {
                printf("%f<->", it->value);
                it = it->next;
            }
            printf("%f<->", it->value);
            printf("<-...");
        }
    }
}

// list length
int length(List *list)
{
    if(list == NULL)
        return 0;
    else
    {
        List *tmp = list;
        int length = 1;
        while (tmp != list->prev)
        {
            length++;
            tmp = tmp->next;
        }
        return length;
    }
}

// example function, it shows up how the code works.
void example()
{
    List *my_list = NULL;
    display(my_list);

    my_list = create(0);
    display(my_list);

    my_list = insertBegin(my_list, 3);
    display(my_list);

    my_list = insertAfter(my_list, 2, 3);
    display(my_list);

    my_list = insertEnd(my_list, 5);
    display(my_list);

    my_list = insertPos(my_list, 100, 3);
    display(my_list);

    my_list = deleteBegin(my_list);
    display(my_list);

    my_list = deleteEnd(my_list);
    display(my_list);

    my_list = deleteAfter(my_list, 100);
    display(my_list);

    my_list = deletePos(my_list, 4);
    display(my_list);

    my_list = deletePos(my_list, 1);
    display(my_list);

    printf("\n%d\t%d", search(my_list, 100), search(my_list, 0));
    
    my_list = deletePos(my_list, 1);
    display(my_list);

    printf("\n%d\t%d", search(my_list, 100), search(my_list, 0));
}

int main()
{
    example();
    return 0;
}
