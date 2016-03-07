# CppPurgatory

This is where the Devil lures... in C++

I set up some interesting examples, either one is
* compiler specific: works with `cl` but not with `g++` or vice-versa
* non-standard: it is up to the compiler how to interpret it
* bug/feature

Feel free to come up with more satanic examples!

## Compile
* Windows: in `cmd` locate and run `vcvarsall.bat` (usually under _C:\Program Files (x86)\Microsoft Visual Studio 99.9\VC_), then compile with `nmake /F Makefile.mak`
* Unix: `make`
