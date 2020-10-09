import sys
import os

# print the optimal value 

def get_optimal_value(capacity,weights, v_w):
    value = 0.
    weight=0

    while weight<capacity:


    	temp=max(v_w)

    	p=v_w.index(temp) 
    	q=v_w.pop(p)
    	r=weights.pop(p)

    	if r<=capacity:
    		value +=(r*q)
    		weight+=r
    	else:
    		value+=(capacity-weight)*q
    		weight+=capacity-weight


    return value



if __name__ == "__main__":
    print('enter the input in format [n, capacity, value1, weight1, value2, weight2.....]')
    data = list(map(int, input().split())) #example input format [n, capacity, value1, weight1, value2, weight2.....]
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]#extracting values from data
    weights = data[3:(2 * n + 2):2]  #extracting weights from data
    v_w= [ i/j for i,j in zip(values,weights)] #storing them in value1/weight1 format
    opt_value = get_optimal_value(capacity, weights, v_w)
    print("max value one can take {:.4f}".format(opt_value))
    