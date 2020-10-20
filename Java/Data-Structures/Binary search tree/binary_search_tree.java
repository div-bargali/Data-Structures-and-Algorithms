// binary search tree creation, new node insertion , and node deletion
import java.util.*;

class bstree{
    //node structure
    nodes headp;
    static class nodes{
        nodes left;
        int value;
        nodes right;
    }
    //bst creation
    void bstreec(){
    int size;
    nodes duph=headp;
    Scanner in= new Scanner(System.in);
    System.out.println("enter the no of nodes you want to insert");
    int no=in.nextInt();        //no of  nodes asked 
    for(int i=0;i<no;i++)
    {
        if(headp == null){               //if our root is null first create root node
            nodes obj = new nodes ();
            System.out.println("enter the root node");     
            int value=in.nextInt();
            obj.value=value;
            headp=obj;
             duph=headp;

        }                              // if root is assigned or had been created then create futher
        else{
            duph=headp;
            System.out.println("enter next node");
            int value=in.nextInt();
            nodes obj = new nodes();
            obj.value=value;
            while(duph != null){                                 //traversing the tree from root node till we find the position to insert the given node and inserting it
                if(value < duph.value && duph.left != null){
                    duph=duph.left;
                }
                else if(value >duph.value && duph.right != null){
                    duph=duph.right;
                }
                else if( value <duph.value){
                    duph.left=obj;
                    duph=duph.left;     // now going on my newly node which is inserted
                     duph=duph.left;    // going to left of my newly node(it dosent matter you can go right also)
                }
                else{
                    duph.right=obj;
                    duph=duph.right;   // now going on my newly node which is inserted
                     duph=duph.right;    // going to right of my newly node(it dosent matter you can go left also)
                }
            }

        }
        
    }
   
    }

    //insertion of node
    void insert(int value){      //taking the value
            nodes duph=headp; 
            nodes obj = new nodes();
            obj.value=value;
            while(duph != null){             //travrsing the whol
                if(value < duph.value && duph.left != null){
                    duph=duph.left;
                }
                else if(value >duph.value && duph.right != null){
                    duph=duph.right;
                }
                else if( value <duph.value){
                    duph.left=obj;
                    duph=duph.left;             //same explanation as explained above
                     duph=duph.left;            //same explanation as explained above 
                }
                else{
                    duph.right=obj;
                    duph=duph.right;        
                     duph=duph.right;
                    
                }
            }
    }
   

        // Get minimum element in binary search tree
	public  nodes minimumElement(nodes root) {
		if (root.left == null)
			return root;
		else {
			return minimumElement(root.left);
		}
	}


        public  nodes deleteNode(nodes root, int value) {
		if (root == null)
			return null;
		if (root.value > value) {
			root.left = deleteNode(root.left, value);
		} else if (root.value < value) {
			root.right = deleteNode(root.right, value);
 
		} else {
			// if nodeToBeDeleted have both children
			if (root.left != null && root.right != null) {
				nodes temp = root;
				// Finding minimum element from right
				nodes minNodeForRight = minimumElement(temp.right);
				// Replacing current node with minimum node from right subtree
				root.value = minNodeForRight.value;
				// Deleting minimum node from right now
				root.right = deleteNode(root.right, minNodeForRight.value);
 
			}
			// if nodeToBeDeleted has only left child
			else if (root.left != null) {
				root = root.left;
			}
			// if nodeToBeDeleted has only right child
			else if (root.right != null) {
				root = root.right;
			}
			// if nodeToBeDeleted do not have child (Leaf node)
			else
				root = null;
		}
		return root;
	}

      public void treet(nodes poi){   
        //recursive 
           //tree traversal
            if(poi != null){
                System.out.println(poi.value); 
                treet(poi.left);   
                treet(poi.right);
            }

    }
}
public class binary_search_tree{
    public static void main(String [] arrrr){
        Scanner wow = new Scanner(System.in);
        //creting object 
        bstree obj = new bstree();
        obj.bstreec();
        
        System.out.println("tree :-");
        obj.treet(obj.headp);     //display of tree

        //calling to insert
        System.out.println("enter the value you wanna insert");
        int ni=wow.nextInt();
        obj.insert(ni);

        //calling for deletion of node
        System.out.println("enter the value you wanna delete");
        int val=wow.nextInt();
        obj.deleteNode(obj.headp,val);

        System.out.println("tree afterd:-");
        obj.treet(obj.headp);    //display of tree after deleting the node

    }
}
