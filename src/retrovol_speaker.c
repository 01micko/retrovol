#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "retrovol_speaker.h"
#define FILE_PATH 	"/.retrovol/"

//Speaker rays <)))
char ray_colour[8];
//SVG icon framework
const char head1[45] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
const char head2[85] = "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" height=\"100\" width=\"100\">\n";
const char string1[83] = "\t<polygon points=\"10 60,  10 40,  20 40,  40 25, 40 75, 20 60, 10 60\" style=\"fill:"; //colour;
const char string2[28] = ";fill-opacity: 0.5; stroke:"; //colour;
const char string3[24] = ";stroke-width: 2;\"/>\n";
const char string4[70] = "\t<path d=\"m 50,30 c 20,20 0,42 0,42\" style=\"fill:none;stroke:"; //colour;
const char string5[22] = ";stroke-width:4\"/>\n";
const char string6[73] = "\t<path d=\"m 60,20 c 30,30 0,62 0,62\" style=\"fill:none;stroke:"; //colour;
const char string7[22] = ";stroke-width:4\"/>\n";
const char string8[72] = "\t<path d=\"m 70,10 c 40,40 0,82 0,82\" style=\"fill:none;stroke:"; //colour;
const char string9[22] = ";stroke-width:4\"/>\n";
const char foot[9] = "</svg>\n";
const char stringX[101] = "\t<line x1=\"5\" y1=\"75\" x2=\"60\" y2=\"20\" style=\"fill:none;stroke:red;stroke-width:7\"/>\n";

FILE *fp;
char file_to[5][256];	

void change_color(char *colour) {
	char home[256];
	strcpy(home, getenv("HOME"));
	strcpy(ray_colour, colour);
	char img_dir[256];
	sprintf(img_dir, "%s%s", home, FILE_PATH);
	// define where images are to be made
	sprintf(file_to[0], "%saudio-volume-high.svg", img_dir);
	sprintf(file_to[1], "%saudio-volume-medium.svg", img_dir);
	sprintf(file_to[2], "%saudio-volume-low.svg", img_dir);
	sprintf(file_to[3], "%saudio-volume-none.svg", img_dir);
	sprintf(file_to[4], "%saudio-volume-muted.svg", img_dir);
	
	//make directory
	char icon_dir[256];
	sprintf(icon_dir,"%s%s", home, FILE_PATH);
	int icon_access;
	icon_access =  access(icon_dir, F_OK);
	if (icon_access != 0) {
		if (mkdir(icon_dir, 0755) != 0) return;
	}
	//build the icons
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
		fprintf(fp,"%s",foot); //common to all
		fclose(fp);
	}
}
