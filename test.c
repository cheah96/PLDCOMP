void p(char x) {
    putchar(x);
} 

int square(int x) {
    return x*x;
}

int main(int arg){
    int x = 1;
    int y = (x++)*2;
	return square(y);
}
