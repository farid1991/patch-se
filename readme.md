# PATCH-SE

## Sony Ericsson Patch
Patch sources for Sony Ericsson phones A1 and A2 platform

<details>
<summary>More details</summary>

* [SE phones history v200909](https://justdanpo.ru/data/projects/gsm/sephoneshistory.rar)

</details>

### Clone the project

```
git clone https://github.com/farid1991/patch-se.git
```
*If you don't have git on your machine, [install it](https://docs.github.com/en/get-started/quickstart/set-up-git).*

### Compile patch from source
<details>
<summary><B>using IAR IDE</B></summary>

* Open root projects directory
* Open iar project file (.eww) and compile to elf with iccarm (IAR Embedded Workbench 4.2)
* Select configuration.
* build project.

</details>
<details>
<summary><B>using VSCode</B></summary>

* install vscode extension [IAR For Visual Studio Code v1.3.1](https://marketplace.visualstudio.com/items?itemName=pluyckx.iar-vsc)
* Configure the extension and set the IAR directory in "iarvsc.iarInstallDirectories".
* Open root projects directory
* Select project and configuration.
* build project.

</details>

Convert elf to vkp using [elf2vkpex 1.03 (c) den_po](https://justdanpo.ru/data/projects/gsm/elf2vkpex.zip)  
`elf2vkp -eELFNAME.ELF -fFIRMWAREFILE.EXT`

### Installation
<details>
<summary><B>A1 Platform</B></summary>

* DB2000 and DB2010 [Tutorial]()
* DB2012, DB2020, and PNX5230 [Tutorial](https://mobilefree.justdanpo.ru/newbb_plus/viewtopic.php?topic_id=3592)

</details>

<details>
<summary><B>A2 Platform</B></summary>

* DB3150, DB32XX, and DB3350 [Tutorial]()

</details>

### Project Structure
<details>
<summary><B>Details</B></summary>

```
.
├── PatchName/
│   ├── asm/                    # asm files
│   ├── Target/                 # configuration files
│   ├── xcl/                    # linker files
│   ├── snapshots/              # screenshot files
│   ├── "BUILD_TARGET"/
│   │   ├── Exe/
│   │   │   └── PatchName.elf   # build files
│   │   ├── List/
│   │   │   └── *
│   │   └── Obj/
│   │       └── *
│   ├── *.c
│   ├── *.h
│   ├── PatchName.ewp           # iar project config
│   ├── PatchName.eww           # iar project
│   └── readme.md
├── ...
├── include/
│   ├── book/
│   ├── classes/
│   ├── types/
│   └── *.h
└── ...
```

</details>

## Patch info
VKP (V_Klay Patch) is format for patch file on Siemens and Sony Ericsson phones firmware.

### Get compiled VKP
* [MobileFree](https://mobilefree.justdanpo.ru/newbb_plus/viewforum.php?forum=8)

### List
* [A2 Walkman Skinner](A2WalkmanSkinner/readme.md)
* [Book Manager Mod](BookManagerMod/readme.md)
* [DBPlayer A2](DBPlayer/readme.md)
* [Flash Menu Picker](FlashMenuPicker/readme.md)
* [FM Radio Layout](FmRadio_Layout/readme.md)
* [Goto Shortcut](Goto_Shortcut/readme.md)
* [ManualEqualizer on DB3350](ManualEqualizer_DB3350/readme.md)
* [PNG Info](PNGinfo/readme.md)
* [Screen Shooter](Screenshooter/readme.md)
* [Shutdown Menu DB3350](ShutdownMenu_DB3350/readme.md)
* [Volume Redraw](VolumeRedraw/readme.md)
* **more patches added soon**

### Structure
```
;Device and Firmware
;Patch name
;Patch description
;(c) Patch creator
;(p) Patch porter
;pAtChFiLe=/boot/phone_app.cxc  ;optional
+base_address                   ;optional
patch_address: old_bytes new_bytes
```
### Example
```
;C510 SW-R1HA035
;Fix int2strID, Str2ID
;(!) Needed by some patches and elves (eg: BookManager)
;(c) IronMaster
;pAtChFiLe=/boot/phone_app.cxc
1401F5C2: 0D1C 0025
141818EE: 1D1C 0025
```

### Port Requests
Open PR to request port a patch to certain device

### Feature Requests
Feature requests are welcome. Please provide as much detail and context as possible.

### TODO
Migrate the projects using [Arm GNU Toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain) from IAR Build Tools for Arm

### License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
