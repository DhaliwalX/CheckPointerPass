int main() {
	int a = 10;
	int *b = &a;

	if (b == 0) {
		*b = 20;
	} else if (*b == 10) {
		a = *b + 10;
	}
}