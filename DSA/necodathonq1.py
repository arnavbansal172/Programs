#IN a smart city there is a queue of citizens waiting to use electic vehilce charging stations 
#The queue is organised in such a way that 0th citizen is at the front and the n-1 citizen is at the back 
#You are given 0 indexed array charging requests where the length n - numer f charging slots that the ith citizen would like to use is chargingrequests[i]
#
#each citizen takes 1 minute to utilize a charging slot a citizen can use only 1 slot at time and has to move to the back of the line. 
#if a citizen has no more slots to request they will leave the quue
#
#return the time taken for the citizen at postion k(0 indexed) to finish using all heir requested charging slots
#
#
#
#Input format 
#The first line of input consists of the no of citizen line 
#the second line consits of an array of integers charginrequests, reps the no of charging slots eah citizen would want to use 
#third line consists f the position k of the citizen for hom we want to calculate the time 
#
#
#
#Output 
#Print time taken for citizen at k to. finish using all their requested charging slots


def time_taken(n, chargingrequests, k):
    time = 0
    while chargingrequests[k] > 0:
        time += 1
        chargingrequests[k] -= 1
        if chargingrequests[k] == 0:
            n -= 1
        if n == 0:
            break
        k = (k + 1) % len(chargingrequests)
    return time

n = int(input())
chargingrequests = list(map(int, input().split()))
k = int(input())
print(time_taken(n, chargingrequests, k))

