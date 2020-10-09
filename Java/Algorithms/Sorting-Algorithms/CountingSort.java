static void countSort(int[] arr) 
	{ 
		int max = Arrays.stream(arr).max().getAsInt(); 
		int min = Arrays.stream(arr).min().getAsInt(); 
		int range = max - min + 1; 
		int count[] = new int[range]; 
		int output[] = new int[arr.length]; 
		for (int i = 0; i < arr.length; i++) 
		{ 
			count[arr[i] - min]++; 
		} 

		for (int i = 1; i < count.length; i++) 
		{ 
			count[i] += count[i - 1]; 
		} 

		for (int i = arr.length - 1; i >= 0; i--) 
		{ 
			output[count[arr[i] - min] - 1] = arr[i]; 
			count[arr[i] - min]--; 
		} 

		for (int i = 0; i < arr.length; i++) 
		{ 
			arr[i] = output[i]; 
		} 
	} 
