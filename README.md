# CppPurgatory

This is where the Devil lures... in C++

I set up some interesting examples, either one is
* compiler specific: works with one compiler but not with another
* non-standard: it is up to the compiler how to interpret it
* bug/feature
* _could_ but _shouldn't_
* Just interesting

__Feel free to contribute with more satanic examples!
Or with a proper explanation/fix for these example. Or tell me more curiosities.__

## Compile
The very same code compiles with different makefiles (or _not_, depending on the example).
* Unix (`g++`)
 * `make`
* Windows (`cl`): in command line locate and run `vcvarsall.bat` (usually under _C:\Program Files (x86)\Microsoft Visual Studio 99.9\VC_), then compile with
 * `nmake /F Makefile.mak`
