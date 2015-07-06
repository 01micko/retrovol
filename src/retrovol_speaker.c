#include <stdio.h>
#include <string.h>
#include "retrovol_speaker.h"

const char ray_colour[8] = "#FFCC00";
const char head1[45] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
const char head2[85] = "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" height=\"100\" width=\"100\">\n";
const char string1[83] = "\t<polygon points=\"10 60,  10 40,  20 40,  40 25, 40 75, 20 60, 10 60\" style=\"fill:"; //colour;
const char string2[28] = ";fill-opacity: 0.5; stroke:"; //colour;
const char string3[24] = ";stroke-width: 2;\"/>\n";
const char string4[70] = "\t<path d=\"M 55,27 c 24,23 0,48 0,48\" style=\"fill:none;stroke:"; //colour;
const char string5[22] = ";stroke-width:7\"/>\n";
const char string6[73] = "\t<path d=\"M 63,15 C 100,53 62,88 62,88\" style=\"fill:none;stroke:"; //colour;
const char string7[22] = ";stroke-width:7\"/>\n";
const char string8[72] = "\t<path d=\"M 72,5 C 120,54 73,97 73,97\" style=\"fill:none;stroke:"; //colour;
const char string9[22] = ";stroke-width:7\"/>\n";
const char string10[9] = "</svg>\n";
const char stringX[101] = "\t<line x1=\"5\" y1=\"75\" x2=\"60\" y2=\"20\" style=\"fill:none;stroke:red;stroke-width:7\"/>\n";

FILE *fp;
char file_to[5][256];	

static void print_output(char *colour) {
	strcpy(file_to[0], "/usr/share/retrovol/images/audio-volume-high.svg");
	strcpy(file_to[1], "/usr/share/retrovol/images/audio-volume-medium.svg");
	strcpy(file_to[2], "/usr/share/retrovol/images/audio-volume-low.svg");
	strcpy(file_to[3], "/usr/share/retrovol/images/audio-volume-none.svg");
	strcpy(file_to[4], "/usr/share/retrovol/images/audio-volume-muted.svg");
	
	int j;
	for (j = 0; j < 5; j++) {
		fp= fopen(file_to[j], "w");
		if (!fp) {
			fprintf(stderr, "Couldn't open %s for writing\n", file_to[j]);
			return;
		}
		fprintf(fp,"%s%s%s%s%s%s%s",head1,head2,string1,colour,string2,colour,string3); //common to all
		if (j == 0) {
			fprintf(fp,"%s%s%s",string4,ray_colour,string5);
			fprintf(fp,"%s%s%s",string6,ray_colour,string7);
			fprintf(fp,"%s%s%s",string8,ray_colour,string9);
		} else if (j == 1) {
			fprintf(fp,"%s%s%s",string4,ray_colour,string5);
			fprintf(fp,"%s%s%s",string6,ray_colour,string7);
		} else if (j == 2) {
			fprintf(fp,"%s%s%s",string4,ray_colour,string5);
		} else if (j == 3) {
			fprintf(fp,""); //dummy
		} else if (j == 4) {
			fprintf(fp,"%s",stringX);
		}
		fprintf(fp,"%s",string10); //common to all
		fclose(fp);
	}
}

int change_color(char *sel_color) {
	print_output(sel_color);
	return 0;
}
