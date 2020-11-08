def solution(A):
    # write your code in Python 3.6
    A = sorted(A) # sort vector
    positive_counter = 1;
    # remove duplicate elements
    res = list(set(A))
    # print(res)
    
    # remove negative elements
    res = list(filter(lambda x : x > 0, res)) 
    # print(res)
    
    for element in A:
        if element == positive_counter:
            positive_counter = positive_counter + 1
        else:
            continue
    return positive_counter
    
A = [1, 3, 6, 4, 1, 2]
B = [1, 2, 3]
C = [-1, -3]

print(solution(A))
print(solution(B))
print(solution(C))