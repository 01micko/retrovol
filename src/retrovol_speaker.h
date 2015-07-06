#ifndef __RETROVOL_SPEAKER_H__
#define __RETROVOL_SPEAKER_H__

static void print_output(char *colour);
int change_color(char *sel_color);

#ifdef _cplusplus
extern "C" {
#endif

extern int change_color(char*);

#ifdef _cplusplus
}
#endif

#endif /* __RETROVOL_SPEAKER_H__ */
