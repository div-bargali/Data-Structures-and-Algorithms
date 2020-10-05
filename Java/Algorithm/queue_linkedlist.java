import java.util.*;
class node
{
    int data;
    node link;
    public node()
    {
        data=0;
        link=null;
    }
    public node(int d,node p)
    {
        data=d;
        link=p;
    }
    public int getdata(){return data;}
    public node getlink(){return link;}
    public void setlink(node n) {link=n;}
}
class queue
{
    node start;
    node end;
    int size;
    queue()
    {
        start=null;
        end = null;
        size=0;
    }

    void enqueue(int x,int s)
    {
        if(size==s)
        System.out.println("queue full");
        else
        {
          node nptr=new node(x,null);
          size++;
         if(start==null)
         {
             start=nptr;
             end= nptr;
         }
         else
         {
             end.setlink(nptr);
             end=nptr;
         }
        }
    }
    void dequeue()
    {
        if(start==null)
        System.out.println("queue empty");
        else
        {
            start = start.getlink();
            size--;
        }
    }
    void peek()
    {
        if(start==null)
            System.out.println("queue empty");
        else
        {
               node ptr = start;
               System.out.println(ptr.getdata()+"is in the front"); 

            }
    }
    void display()
    {
        node ptr=start;
        if(size==0)
        System.out.println("queue empty");
        else{
            for(int i=0;i<size;i++)
            {
                System.out.print(ptr.getdata()+" ");
                ptr=ptr.getlink();
            }
        }
    }
 }
    


public class queue_linkedlist
{
 public static void main(String args[])throws Exception
  {
    int ch,x;
    Scanner i=new Scanner(System.in);
    System.out.println("enter queue size");
    int s=i.nextInt();
    queue obj=new queue();
    while(true)
    {
        System.out.println("\nenter choice 1.enqueue 2.dequeue 3.peek 4.exit");
        ch=i.nextInt();
        switch(ch)
        {
            case 1: System.out.println("enter element");
            x=i.nextInt();
            obj.enqueue(x, s);
            obj.display();
            break;
            case 2: obj.dequeue();
            obj.display();
            break;
            case 3:obj.peek();
            break;
            case 4:System.exit(0);
            default:System.out.println("invalid choice");

        }
    }
 }   
}

