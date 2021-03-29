print("5912")

def perm(lst,n):
	ret = []
	if n > len(lst): return ret

	if n==1:
		for i in lst:
			ret.append([i])
	elif n>1:
		for i in range(len(lst)):
			temp = [i for i in lst]
			temp.remove(lst[i])
			for p in perm(temp,n-1):
				ret.append([lst[i]]+p)

	return ret
num = 0
for i in range(2, 8):
	p = perm([i for i in range(1, i+1)], i)
	for pp in p:
		num += 1
		print("Case #" + str(num) + ": ")
		for _ in pp:
			print(_, end=' ')
		print()
