class Program
    {
        static void Main(string[] args)
        {
             
            MinHeap mh = new MinHeap(7);
            mh.insert(8);
            mh.insert(5);
            mh.insert(10);
            mh.insert(3);
            mh.insert(1);
            mh.insert(7);
            mh.insert(20);
            Console.WriteLine(mh.getMin());
            mh.displayHeap();
             
            mh.removeMin();
            Console.WriteLine(mh.getMin());
            mh.displayHeap();
 
            mh.remove(7);
            Console.WriteLine(mh.getMin());
            mh.displayHeap();
            int[] arr = {77,64,21,89,92,17,30,42,50,2 };
            mh.BuildMinHeap(arr);
            mh.displayHeap();
        }
    }
    class MinHeap
    {
        int[] arr;
        int arrSize;//size for the array container
        int heapSize;//keeps track of the number of elements
        public MinHeap()
        {
            arrSize = 0;
            heapSize = 0;
            arr = new int[arrSize];
        }
        public MinHeap(int size)
        {
            arr = new int[size];
        }
        public void setHeapSize(int size)
        {
            this.arrSize = size;
            arr = new int[size];
        }
        public void insert(int value)
        {
            if (heapSize == arr.Length)
            {
                throw new Exception("Heap is at full capacity!");
            }
            else
            {
                arr[heapSize] = value;
                heapSize++;
                siftUp(heapSize - 1);
            }
        }
        public void remove(int value)
        {
            for (int i = 0; i < heapSize - 1; i++)
            {
                if (arr[i] == value)
                {
                    arr[i] = arr[heapSize - 1];
                    heapSize--;
                    siftDown(i);
                    break;
                }
            }
        }
        public void removeMin()
        {
            if (heapSize == 0)
            {
                throw new Exception("Heap is empty!");
            }
            else
            {
                arr[0] = arr[heapSize - 1];
                heapSize--;
                if (heapSize > 0)
                {
                    siftDown(0);
                }
            }
        }
        private void siftUp(int index)
        {
            int parentIndex, temp;
            if (index != 0)
            {
                parentIndex = getParentIndex(index);
                if (arr[parentIndex] > arr[index])
                {
                    temp = arr[parentIndex];
                    arr[parentIndex] = arr[index];
                    arr[index] = temp;
                    siftUp(parentIndex);
                }
            }
        }
        private int getParentIndex(int index)
        {
            return (index - 1) / 2;
        }
        private void siftDown(int nodeIndex)
        {
            int leftChildIndex, rightChildIndex, minIndex, tmp;
 
            leftChildIndex = getLeftChildIndex(nodeIndex);
 
            rightChildIndex = getRightChildIndex(nodeIndex);
 
            if (rightChildIndex >= heapSize)
            {
                if (leftChildIndex >= heapSize)
                {
                    return;
                }
                else
                {
                    minIndex = leftChildIndex;
                }
            }
            else
            {
                if (arr[leftChildIndex] <= arr[rightChildIndex])
                {
                    minIndex = leftChildIndex;
                }
                else
                {
                    minIndex = rightChildIndex;
                }
            }
            if (arr[nodeIndex] > arr[minIndex])
            {
                tmp = arr[minIndex];
 
                arr[minIndex] = arr[nodeIndex];
 
                arr[nodeIndex] = tmp;
 
                siftDown(minIndex);
            }
        }
        private int getRightChildIndex(int nodeIndex)
        {
            return (2 * nodeIndex) + 2;
        }
        private int getLeftChildIndex(int nodeIndex)
        {
            return (2 * nodeIndex) + 1;
        }
        public void displayHeap()
        {
            Console.WriteLine("Elements of the heap:");
            for (int i = 0; i < heapSize; i++)
            {
                Console.Write("{0} ", arr[i]);
            }
             
            Console.WriteLine("\n***********************************");
        }
        public int getMin()
        {
            return arr[0];
        }
        public void BuildMinHeap(int[] input)
        {
            if (heapSize > 0)
            {
                //clear the current heap
                Array.Resize(ref arr, input.Length);
                heapSize = 0;
                for (int i = 0; i < arr.Length; i++)
                {
                    arr[i] = input[i];
                    heapSize++;
                }
            }
            for (int i = heapSize - 1 / 2; i >= 0; i--)
            {
                MinHeapify(i);
            }
        }
        private void MinHeapify(int index)
        {
            int left = 2 * index;
            int right = (2 * index) + 1;
            int smallest = index;
            if (left < heapSize && arr[left] < arr[index])
            {
                smallest = left;
            }
            else
            {
                smallest = index;
            }
            if (right < heapSize && arr[right] < arr[smallest])
            {
                smallest = right;
            }
            if (smallest != index)
            {
                swap(ref arr, index, smallest);
                MinHeapify(smallest);
            }
        }
        private void swap(ref int[] input, int a, int b)
        {
            int temp = input[a];
            input[a] = input[b];
            input[b] = temp;
        }
        public void deleteHeap()
        {
            Array.Resize(ref arr, 0);
            heapSize = 0;
        }
    }