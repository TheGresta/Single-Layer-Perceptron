// Return Y Points With Given X Points
int YPoint(int x, float *w, int factor = 1) {
	return (int)((float)(-1 * (float)factor * w[2] - w[0] * x) / (float)(w[1]));
}

