//this code will create  the tree using queue ds 
import java.util.*;

//stack ds
 class  stackk <T >{ // using generic types 
  T arr[];
  int size;              // used array as a physical data structure for stack and size will contain the size of array and top will point to the top most element of the stack
  int top;

    stackk(T arr[]){     //constructor for intilizing the refrence (arr ,size ,top) 
        if(arr.length>0)
       { 
         this.arr=arr;
         size=arr.length;
         top=arr.length-1;               
        }
      }
    @SuppressWarnings("unchecked")
    stackk(){                         // constructor intilzing the refrence (size ,top) and creation of array 
      Scanner ob  = new Scanner (System.in); 
      int size=ob.nextInt();
      Object arr[]=new Object[size];    // Object type array created,as you cant creat for generic typed 
      this.arr=(T[])arr;   // conversion form Ojbect type to T 
      size=arr.length;
      top=arr.length-1;

    }
     public T popp(){   // popp method for poping and returning the value from stack (if  value not present the will return null)
      
       T var=null;
       if(top <0)
       {
          return var;
        }

        else{
            var= arr[top];
            arr[top--]=null;
          }
          return var;

        }
        public void pushh(T var){    // pushh method for pushing the passed value to stack.
          if(top<arr.length-1)
          {top++;
          arr[top]=var;
          }

        }
        public void display(){    // display method for displaying the elements of stack
          for(int i=0;i<=top;i++)
          System.out.println(arr[i]);
        }
        public boolean isempty(){    // method for checking if stack is empty or not
          if(top <0)
          {    
            return true;
          }
    
          return false;
       }
    }


/// circular queue ds 
class queue<T>{  
    int front;
    int rear;
    T arr[];
    queue(){
        Scanner obj  = new Scanner (System.in);
        System.out.println("enter the size of queue");
        int size=obj.nextInt();
        Object arr2[]=new Object[size];    //same as above,cretion of Object type array 

        arr=(T[])arr2;   // conversion of Object type array to T
        rear=0;
        front=0;

    }
    public void push(T var){ 
      
       // pushing of a value of var into circular queue if my rear is 2 less than front  and if my rear is not equal to last index of queue and front should not be zero then
        if(rear%arr.length != front-1 && !(rear%arr.length==arr.length-1 && front==0))  
           { int insertingat=(++rear)%arr.length;     //getting of position to insert in a value (i had taken mod ,as my rear value will keep going on increasing so that mode will help me in getting the index)
            arr[insertingat]=var;}
        
        
        else 
        System.out.println("Queue overflow");
    }
    public T pop(){ 
      // deleting from queue if my front is not equal to real as my queueu would be empty then
        T value =null; 
        if(front!=rear){
            int deletingfrom=(++front)%arr.length;    // geeting the position for where i wanna delete (same explanation as given for rear )
            value=arr[deletingfrom];
            arr[deletingfrom]=null;
         }
        else
        System.out.println("queue underfolw");
        return value;
    }
    public void display(){   // method to display the content of queue 
        for(int i=front;i<rear;i++)   //taken front to rear because  front will always be less than the rear if not then queue will be empty
        System.out.println(arr[(i % arr.length)]);
    }
}



//  treee ds

class creatingb{
    
    nodes rootp;   //created for pointing to root node
    //blue print of node
    static class nodes{
         nodes left;
         int value;
         nodes right;
    }
    creatingb(queue bb){  //creation of first node in constructor
        nodes obj = new nodes();
        rootp=obj;
        Scanner in = new Scanner(System.in);
        System.out.println("enter the first node");
        obj.value=in.nextInt();
        bb.push(obj);

    }
    public void creatingtree(queue<creatingb.nodes> objj){
        nodes poi;
        Scanner in= new Scanner(System.in);
          //new node poped out from queue for which we want to create left and right if user want
            poi =objj.pop();
        while(poi != null ){ //this is going to be repated until poi is not null(or until it is getting node from queue)
          
            //asking for left node of a node that poped out of the queue
            System.out.println("enter left node otherwise -1 for null");
            int value1=in.nextInt();
            if( value1 != -1 )
            {
                nodes obj1= new nodes();
              obj1.value=value1;
              poi.left=obj1;
              objj.push(obj1);
            }
            else {  
                poi.left=null;
            }

            //asking for right node for the node that just poped out of the queue
            System.out.println("enter right node otherwise -1 for null");
            int value2=in.nextInt();
            if( value2 !=-1){
                nodes obj2 = new nodes();
                obj2.value=value2;
                objj.push(obj2);
                poi.right=obj2;
            }
            else{
                poi.right=null;
            }                      
            //getting the next node from  queue  and printing the message is poi doesent get any other node from the queue
                 poi =objj.pop();
                 if(poi == null){
                     System.out.println("treee created");
                     
                 }

        }
    }
    @SuppressWarnings("unchecked")
    //tree traversal (preorder)
    public void treet(nodes poi){   

        //tried using iteration but it did not work out as my code require to use the object containing null value

        //  stackk<creatingb.nodes> bb = new stackk<creatingb.nodes>();
        //  nodes poi=rootp;
        //  int controlingne;
        //  while(poi != null ||  !bb.isempty()){
        //      if(poi!=null)
        //      {
        //          System.out.println(poi.value);
        //          bb.pushh(poi);
        //          poi=poi.left;
        //      }
        //      else{
                 
        //         nodes temp= bb.popp();
        //         poi=temp.right;
        //      }
        //  }

        //recursive 
           //tree traversal
            if(poi != null){
                System.out.println(poi.value); 
                treet(poi.left);   
                treet(poi.right);
            }

    }
    //couting of nodes
    public int countingn(nodes head){
      if(head != null){
        int x=countingn(head.left);
        int y=countingn(head.right);
        return x+y+1;  //returning  previous node sum with adding 1 to it(of current node) added to it nodes             //// we can upgrade this for counting nodes with degree 2 m degree 1 or degree 0 or mix.
      }
      return 0; //returning 0 if the head is on null node
    }

}

public class creating_a_binary_tree_using_circular_queue{
    public static void main(String [] a){
        queue<creatingb.nodes> obj = new queue<creatingb.nodes>();
        creatingb bb = new creatingb (obj);
        //creation of tree
        bb.creatingtree(obj);
        // display of tree
         bb.treet(bb.rootp);

    }
}
