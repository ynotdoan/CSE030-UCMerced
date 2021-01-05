#ifndef Functions_h
#define Functions_h

int max (int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

int even (int x) {
	if ((x % 2) == 0)  {
		return true;
	}
	else {
		return false;
	}
}

int sum (int x, int result = 0) {
	for (int i = 0; i <= x; i++) {
		if (x < 0) {
			return false;
		}
		else {
			result += i;
		}
	}
	return result;
}

#endif
