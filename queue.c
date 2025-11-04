#include <stdio.h>
#define s 3
int cq[s],f=-1,r=-1;
int cenqueue ()
{
    int a;
    printf("Enter number:");
    scanf("%d",&a);
    if((r+1)%s==f){
        printf("Overflow\n");
        return (0);
    }
    else if(r==-1 &&f==-1)
    {
        r=f=0;
    }
    else{
        r=(r+1)%s;
    }
    cq[r]=a;
}
int cdequeue()
{
    int x;
    if(r==-1)
    {
        printf("Underflow\n");
        return (0);
    }
    else if(r==f)
        {x=cq[r];
            r=f=-1;
        }
    else {
        x=cq[f++];
    }
    return(x);
}
void cdisplay(){
    for(int i=f;i!=r;i=(i+1)%s){
        printf("%d\t",cq[i]);
    }printf("%d\n",cq[r]);
}
int main()
{
    int c;
    while(1){
        printf("1:Insert\n2:Delete\n3:Display\n4:Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :

                cenqueue();
                break;
            case 2 :
                cdequeue();
                break;
            case 3:
                cdisplay();
                break;
            case 4:
                return (0);

        }
    }
}

