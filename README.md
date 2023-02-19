# csm32rv20 firmware library

CSM32RV20 is a RISCV MCU made by Nanjing Zhongke Micro. it's 32MHz RISC-V RV32IMAC with 4KB SRAM + 40KB FLASH + 512B NVM.

This is CSM32RV20 firmware library v1.2.0 from Nanjing Zhongke Microelectronics.

```
csm32rv20_firmware_library
├── config : a cjlink.cfg for OpenOCD, but not used
├── Devices : jlink related files
├── datasheet : datasheet in Chinese, no en datasheet provided.
├── drivers : firmware library sources
├── hardware : ref board
├── Makefile
├── README.md
└── src : user's codes.
```

It is extracted from csmstudio and with below changes:

- convert all files to UTF-8 encoding
- tune dir structure, put vectors.S (triditional startup.S) to 'drivers/startup' dir.
- put linker script 'target.ld' to 'drivers/ld' dir.
- add a 'Makefile', let it can be built.

There is also another project template provided in csmstudio for 'Shanghai WestBerry WB32F030', after diff with csm32rv20 firmware library, it's exactly same. aka, these two MCU are same with different brand.

CSM32RV20 can be programmbed by JLink. 

And according to the 'config/cjlink.cfg', it's a config file for a private forked OpenOCD. it seems they already have a workable forked OpenOCD to support their 'cjlink' debugger and csm flash, but not released in binary or source format.
