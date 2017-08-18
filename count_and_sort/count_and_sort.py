def string_compression_count_sort(s):
	new_s = ''
	matrix = [[]]
	i = 0
	size = len(s)
	matrix = [[-1 for x in xrange(256)] for x in xrange(256)]

	while (i < size):
		cur = s[i]
		count = 0
		while (i < size and s[i] == cur):
			count += 1
			i += 1
		matrix[count][ord(cur)] = 1
		matrix[0][ord(cur)] = 1 #mark data existance

	for y in range(0, 256):
		if matrix[0][y] == 1:
			for x in range(1, 256):
				if matrix[x][y] == 1:
					new_s = new_s + chr(y) + str(x)
	return new_s

print(string_compression_count_sort('AAABBAABBBBBCCCDDCC'))