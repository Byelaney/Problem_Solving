package tree;

//Find the sum of elements from index l to r where 0 <= l <= r <= n-1
//Change value of a specified element of the array arr[i] = x where 0 <= i <= n-1.
//both in O(logN)
public class SegmentTree {
	int st[];

	SegmentTree(int arr[],int n)
	{
		//allocate memory for segment tree

		//height of the tree
		int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));

		//maximum size of the tree
		int max_size = 2 * (int)Math.pow(2, x) - 1;

		st = new int[max_size];

		constructSTUtil(arr,0,n-1,0);

	}

	//a recursive function that constructs Segment Tree for array[ss...se]
	//si is index of the current code in segment tree st
	int constructSTUtil(int arr[],int ss,int se,int si)
	{
		if(ss == se)
		{
			st[si] = arr[ss];
			return st[si];
		}

		int mid = getMid(ss,se);

		st[si] = constructSTUtil(arr,ss,mid,2*si+1) + constructSTUtil(arr,mid+1,se,2*si+2);

		return st[si];
	}

	// A utility function to get the middle index from corner indexes.
    int getMid(int s, int e) {
        return s + (e - s) / 2;
    }

    /*  A recursive function to get the sum of values in given range
    of the array.  The following are parameters for this function.

  	st    --> Pointer to segment tree
  	si    --> Index of current node in the segment tree. Initially
            0 is passed as root is always at index 0
  	ss & se  --> Starting and ending indexes of the segment represented
                by current node, i.e., st[si]
  	qs & qe  --> Starting and ending indexes of query range
  */
    int getSumUtil(int ss, int se, int qs, int qe, int si)
    {
    	//query interval is larger
    	if(qs <= ss && qe >= se)
    		return st[si];

    	//two interval have no intersect
    	if(se < qs || qe < ss)
    		return 0;

    	int mid = getMid(ss,se);

    	return getSumUtil(ss,mid,qs,qe,2*si+1) + getSumUtil(mid+1,se,qs,qe,2*si+2);
    }




    // The function to update a value in input array and segment tree.
    // It uses updateValueUtil() to update the value in segment tree
    void updateValue(int arr[], int n, int i, int new_val)
    {
    	//edge check
    	if(i < 0 || i > n-1)
    	{
    		System.out.println("Invalid input");
    		return;
    	}

    	int diff = new_val - arr[i];
    	arr[i] = new_val;

    	updateValueUtil(0,n-1,i,diff,0);
    }


    /* A recursive function to update the nodes which have the given
    index in their range. The following are parameters
     st, si, ss and se are same as getSumUtil()
     i    --> index of the element to be updated. This index is in
              input array.
    diff --> Value to be added to all nodes which have i in range */
    void updateValueUtil(int ss, int se, int i, int diff, int si)
    {

        // Base Case: If the input index lies outside the range of
        // this segment
        if (i < ss || i > se)
            return;

        // If the input index is in range of this node, then update the
        // value of the node and its children
        st[si] += diff;
        if (se != ss) {
            int mid = getMid(ss, se);
            updateValueUtil(ss, mid, i, diff, 2 * si + 1);
            updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
        }

    }

    // Return sum of elements in range from index qs (quey start) to
    // qe (query end).  It mainly uses getSumUtil()
    // starts from 0
    public int getSum(int n, int qs, int qe)
    {
    	// Check for erroneous input values
        if (qs < 0 || qe > n - 1 || qs > qe) {
            System.out.println("Invalid Input");
            return -1;
        }

        return getSumUtil(0, n - 1, qs, qe, 0);
    }


    public void display()
    {
    	for(int i = 0;i<st.length;++i)
    		System.out.println(st[i]);
    }


	public static void main(String []args)
	{
		int [] a = {1,3,5,7,9,11};
		SegmentTree segTree = new SegmentTree(a,6);

		System.out.println(segTree.getSum(6, 0, 5));
	}

}
