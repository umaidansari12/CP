#include <bits/stdc++.h>

using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    stack <int> s1;
    stack <int> s2;
    int q;
    cin >> q;
    while (q--)
    {
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1: int x;
            cin >> x;
            s1.push(x);
            break;
        case 2:
            if (s2.empty() && s1.empty())
            {
                cout << -1;
                break;
            }
            if (!s2.empty())
            {
                cout << s2.top() << " ";
                s2.pop();
            }
            else
            {
                while (!s1.empty())
                {
                    int t = s1.top();
                    s2.push(t);
                    s1.pop();
                }
                cout << s2.top() << " ";
                s2.pop();
            }
            break;
        case 3: if (!s2.empty())
            {
                cout << s2.top() << endl;
            }
            else
            {
                while (!s1.empty())
                {
                    int t = s1.top();
                    s2.push(t);
                    s1.pop();
                }
                cout << s2.top() << endl;
            }
            break;
        }
    }
    return 0;
}

/*void Push1(int *stack1,int item);
int Pop1(int *stack1);
void Display();
void Push2(int *stack2,int item);
int Pop2(int *stack2);
int isFull();
int isEmpty();
int top1=-1,top2=-1,stack1[100],stack2[100];*//*int item,t,i=0,ch,it;
    scanf("%d",&t);
        do{
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            scanf("%d",&item);
            if(!isFull())
                {
                    while(top2!=-1)
                {
                    it=Pop2(stack2);
                    Push1(stack1,it);
                }

                    Push1(stack1,item);
                }
            break;
            case 2:
            if(!isEmpty())
            {
                while(top1!=-1)
                {
                    item=Pop1(stack1);
                    Push2(stack2,item);
                }

            }
                if(top2!=-1)
                {
                    item=Pop2(stack2);
                }
                break;
            case 3:Display();
                    break;
        }

        }
        while(i<=t);
         return 0;
    }*/
//}
/*
void Push1(int *stack,int item)
{
        stack[++top1]=item;
}
void Push2(int *stack,int item)
{
        stack[++top2]=item;
}
int Pop1(int *stack)
{
        return stack[top1--];
}
int Pop2(int *stack)
{
        return stack[top2--];
}

void Display()
{
   if(top1!=-1)
   {
       int i=0;
        printf("\n%d\t\n",stack1[i]);
   }
    else if(top2!=-1)
    {
        int i=top2;
        printf("\n%d\t",stack2[top2]);
    }

}

int isFull()
{
    return(top1==99||top2==99);
}
int isEmpty()
{
    return(top1==-1&&top2==-1);
}
*/