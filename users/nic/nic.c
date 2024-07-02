#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
float master_song[][2] = SONG(WORKMAN_SOUND);
float receiver_song[][2] = SONG(MUSIC_ON_SOUND);
#endif

