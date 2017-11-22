extern int f_while(int n) {
	int i = 1;
	int hap = 0;
	while (i <= n) {
		if (i == 5) { i++; continue; }
		printf("%2d", i);
		hap = hap + i;
		if (i == 7)break;
		i++;
	}
	printf("\n while ¹® : hap = %d \n\n", hap);
	return 0;
}