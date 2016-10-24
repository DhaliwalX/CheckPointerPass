// loops
int main() {
	int a = 10;
	int *b = &a;

	while (*b > 0) {
		*b = a + 1;
	}
}
