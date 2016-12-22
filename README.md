# CSDL2.swift

A minimal set of headers to enable usage of SDL2 in Swift. Most of the work here is done by LLVM's awesome C integration.

The code needed to use these bindings is ugly; for a cleaner, more "Swift-like" interface to SDL2 functionality, check out [SDL2.swift](https://github.com/jaz303/SDL2.swift) which builds upon these bindings.

If SDL2's prefix is not `/usr`, you must update the prefixes in `module.modulemap`.