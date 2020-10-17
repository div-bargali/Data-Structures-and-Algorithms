//implementation of segment tree in java.
//below is a segment_class tree which includes all the utility functions to maintain the segment tree.
//below implementation is to find the minimum in a sub-array for which segment tree is useful.

import java.util.*;


class segment_tree {
	//public array which holds the structure of segment tree
	public static int[] sg;
	//public array which will hold the actual input array
	public static int[] arr;
	//main method to drive the program
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//input size of the array
		System.out.print("Enter the size of the array : ");
		int n = sc.nextInt();
		System.out.print("Enter array integers seperated by space : ");
		arr = new int[n];
		for(int i=0; i<n; i++)
			arr[i] = sc.nextInt();

		//sizr of the segment tree which will be of the size of complete binary tree.
		sg = new int[(1<<((int)Math.ceil(Math.log(n)/Math.log(2))) + 1)-1];
		//build the seggment tree
		build(0,0,n-1);
		System.out.print("Enter 2 indexes of a subarray : ");
		int x = sc.nextInt(), y = sc.nextInt();
		System.out.println("minimum of this subarray will be : " + query(0,0,n-1,x,y));
		return;
	}

	//utility function for initial building of the binary tree
	public static void build(int node, int start, int end) {
        if(start == end) {
            sg[node] = arr[start];
            return;
        }
        int mid = (start+end)>>1;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        sg[node] = Math.min(sg[2*node+1], sg[2*node+2]);
        return;
    }

    //utility function if we want to update the input array
    public static void update(int node, int start, int end, int x, int y) {
        if(start == end) {
            sg[node] = y;
            arr[x] = y;
            return;
        }
        int mid = (start+end)>>1;
        if(x >= start && x <= mid)
            update(2*node+1, start, mid, x, y);
        else
            update(2*node+2, mid+1, end, x, y);
        sg[node] = Math.min(sg[2*node+1], sg[2*node+2]);
        return;
    }

    //utility function to query the segment tree
    public static int query(int node, int start, int end, int l, int r) {
        if(start >= l && end <= r)
            return sg[node];
        if(start > r || end < l)
            return Integer.MAX_VALUE;
        int mid = (start+end)>>1;
        int p1 = query(2*node+1, start, mid, l, r);
        int p2 = query(2*node+2, mid+1, end, l, r);
        return Math.min(p1,p2);
    }
}