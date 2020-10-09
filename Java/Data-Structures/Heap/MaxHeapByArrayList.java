import java.util.ArrayList;

/** A max heap based on an array list. */
public class MaxHeapByArrayList {

  ArrayList<Integer> maxHeap;

  /** Constructor; Creates the maxHeap arrayList. */
  public MaxHeapByArrayList() {
    maxHeap = new ArrayList<>();
  }

  /**
   * Adds an item to the heap, while ensuring it's a MinHeap.
   *
   * @param element - the item to be added
   */
  public void insert(int element) {
    /*
     * Understand that (in arrayList):
     * An element's left child: i * 2 + 1
     * An element's right child: i * 2 + 2
     * An element's parent: Math.floor((i - 1) / 2)
     */

    // Add the new element to the end of the array.
    maxHeap.add(element);
    if (maxHeap.size() > 1) {
      int lastIndex = maxHeap.size() - 1;
      // Continue swapping elements until the new element is smaller than its parent root is
      // reached.
      while (maxHeap.get(lastIndex) > maxHeap.get((int) Math.floor((lastIndex - 1) / 2))) {
        if (lastIndex >= 0) {
          int temp = maxHeap.get(lastIndex);
          maxHeap.set(lastIndex, maxHeap.get((int) Math.floor((lastIndex - 1) / 2)));
          maxHeap.set((int) Math.floor((lastIndex - 1) / 2), temp);
          if (Math.floor((lastIndex - 1) / 2) > 0) {
            lastIndex = (int) Math.floor((lastIndex - 1) / 2);
          } else {
            break;
          }
        }
      }
    }
  }

  /**
   * Removes an item to the heap, while ensuring it's a MinHeap. Returns it
   *
   * @return int - the min value in the heap to be removed
   */
  public int remove() {
    int biggest = maxHeap.get(0);
    if (maxHeap.size() > 1) {
      maxHeap.set(0, maxHeap.get(maxHeap.size() - 1));
      maxHeap.remove(maxHeap.size() - 1);
      // If there are only two elements, simply compare and if child is bigger, then swap and return
      // value.
      if (maxHeap.size() == 2) {
        if (maxHeap.get(1) > maxHeap.get(0)) {
          int temp = maxHeap.get(0);
          maxHeap.set(0, maxHeap.get(1));
          maxHeap.set(1, temp);
        }
        return biggest;
      }
      int i = 0;
      int leftChild = 2 * i + 1;
      int rightChild = 2 * i + 2;
      // Continue swapping until the parent is greater than both children or you reach the last
      // level in the tree
      while (leftChild < maxHeap.size()
          && rightChild < maxHeap.size()
          && (maxHeap.get(i) <= maxHeap.get(leftChild)
              || maxHeap.get(i) <= maxHeap.get(rightChild))) {
        // If either child of the root is smaller than it, swap the root with the child of greater
        // value.
        if (maxHeap.get(leftChild) < maxHeap.get(rightChild)) {
          int temp = maxHeap.get(i);
          maxHeap.set(i, maxHeap.get(rightChild));
          maxHeap.set(rightChild, temp);
          i = 2 * i + 2;
        } else {
          int temp = maxHeap.get(i);
          maxHeap.set(i, maxHeap.get(leftChild));
          maxHeap.set(leftChild, temp);
          i = 2 * i + 1;
        }
        leftChild = 2 * i + 1;
        rightChild = 2 * i + 2;
      }
    } else if (maxHeap.size() == 1) {
      maxHeap.remove(maxHeap.size() - 1);
    } else {
      return -1;
    }
    return biggest;
  }

  /**
   * Returns the maxHeap arrayList
   *
   * @return maxHeap - the arrayList to be returned
   */
  public ArrayList<Integer> getMaxHeap() {
    return maxHeap;
  }

  /** Overridden toString function. Returns the arrayList's content in String. */
  @Override
  public String toString() {
    if (maxHeap.isEmpty()) {
      return "maxArrayHeap{arrayList=[]}";
    }

    final StringBuilder stringBuilder = new StringBuilder();

    maxHeap.forEach(e -> stringBuilder.append(",").append(e.toString()));
    return "maxHeap{arrayList=[" + stringBuilder.toString().substring(1) + "]}";
  }
}
