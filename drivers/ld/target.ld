/*
 *riscv.lds
 *@2019-04-14
 *(1)Add .srodata section into .rodata section
 *
 */
OUTPUT_ARCH( "riscv" )

ENTRY( vector_base )



MEMORY
{
  rom (rxai!w) : ORIGIN = 0x20000000, LENGTH = 40K
  ram (wxa!ri) : ORIGIN = 0x20020000, LENGTH = 4K
}



PHDRS
{
  rom PT_LOAD;
  ram_init PT_LOAD;
  ram PT_NULL;
}

SECTIONS
{
	__stack_size = DEFINED(__stack_size)?__stack_size : 256;
	PROVIDE(_stack_size =_stack_size);
	_heap_size  = DEFINED(__heap_size)?__heap_size : 256;
	PROVIDE(_stack_size =_stack_size);
	. = ALIGN(4);
	.init :
	{
		*(.init);
	} >rom AT>rom :rom

	.text :
	{
	  *(.text.startup .text.startup.*);
	  *(.text .text.*);
	} >rom AT>rom :rom

	.rodata	:
	{
	  *(.rdata);
	  *(.rodata .rodata.*);
	  *(.srodata .srodata.*);
	} >rom AT>rom :rom
     . = ALIGN(4);
    _data_load_start = .;
	.data  :ALIGN(4)
	{_data_start  = . ;
	  *(.data .data.*);
	   PROVIDE( __global_pointer$ = . + 256 );
	  *(.sdata .sdata.* .sdata2.*);
	} >ram AT>rom :ram_init
    _data_end = _data_start + SIZEOF(.data);
	.bss : ALIGN(4)
	{_bss_start = . ;
	  *(.sbss*)
	  *(.bss .bss.*)
	  _bss_end = . ;
	} >ram AT>ram :ram

  . = ALIGN(4);
  PROVIDE( _end = . );
  PROVIDE( end = . );
  .stack ORIGIN(ram) + LENGTH(ram) - __stack_size :
  {
    . = __stack_size;
    PROVIDE( _sp = . );
  } >ram AT>ram :ram
   . = ALIGN(4);
  .heap  ORIGIN(ram) + LENGTH(ram) - __stack_size - _heap_size : {
     . = _heap_size;
     PROVIDE( _heap_end = . );
     }
}
