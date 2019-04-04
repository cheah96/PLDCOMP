int square (int a) {
    return a*a;
}

int main(int arg){
	int x;
	x = 2;
	x *= 4;
	x += x * (5+x);
	x /= 3;
	x += x /= 3;
    return x;
}

