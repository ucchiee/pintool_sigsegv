# pintool_sigsegv

An example pintool that surpress SIGSEGV.

## build

```bash
make
```

## how to run pintool

```bash
./pin-3.20-98437-gf02b61307-gcc-linux/pin -t src/obj-intel64/pintool_sigsegv.so -- /abs/path/to/a.out
```

## release note

- v0.0.1: added prototype
- v0.0.2: added test program
- v0.0.3: fixed test program
