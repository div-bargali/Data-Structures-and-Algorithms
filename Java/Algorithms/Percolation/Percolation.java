import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {

    private boolean[][] grid;
    private int openSites;
    private final int len;
    private static final int SOURCE = 0;
    private final int sink;
    private final WeightedQuickUnionUF uf;

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        if (n <= 0) throw new IllegalArgumentException();
        len = n;
        grid = new boolean[n][n];
        sink = n * n + 1;
        uf = new WeightedQuickUnionUF(n * n + 2);
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        errorCheck(row, col);
        if (!isOpen(row, col)) openSites++;
        grid[row - 1][col - 1] = true;

        if (row == 1) // Union with SOURCE
            uf.union(getIndex(row, col), SOURCE);
        if (row == len) // Union with sink
            uf.union(getIndex(row, col), sink);

        // Union with neighbor(s)
        if (row > 1 && isOpen(row - 1, col))
            uf.union(getIndex(row, col), getIndex(row - 1, col));
        if (row < len && isOpen(row + 1, col))
            uf.union(getIndex(row, col), getIndex(row + 1, col));
        if (col > 1 && isOpen(row, col - 1))
            uf.union(getIndex(row, col), getIndex(row, col - 1));
        if (col < len && isOpen(row, col + 1))
            uf.union(getIndex(row, col), getIndex(row, col + 1));
    }

    private void errorCheck(int row, int col) {
        if (row <= 0 || row > len || col <= 0 || col > len) throw new IllegalArgumentException();
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        errorCheck(row, col);
        return grid[row - 1][col - 1];
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        errorCheck(row, col);
        return uf.find(getIndex(row, col)) == uf.find(SOURCE);
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return openSites;
    }

    // does the system percolate?
    public boolean percolates() {
        return uf.find(SOURCE) == uf.find(sink);
    }

    private int getIndex(int row, int col) {
        return len * (row - 1) + col;
    }

    public static void main(String[] args) {
        // testing
    }
}