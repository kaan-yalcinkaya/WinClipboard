# WinClipboard
A small clipboard library written in C.
# Install
```
git clone https://github.com/kaan-yalcinkaya/WinClipboard.git
cd <path\to\WinClipboard>
md build
cmake -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -DBUILD_SHARED_LIBS=TRUE -B build
cmake --build build
```
# Functions
```
winClipboardGet(): returns copy of the unicode text form the clipboard if function succesed otherwise returns NULL.
winClipboardSet(): transfers given wide character string to the clipboard.
```
