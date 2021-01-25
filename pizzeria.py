import math
import os
import random
import sys

def dfs(vec , visited , x , y , rem):
	n = len(vec)
	i = 0
	newx = 0
	newy = 0
	if rem == 0:
		return
	xcor = [-1,1,0,0]
	ycor = [0,0,-1,1]
	for i in range(4):
		newx = x + xcor[i]
		newy = y + ycor[i]
		if newx >= 0 and newx < n and newy >= 0 and newy < n and rem and visited[newx][newy] == 0:
			vec[newx][newy] = vec[newx][newy] + 1
			visited[newx][newy] = 1
			dfs(vec , visited , newx , newy , rem - 1)
	return

def printvec(vec):
	n = len(vec)
	for i in range(n):
		for j in range(n):
			print(vec[i][j] , end = " ")
		print()
	return


def reset(vec):
	n = len(vec)
	for i in range(n):
		for j in range(n):
			vec[i][j] = 0
	return

if __name__ == '__main__':
	n , m = input().split()
	n , m = int(n) , int(m)
	maxi = 0
	vec = list()
	for i in range(n):
		vec.append([0] * n)
	visited = list()
	for i in range(n):
		visited.append([0] * n)

	while m:
		x , y , rem = input().split()
		x , y , rem = int(x) , int(y) , int(rem)
		x = x - 1
		y = y - 1
		vec[x][y] += 1
		visited[x][y] = 1
		dfs(vec,visited,x,y,rem)
		reset(visited)
		m = m - 1
	#printvec(vec)

	for i in range(n):
		for j in range(n):
			maxi = max(maxi , vec[i][j])
	print(maxi)
