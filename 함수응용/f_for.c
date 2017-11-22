extern int f_for(int n) {
	int i;
	int hap = 0;
	for (i = 1; i <= n; i++) {
		if (i == 5)  continue;
		printf("%2d", i);
		hap = hap + i;
		if (i == 7)break;
	}
	printf("\n for ¹® : hap = %d \n\n", hap);
	return 0;
}