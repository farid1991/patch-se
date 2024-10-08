# ScreenShooter
Add ability to take screenshot with Game A & Game B button.  

### Usage
- `Game A`: save screenshot as `PNG`.
- `Game B`: save screenshot as `BMP`.
- `Camera`: save screenshot as `PNG` when MusicApplication is active.
- On MusicApplication `Game A` and `Game B` button works as Next and Prev track button.
- BMP and PNG saved on `/usb/picture/snapshots/`

### Devices
- **U100 R7AA076**[^1]
- ...

### Patch Info
```
;Ability to take screenshot using button Game A&B
;Game A: save screenshot as PNG
;Game B: save screenshot as BMP
-Camera: save screenshot as PNG when MusicApplication is active
;On MusicApplication Game A+B button works as Next and Prev track button
;BMP and PNG saved on "/usb/picture/snapshots/"
;(c) farid
```

### Screenshot
#### **U100 R7AA076**
- **PNG**

![save-png1](snapshots/scr00-57-39.png) 
![save-png2](snapshots/scr03-09-25.png)

- **BMP**

![save-bmp1](snapshots/scr02-32-49.bmp) 
![save-bmp2](snapshots/scr02-33-46.bmp)

## libpng License
`ScreenShooter` use `libpng`. For the full libpng license, see [libpng.org](http://www.libpng.org/pub/png/libpng.html).

[^1]: [*libpng 1.2.16*](https://sourceforge.net/projects/libpng/files/libpng12/older-releases/1.2.16/)

## [Go Back](../readme.md)