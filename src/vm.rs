//! shared VM implementation

#![allow(non_camel_case_types)]
#![allow(non_upper_case_globals)]

use crate::config;

// types
type byte = u8;
type addr = u16;
type cell = i32;

/// global memory array for the VM
static mut M: [byte; config::VM::Msz] = [0; config::VM::Msz];

/// compiler pointer
static mut Cp: addr = 0;
static mut Ip: addr = 0;

/// return stack
static mut R: [addr; config::VM::Rsz] = [0; config::VM::Rsz];
static mut Rp: u8 = 0;

/// data stack

static mut D: [cell; config::VM::Dsz] = [0; config::VM::Dsz];
static mut Dp: u8 = 0;
