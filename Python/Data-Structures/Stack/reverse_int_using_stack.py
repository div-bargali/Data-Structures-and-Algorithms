st = []; 


def push_digits(number): 

	while (number != 0): 
		st.append(number % 10); 
		number = int(number / 10); 


def reverse_number(number): 
	push_digits(number); 
	
	reverse = 0; 
	i = 1; 
	
	while (len(st) > 0): 
		reverse = reverse + (st[len(st) - 1] * i); 
		st.pop(); 
		i = i * 10; 
	

	return reverse; 


number = int(input()); 
print(reverse_number(number)); 
