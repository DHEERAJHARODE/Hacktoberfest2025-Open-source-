import java.util.*;

class Node {
	int[] point;
	Node left, right;

	public Node(int[] arr)
	{
		this.point = arr;
		this.left = this.right = null;
	}
}

class KDtree {
	int k = 2;

	public Node newNode(int[] arr) { return new Node(arr); }

	public Node insertRec(Node root, int[] point, int depth)
	{
		if (root == null) {
			return newNode(point);
		}

		int cd = depth % k;
		if (point[cd] < root.point[cd]) {
			root.left
				= insertRec(root.left, point, depth + 1);
		}
		else {
			root.right
				= insertRec(root.right, point, depth + 1);
		}

		return root;
	}

	public Node insert(Node root, int[] point)
	{
		return insertRec(root, point, 0);
	}

	public boolean arePointsSame(int[] point1, int[] point2)
	{
		for (int i = 0; i < k; ++i) {
			if (point1[i] != point2[i]) {
				return false;
			}
		}
		return true;
	}

	public boolean searchRec(Node root, int[] point, int depth)
	{
		if (root == null) {
			return false;
		}
		if (arePointsSame(root.point, point)) {
			return true;
		}

		int cd = depth % k;
		if (point[cd] < root.point[cd]) {
			return searchRec(root.left, point, depth + 1);
		}
		return searchRec(root.right, point, depth + 1);
	}

	public boolean search(Node root, int[] point)
	{
		return searchRec(root, point, 0);
	}

	public static void main(String[] args)
	{
		KDtree kdTree = new KDtree();

		Node root = null;
		int[][] points
			= { { 3, 6 }, { 17, 15 }, { 13, 15 }, { 6, 12 },{ 9, 1 }, { 2, 7 }, { 10, 19 } };

		int n = points.length;

		for (int i = 0; i < n; i++) {
			root = kdTree.insert(root, points[i]);
		}

		int[] point1 = { 10, 19 };
		System.out.println(kdTree.search(root, point1)? "Found": "Not Found");

		int[] point2 = { 12, 19 };
		System.out.println(kdTree.search(root, point2)? "Found": "Not Found");
	}
}
