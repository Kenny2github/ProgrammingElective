void recursiveBubble(int* arrv, int arrc) {
	if (arrc <= 1) return;
	register int i, tmp;
	for (i = 0; i < arrc - 1; ++i) {
		if (arrv[i + 1] < arrv[i]) {
			// swap
			tmp = arrv[i];
			arrv[i] = arrv[i + 1];
			arrv[i + 1] = tmp;
		}
	}
	// recursively sort a sublist that
	// excludes the newly sorted last item
	recursiveBubble(arrv, arrc - 1);
}