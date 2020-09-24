#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#define PERIOD 50
#define WIDTH 40
#define HEIGHT 12
#define HEIGHT2 24
#define BUFLEN (HEIGHT + 1) * (WIDTH * 2 + 2)
#define M_PI 3.14159265358979323846

void frame(int offset);

#ifdef __VSCODE
int main() {
#else
int anime_main() {
#endif
	int i = 0;
	while (1) {
		system("cls");
		frame(++i);
	}
	return 0;
}

void frame(int offset) {
	register int i, j;
	char buffer[BUFLEN+1]; // avoid many small printf calls
	int pos = -1; // prefer ++pos over pos++ because pos++ has to remember old value
	printf("%-40s| Triangle\n", "Sine"); // width of -40 means align left to 40 chars
	for (i = HEIGHT/2; i >= -HEIGHT/2; --i) {
		// sine wave
		for (j = 0; j < WIDTH; ++j) {
			if (round(sin(2 * M_PI * ((double)j + offset) / PERIOD) * HEIGHT/2) == i) {
				buffer[++pos] = '*'; // write plot into buffer
			} else {
				buffer[++pos] = ' ';
			}
		}
		buffer[++pos] = '|'; // separator between two adjacent graphs
		// triangle wave
		for (j = 0; j < WIDTH; ++j) {
			// function for triangle wave starting at 0
			if (abs((j + offset) % HEIGHT2 - HEIGHT2 / 2) - HEIGHT2/4 == i) {
				buffer[++pos] = '*';
			} else {
				buffer[++pos] = ' ';
			}
		}
		buffer[++pos] = '\n'; // one y-level done
	}
	buffer[BUFLEN] = 0; // NUL-terminate string
	puts(buffer);
	pos = -1;
	printf("%-40s| Square\n", "Sawtooth");
	for (i = HEIGHT/2; i >= -HEIGHT/2; --i) {
		// sawtooth wave
		for (j = 0; j < WIDTH; ++j) {
			if ((j + offset) % HEIGHT == 0) { // draw vertical line at cycle start
				buffer[++pos] = '*';
			} else if ((j + offset) % HEIGHT == (i+HEIGHT/2)) { // function for sawtooth
				buffer[++pos] = '*';
			} else {
				buffer[++pos] = ' ';
			}
		}
		buffer[++pos] = '|';
		// square wave
		for (j = 0; j < WIDTH; ++j) {
			if ((j + offset) % (PERIOD/2) == 0) { // ditto with previous
				buffer[++pos] = '*';
			} else if (round(
				sin(2 * M_PI *((double)j + offset) / PERIOD)
				/ fabs(sin(2 * M_PI *((double)j + offset) / PERIOD))
			) * HEIGHT/2 == i) { // sqr(x) = sgn(sin(x)) = sin(x)/abs(sin(x))
				buffer[++pos] = '*';
			} else {
				buffer[++pos] = ' ';
			}
		}
		buffer[++pos] = '\n';
	}
	buffer[BUFLEN] = 0; // NUL-terminate string
	puts(buffer);
}