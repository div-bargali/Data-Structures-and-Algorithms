// Operations on Fibonacci Heap in Java

// Node creation
class node {
  node parent;
  node left;
  node right;
  node child;
  int degree;
  boolean mark;
  int key;

  public node() {
    this.degree = 0;
    this.mark = false;
    this.parent = null;
    this.left = this;
    this.right = this;
    this.child = null;
    this.key = Integer.MAX_VALUE;
  }

  node(int x) {
    this();
    this.key = x;
  }

  void set_parent(node x) {
    this.parent = x;
  }

  node get_parent() {
    return this.parent;
  }

  void set_left(node x) {
    this.left = x;
  }

  node get_left() {
    return this.left;
  }

  void set_right(node x) {
    this.right = x;
  }

  node get_right() {
    return this.right;
  }

  void set_child(node x) {
    this.child = x;
  }

  node get_child() {
    return this.child;
  }

  void set_degree(int x) {
    this.degree = x;
  }

  int get_degree() {
    return this.degree;
  }

  void set_mark(boolean m) {
    this.mark = m;
  }

  boolean get_mark() {
    return this.mark;
  }

  void set_key(int x) {
    this.key = x;
  }

  int get_key() {
    return this.key;
  }
}

public class fibHeap {
  node min;
  int n;
  boolean trace;
  node found;

  public boolean get_trace() {
    return trace;
  }

  public void set_trace(boolean t) {
    this.trace = t;
  }

  public static fibHeap create_heap() {
    return new fibHeap();
  }

  fibHeap() {
    min = null;
    n = 0;
    trace = false;
  }

  private void insert(node x) {
    if (min == null) {
      min = x;
      x.set_left(min);
      x.set_right(min);
    } else {
      x.set_right(min);
      x.set_left(min.get_left());
      min.get_left().set_right(x);
      min.set_left(x);
      if (x.get_key() < min.get_key())
        min = x;
    }
    n += 1;
  }

  public void insert(int key) {
    insert(new node(key));
  }

  public void display() {
    display(min);
    System.out.println();
  }

  private void display(node c) {
    System.out.print("(");
    if (c == null) {
      System.out.print(")");
      return;
    } else {
      node temp = c;
      do {
        System.out.print(temp.get_key());
        node k = temp.get_child();
        display(k);
        System.out.print("->");
        temp = temp.get_right();
      } while (temp != c);
      System.out.print(")");
    }
  }

  public static void merge_heap(fibHeap H1, fibHeap H2, fibHeap H3) {
    H3.min = H1.min;

    if (H1.min != null && H2.min != null) {
      node t1 = H1.min.get_left();
      node t2 = H2.min.get_left();
      H1.min.set_left(t2);
      t1.set_right(H2.min);
      H2.min.set_left(t1);
      t2.set_right(H1.min);
    }
    if (H1.min == null || (H2.min != null && H2.min.get_key() < H1.min.get_key()))
      H3.min = H2.min;
    H3.n = H1.n + H2.n;
  }

  public int find_min() {
    return this.min.get_key();
  }

  private void display_node(node z) {
    System.out.println("right: " + ((z.get_right() == null) ? "-1" : z.get_right().get_key()));
    System.out.println("left: " + ((z.get_left() == null) ? "-1" : z.get_left().get_key()));
    System.out.println("child: " + ((z.get_child() == null) ? "-1" : z.get_child().get_key()));
    System.out.println("degree " + z.get_degree());
  }

  public int extract_min() {
    node z = this.min;
    if (z != null) {
      node c = z.get_child();
      node k = c, p;
      if (c != null) {
        do {
          p = c.get_right();
          insert(c);
          c.set_parent(null);
          c = p;
        } while (c != null && c != k);
      }
      z.get_left().set_right(z.get_right());
      z.get_right().set_left(z.get_left());
      z.set_child(null);
      if (z == z.get_right())
        this.min = null;
      else {
        this.min = z.get_right();
        this.consolidate();
      }
      this.n -= 1;
      return z.get_key();
    }
    return Integer.MAX_VALUE;
  }

  public void consolidate() {
    double phi = (1 + Math.sqrt(5)) / 2;
    int Dofn = (int) (Math.log(this.n) / Math.log(phi));
    node[] A = new node[Dofn + 1];
    for (int i = 0; i <= Dofn; ++i)
      A[i] = null;
    node w = min;
    if (w != null) {
      node check = min;
      do {
        node x = w;
        int d = x.get_degree();
        while (A[d] != null) {
          node y = A[d];
          if (x.get_key() > y.get_key()) {
            node temp = x;
            x = y;
            y = temp;
            w = x;
          }
          fib_heap_link(y, x);
          check = x;
          A[d] = null;
          d += 1;
        }
        A[d] = x;
        w = w.get_right();
      } while (w != null && w != check);
      this.min = null;
      for (int i = 0; i <= Dofn; ++i) {
        if (A[i] != null) {
          insert(A[i]);
        }
      }
    }
  }

  // Linking operation
  private void fib_heap_link(node y, node x) {
    y.get_left().set_right(y.get_right());
    y.get_right().set_left(y.get_left());

    node p = x.get_child();
    if (p == null) {
      y.set_right(y);
      y.set_left(y);
    } else {
      y.set_right(p);
      y.set_left(p.get_left());
      p.get_left().set_right(y);
      p.set_left(y);
    }
    y.set_parent(x);
    x.set_child(y);
    x.set_degree(x.get_degree() + 1);
    y.set_mark(false);
  }

  // Search operation
  private void find(int key, node c) {
    if (found != null || c == null)
      return;
    else {
      node temp = c;
      do {
        if (key == temp.get_key())
          found = temp;
        else {
          node k = temp.get_child();
          find(key, k);
          temp = temp.get_right();
        }
      } while (temp != c && found == null);
    }
  }

  public node find(int k) {
    found = null;
    find(k, this.min);
    return found;
  }

  public void decrease_key(int key, int nval) {
    node x = find(key);
    decrease_key(x, nval);
  }

  // Decrease key operation
  private void decrease_key(node x, int k) {
    if (k > x.get_key())
      return;
    x.set_key(k);
    node y = x.get_parent();
    if (y != null && x.get_key() < y.get_key()) {
      cut(x, y);
      cascading_cut(y);
    }
    if (x.get_key() < min.get_key())
      min = x;
  }

  // Cut operation
  private void cut(node x, node y) {
    x.get_right().set_left(x.get_left());
    x.get_left().set_right(x.get_right());

    y.set_degree(y.get_degree() - 1);

    x.set_right(null);
    x.set_left(null);
    insert(x);
    x.set_parent(null);
    x.set_mark(false);
  }

  private void cascading_cut(node y) {
    node z = y.get_parent();
    if (z != null) {
      if (y.get_mark() == false)
        y.set_mark(true);
      else {
        cut(y, z);
        cascading_cut(z);
      }
    }
  }

  // Delete operations
  public void delete(node x) {
    decrease_key(x, Integer.MIN_VALUE);
    int p = extract_min();
  }

  public static void main(String[] args) {
    fibHeap obj = create_heap();
    obj.insert(7);
    obj.insert(26);
    obj.insert(30);
    obj.insert(39);
    obj.insert(10);
    obj.display();

    System.out.println(obj.extract_min());
    obj.display();
    System.out.println(obj.extract_min());
    obj.display();
    System.out.println(obj.extract_min());
    obj.display();
    System.out.println(obj.extract_min());
    obj.display();
    System.out.println(obj.extract_min());
    obj.display();
  }
}