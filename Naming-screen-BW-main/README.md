# GEN V Styled Naming Screen FR
___


## What's this?
This code changes the Fire Red's old Naming Screen to
a new Naming Screen with GEN V Styled UI graphics and better
animations.

<image src="namingscreen1.png"> </image>

## How to Use?

To build the code and insert it into your 
FR rom you'll require `make`, `armips` and `devkitARM`.
(armips, gbagfx and preproc are included in the project itself in tools folder, no need to install them.)
### Configuration 

To configure the compile options edit `config.mk`:
```
# variables

ROM_CODE ?= BPRE
OFFSET ?= 0x08800000
```

Set `OFFSET` value to the address where you want the 
code to be inserted in rom.

### Build Instruction

- Clone or download the repository and copy your FR rom 
to this directory and rename it to `BPRE.gba`.
Do not forget to give path to Gnu make in user variables , just edit the Path to the GnuWin32's bin like here my path is C:\GnuWin32\bin

- Before initiating the build, add `DEVKITARM` to environment by running:

```powershell
 set DEVKITARM=path\to\devkitARM
```
- Once ready, open command promt/powershell and write:
```powershell
make
```
This should generate `build/rom_BPRE.gba` rom with code inserted.

## Credits

The code and graphics are taken from [CompuMaxx/TerraNovaFR](https://github.com/CompuMaxx/TerranovaFR)
and ported to this [build system](https://github.com/Acimut/Pokemon-GBA-hack-template)
