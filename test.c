int square (int a) {
    return a*a;
}

int main(int arg){
	int i = 3;
    if (i != square(2)) {
        i ++;
    }
	while(i < 3){
	    i ++;
	    putchar('Z');
	}
    if (i < 4) {
        i = 79;
    }
    return i;
}

