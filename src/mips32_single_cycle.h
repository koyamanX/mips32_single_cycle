#ifndef MIPS32_SINGLE_CYCLE_H
#define MIPS32_SINGLE_CYCLE_H

declare inc32
{
	input a[32];
	output q[32];
	func_in exe(a) : q;
}

declare cla32
{
	input a[32];
	input b[32];
	input cin;
	output q[32];
	func_in exe(a, b, cin) : q;
}

declare alu32
{
	input a[32];
	input b[32];
	input fn[4];
	output q[32];
	output zero;
	func_in exe(a, b, fn) : q;
}

declare reg32
{
	input rnuma[5];
	input rnumb[5];
	input wnum[5];
	input wdata[32];
	output rdataa[32];
	output rdatab[32];
	func_in reada(rnuma) : rdataa;
	func_in readb(rnumb) : rdatab;
	func_in write(wnum, wdata);
}

declare alu_ctl
{
	input funct[6];
	input aluop[2];
	output fn[4];
}

declare ctl_unit
{
	input inst[6];
	func_out regDst;
	func_out branch;
	func_out memRead;
	func_out aluOp0;
	func_out aluOp1;
	func_out mem2Reg;
	func_out memWrite;
	func_out aluSrc;
	func_out regWrite;
	func_out jump;
}

declare mips32
{
	output iadrs[32];
	output dadrs[32];
	input idata[32];
	inout ddata[32];
	func_in startup();
	func_out imread(iadrs) : idata;
	func_out dmread(dadrs) : ddata;
	func_out dmwrite(dadrs, ddata);
}

struct Itype
{
	op[6];
	rs[5];
	rt[5];
	im[16];
};

#endif
