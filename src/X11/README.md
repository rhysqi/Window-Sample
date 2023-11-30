# Dependencies
- Xorg/X11

# How to build
- FreeBSD
```
clang filename.c -o filename -I/usr/local/include -L/usr/local/lib -lX11
```

- Linux
```
clang filename.c -o filename -lX11
```
