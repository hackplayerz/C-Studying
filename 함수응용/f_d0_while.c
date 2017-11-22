extern int f_do_while(int n) {
	int i = 1;
	int hap = 0;
	do {
		if (i == 5) { i++; continue; }
		printf("%2d", i);
		hap = hap + i;
		if (i == 7)break;
		i++;
	} while (i <= n);
	return hap;
}