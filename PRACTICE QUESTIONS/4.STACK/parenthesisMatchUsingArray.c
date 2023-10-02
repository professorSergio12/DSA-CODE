#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
    
};

int empty(struct stack* ptr )
{
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;
}
int full(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack* ptr,int value)
{
    if(full(ptr))
    {
        printf("The stack is overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}
 
char pop(struct stack* ptr)
{
    if(empty(ptr))
    {
        printf("The stack is under flow\n");
    }
    else
    {
        char value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
} 

int parenthesis_match(char* epx)
{
    struct stack* sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    int i;
    for(i=0;epx[i]!='\0';i++)
    {
        if(epx[i]=='(')
        {
            push(sp,'(');
        }
        else if(epx[i]==')')
        {
            if(empty(sp))
            {
                return 0;
        }
        pop(sp);
            
        }
    }
    if(empty(sp))
    {
        return 1;
        
    }
        return 0;
}
 
int main()
{
    char * exp = "((8)($$9))";
    // Check if stack is empty
    if(parenthesis_match(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}

