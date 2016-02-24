# CSDL2.swift

A minimal set of headers to enable usage of SDL2 in Swift. Most of the work here is done by LLVM's awesome C integration.

The code needed to use these bindings is ugly; for a cleaner, more "Swift-like" interface to SDL2 functionality, check out [SDL2.swift](https://github.com/jaz303/SDL2.swift) which builds upon these bindings.

## Usage notes

When first compiling a project that uses this package, the build will fail. To fix, run these commands, replacing `$VERSION` as necessary:

    $ cd Packages/CSDL2.swift-$VERSION
    $ ./Hooks/post-install

This step is necessary because SDL uses `enum` and integers interchangably; as far as I can tell this isn't compatible with Swift's C interop. As a workaround, corresponding `#define`s have been generated for each `enum` value, prefixed with `K_`. Static `#defines` are also generated for values defined by complex macros, such as `SDL_WINDOWPOS_UNDEFINED`. A full list of generated constants can be found in `SDL2_generated_constants.h`.

If SDL is installed anywhere other than `/usr/local` you will also need to update `module.modulemap` as necessary.

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
