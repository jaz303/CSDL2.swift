# CSDL2.swift

A minimal set of headers to enable usage of SDL2 in Swift. Most of the work here is done by LLVM's awesome C integration.

The code needed to use these bindings is ugly; for a cleaner, more "Swift-like" interface to SDL2 functionality, check out [SDL2.swift](https://github.com/jaz303/SDL2.swift) (work in progress) which will build upon these bindings.

## Usage notes

You must update the path to `SDL.h` in `module.map`. Eventually this step will be handled by the Swift package manager.

SDL uses `enum` and integers interchangably; as far as I can tell this isn't compatible with Swift's C interop. As a workaround, corresponding `#define`s have been generated for each `enum` value, prefixed with `K_`. Static `#defines` are also generated for values defined by complex macros, such as `SDL_WINDOWPOS_UNDEFINED`. A full list of generated constants can be found in `SDL2_generated_constants.h`.

## Example

```swift
import CSDL2

if SDL_Init(Uint32(SDL_INIT_VIDEO)) < 0 {
	print("error initialising SDL");
}

var win = SDL_CreateWindow("Hello World", K_SDL_WINDOWPOS_UNDEFINED, K_SDL_WINDOWPOS_UNDEFINED, 640, 480, Uint32(K_SDL_WINDOW_SHOWN));
if win == nil {
	print("error creating window");
}

var evt = SDL_Event();
while true {
	SDL_WaitEvent(&evt);
	if evt.type == Uint32(K_SDL_WINDOWEVENT) && evt.window.event == Uint8(K_SDL_WINDOWEVENT_CLOSE) {
		break;
	}
}

SDL_DestroyWindow(win);
SDL_Quit();
```

## Building

  1. Check out this repo locally
  2. Write your code in `main.swift`
  3. Compile with:

```shell
swiftc -L/usr/local/lib -Xcc -I/usr/include -I ./modules main.swift
```

Tested with `Apple Swift version 2.2-dev (LLVM 3ebdbb2c7e, Clang f66c5bb67b, Swift 0ddf238ad7)` on OS X.

Notes:

  * `-L/usr/local/lib` should be the library path for locating SDL
  * `-Xcc -I/usr/include` is required so that any system headers needed by SDL can be found
  * `-I ./modules` should point to the directory containing the CSDL2 directory (i.e. a checked out copy of this repo)

## TODO

  - submodules for image, network etc.
  - package as a proper Swift package
