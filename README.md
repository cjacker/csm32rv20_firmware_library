# csm32rv20 firmware library

CSM32RV20 is a RISCV MCU made by Nanjing Zhongke Micro. it's 32MHz RISC-V RV32IMAC with 4KB SRAM + 40KB FLASH + 512B NVM.

This is CSM32RV20 firmware library v1.7.0 from Nanjing Zhongke Microelectronics.

```
csm32rv20_firmware_library
├── datasheet
│   └── CSM32RV20_datasheet_v1.23_only_cn.pdf : datasheet
├── Devices
│   ├── cjlink.cfg : used by cjlink (a private OpenOCD fork without linux build, not open source)
│   ├── csmflash.JLinkScript : important !, JLINK_ExecCommand("SetcJTAGInitMode = 1") must set, otherwise, failed to connect. 
│   ├── Flashloader.elf : flash loader
│   └── JLinkDevices.xml : JLink device database
├── flash.jlink : Jlink script to flash hex file to device
├── fw_lib : firmware library
│   ├── drivers
│   ├── ld
│   └── startup
├── hardware : official evb pcb & sch
│   ├── qfn32
│   └── tssop20
├── import-csm-jflash : script to set up csm flashloader for JFlash 
├── Makefile
├── README.md
└── src
    ├── main.c
    └── sys_io.c
```

It is extracted from csmstudio and with below changes:

- convert all files to UTF-8 encoding
- tune dir structure, put vectors.S (triditional startup.S) to 'fw_lib/startup' dir.
- add a 'Makefile', let it can be built.

# Build
type `make` to build.

# Flash
You have to use JLink now.

type `make flash` to program firmware to target device.

# Debug
You have to use JLink now.

type `make debug` to invoke JLinkGDBServer and open another terminal window to launch 'riscv-none-embed-gdb'.


There is also another firmware library provided in csmstudio for 'Shanghai WestBerry WB32F030', after diff with csm32rv20 firmware library, it's exactly identical, these two MCUs are same with different brand.

CSM32RV20 can be programmbed by JLink. 

And the 'Devices/cjlink.cfg' is a config file for private forked OpenOCD. it seems they already have a workable forked OpenOCD to support their 'cjlink' debugger and csm flash driver, and release a 'cjlink.exe' for windows, but not released in binary or source format for linux.
