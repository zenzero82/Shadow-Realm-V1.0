To support this types of codes and coders join our discord https://discord.com/invite/axNX3rhR9K
# BW Summary Screen
BW style summary screen for Fire Red.


https://github.com/user-attachments/assets/f7d1623d-0670-46be-a138-fa28149fc9e6


## How to Compile
- devkitARM, armips and the [pret tools](https://www.mediafire.com/file/bdq6eept3e00bb8/pret-tools.rar/file?dkey=87faiifqqvi&r=909) are required and must be set in `PATH`.
- Open the file `config.mk`, there change `OFFSET` to the offset you want to insert this, it needs atleast 0xBC00 bytes.
- Place a Fire Red rom in the repository folder and rename it to `BPRE.gba`.
- Open the terminal in the repository folder and run `make`.
- A rom named `rom_BPRE.gba` will be generated in the folder `build`. (The code is inserterd in `rom_BPRE.gba`. `BPRE.gba` remains unmodified.)

## Credits
- Zake, the person who ported this code.
- The template used here was made by Acimut.
-  The source code was made by CompuMaxx.

- You compile by running make with your terminal, and an injected rom will appear in a folder called `build`.

- Files inside the `include` folder were taken from [**pokefirered**](https://github.com/pret/pokefirered).

