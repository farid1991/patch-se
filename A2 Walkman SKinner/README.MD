;A2 Walkman skinner
;Adds possibility to edit the Position,Color,Font
;Enable/Disable Title,Artist,Album,Genre,Total/Elapsed/Remaining time,Extension,Bit-rate,Total/Current track number,progress-bar,Album art
;Adds new items of Genre,Extension,Bit-rate,Overlay image to Walkman
;Adds possibility to edit position of icons shuffle/EQ/loop/state/wheel,Title/Artist/Album/Background/Overlay image
;Adds possibility to use skins in Walkman Player
;Adds skin editor for easy loading & editing of skins
;Adds possibility to use Walkman 4 visualization
;Redraws everything in Walkman,optimized for better Walkman experience
;v.1.5
;(c) blacklizard
;(r) KreN
;(e) farid, D3mon, blacklizard

Changelog:
[+]Faster load Image
[+]Reduce RAM usage
[+]Player does not restart after change skin
[+]Added Volume Bar

Changes from blacklizard:
[+]Possibility redrawing an image on top of the progressbar.
[+]Icon should be called "PROGRESSBAR_OVERLAY.png"(portrait) and "PROGRESSBAR_OVERLAY_LANDSCAPE.png" (landscape)

Changes from D3mon:
[+]Added patch "Ability to set a track playing on continuous replay" (Addon of the last post is not needed). Icon should be called "MP_MODE_REPEAT_ONE_ICN.png"
[+]File with the current skins CurrentSkin transferred to your phone
[+]Fixed display the current time from 60:00, before appearing as a 00:00
[+]Slightly optimized the patch, as a consequence - reduced its volume
[+]Added a way out Editor's coordinates by pressing End
[+]Added a way out of the editor by pressing the END button on the menu "Apply / set skin"
[+]Added automatic closing after installing a skin editor
[+]Removed exit to standby mode from the skin settings by pressing the End
[+]When you exit the editor in any way the cover itself is updated!

Changes from farid:
[+]Added background for GUI Coordinates at each skins.
[+]It supports animated skins - there are 9 standard animated skins
[+]You can add your own skins!

[+]Create thumbnail for GUI with selecting skins called: X_viz.png (where X is a number, egz.: if we've got 9 skins and we want to add tenth, rename file to 10_viz.png)
[+]Create skin called: X.png (like before - X is a number, for example 6.png)
[+]You don't need to restart player after adding skins. You don't even need to restart player. it detects number of skins on creating GUI with selecting skins.

fixed:
[+]custom equalizer, shuffle and repeat icon
[+]some code improvements :)