// blocks in loops
int main() {
	int a = 10;
	int *b = &a;

	while (*b > 0) {
		*b = a + 1;

		if (a > 20) {
			*b = 10;
		}
	}
}
