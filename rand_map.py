import random

width = random.randint(1,500)
height = random.randint(1,500)
m = [[str(random.randint(-100,100)) for x in range(width)] for y in range(height)]
with open('random.fdf', 'w') as f:
	for line in m:
		f.write(' '.join(line) + '\n')
