import java.util.Scanner;

public class NQueen {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		boolean[][] board = new boolean[n][n];
		printNQueen(board, 0, "");
		System.out.println();
		System.out.println(countNQueen(board, 0));
	}
	public static int countNQueen(boolean[][] board, int row) {
		if (row == board.length) {
			return 1;
		}
		int count = 0;
		for (int col = 0; col < board[row].length; col++) {
			if (Safe(board, row, col)) {
				board[row][col] = true;
				count = count + countNQueen(board, row + 1);
				board[row][col] = false;
			}
		}
		return count;
	}
	public static void printNQueen(boolean[][] board, int row, String res) {
		if (row == board.length) {
			System.out.print(res + " ");
			return;
		}
		for (int col = 0; col < board[row].length; col++) {
			if (Safe(board, row, col)) {
				board[row][col] = true;
				printNQueen(board, row + 1, res + "{" + (row + 1) + "-" + (col + 1) + "}");
				board[row][col] = false;
			}
		}
	}
	private static boolean Safe(boolean[][] board, int row, int col) {
		for (int i = row; i >= 0; i--) {
			if (board[i][col]) {
				return false;
			}
		}
		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j]) {
				return false;
			}
		}
		for (int i = row, j = col; i >= 0 && j < board.length; i--, j++) {
			if (board[i][j]) {
				return false;
			}
		}
		return true;
	}
}
