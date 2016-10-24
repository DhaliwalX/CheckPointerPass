// functions
int add(int *x, int *y) {
	return *x + *y;
}

int main() {
	int a = 10;
	int b = 20;

	int *aptr = &a;
	int *bptr = &b;

	add(aptr, bptr);

	return 0;
}
