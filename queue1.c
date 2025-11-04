#include <stdio.h>
#define s 3
int q[s],f=-1,r=-1;
int enqueue ()
{   int x;
    printf("Enter number:");
    scanf("%d",&x);
    if(r==s-1){
        printf("Overflow\n");
        return (0);
    }
    else if(r==-1 &&f==-1)
    {
        r=f=0;
    }
    else{
        r=r+1;
    }
    q[r]=x;
}
int dequeue()
{
    int x;
    if(r==-1)
    {
        printf("Underflow\n");
        return (0);
    }
    else if(r==f)
        {x=q[r];
            r=f=-1;
        }
    else {
        x=q[f++];
    }
    return(x);
}
void display(){

    for(int i=f;i<=r;i++){
        if(f==-1 &&r==-1)
       {printf("kuch nhi hai bhai aage badho");
       }else{
        printf("%d\t",q[i]);
    }printf("\n");
}}
int main()
{
    int c;
    while(1){
    printf("1:Insert\n2:Delete\n3:Display\n4:Exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 :
            enqueue();
            break;
        case 2 :
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return (0);

    }
    }
}
