import java.util.ArrayList;

public class MinHeapByArrayList {
    ArrayList<Integer> minHeap;

    public MinHeapByArrayList() {
        minHeap = new ArrayList<>();
    }

    public void insert(int item) {
        /*
        Understand that:
        An element's left child: i * 2 + 1
        An element's right child: i * 2 + 2
        An element's parent: Math.floor((i-1) / 2)
        */

        // Add new element to the end of the array.
        minHeap.add(item);
        int lastIndex = minHeap.size() - 1;

        //Loop until new element is bigger than its parent or at root
        while (lastIndex >= 0 && minHeap.get(lastIndex) < minHeap.get((int)Math.floor((lastIndex - 1)/2))) {
            //Switch new element with parent if it is smaller than it
            int temp = minHeap.get(lastIndex);
            minHeap.set(lastIndex, minHeap.get((int) Math.floor((lastIndex - 1)/2)));
            minHeap.set((int)Math.floor((lastIndex - 1) / 2), temp);
            lastIndex = (int)Math.floor((lastIndex - 1)/2);
        }
    }

    public ArrayList<Integer> getMinHeap() {
        return minHeap;
    }

    public static void main(String[] args) {
        //Sample: Expected: 10 20 25 300 30 500 29
        MinHeapByArrayList mh = new MinHeapByArrayList();
        mh.insert(30);
        mh.insert(300);
        mh.insert(500);
        mh.insert(10);
        mh.insert(20);
        mh.insert(25);
        mh.insert(29);
        for(int i : mh.getMinHeap()) {
            System.out.println(i);
        }
    }
}
