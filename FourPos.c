int FourPos(int values[], int length) {
	for (int i = 0; i <= length-4; i++) {
		if (values[i] == values[i+1] && values[i] == values[i+2] && values[i] == values[i+3]) {
			return i;
		}
	}
	return -1;
}