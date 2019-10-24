read_ID3_info

Super lightweight MP3 ID3 metadata tag reader made for embedded systems.

=============

See my original [blog post](http://t413.com/2010/10/lightweight-mp3-id3-metadata-tag-reader/) about this project.

### Example
```
FIL file;
f_open(&file, file_name, (FA_READ | FA_OPEN_EXISTING));
char str[40];
read_ID3_info(TITLE_ID3,str,sizeof(str),&file);
printf("Title: %s\n",str);
f_close(&file);
```

This is also being used in [mp3_player_v2](https://github.com/t413/mp3_player_v2).


### License / Copyright
This work is licensed under the Creative Commons Attribution-ShareAlike 3.0. See source code comments for details. I’m flexible if this is incompatible with your needs, just email me and ask.

