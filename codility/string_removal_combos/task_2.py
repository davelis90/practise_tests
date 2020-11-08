# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    replace = 1
    while replace != 0:
        replace = 0
        S_removed = S.replace('AB', '')
        if (S_removed != S):
            replace = 1
            S = S_removed
            continue
        S_removed = S.replace('BA', '')
        if (S_removed != S):
            replace = 1
            S = S_removed
            continue
        S_removed = S.replace('CD', '')
        if (S_removed != S):
            replace = 1
            S = S_removed
            continue
        S_removed = S.replace('DC', '')
        if (S_removed != S):
            replace = 1
            S = S_removed
            continue
    return S
    
        


S1 = "CBACD"
S2 = "CABABD"
S3 = "ACBDACBD"

S1 = solution(S1)
S2 = solution(S2)
S3 = solution(S3)
print(S1)
print(S2)
print(S3)