def LongestPalindromSubsequence(s):
    n = len(s)
    L = [[0 for i in range(0,n)] for i in range(0,n)]       
    for i in range(0,n):
        L[i][i] = 1
    
    for i in range(2,n+1):
        for j in range(0,n-i+1):
            k = i + j -1
            if s[k] == s[j] and i==2:
                L[j][k] = 2
            elif s[k]==s[j]:
                L[j][k] = L[j+1][k-1] + 2
            else:
                L[j][k] = max(L[j][k-1],L[j+1][k])

    return L[0][n-1]


print "Enter String to Find Pelindrom."
p = raw_input()
LPS = LongestPalindromSubsequence(p)
print LPS