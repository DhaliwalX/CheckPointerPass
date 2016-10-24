struct foo {
	int a;
};

struct bar {
	struct foo z;
};

int main() {
	struct bar *x;
	x->z;
	x->z.a;
}
