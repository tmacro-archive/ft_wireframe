import random

m = [[str(random.randint(-100,100)) for x in range(16)] for y in range(16)]
with open('random.fdf', 'w') as f:
	for line in m:
		f.write(' '.join(line) + '\n')
