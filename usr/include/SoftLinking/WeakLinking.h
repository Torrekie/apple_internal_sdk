#pragma once

// Stolen from Source/WTF/wtf/darwin/WeakLinking.h‎

#define WEAK_LINK_FORCE_IMPORT(sym) extern __attribute__((weak_import)) __typeof__(sym) sym
