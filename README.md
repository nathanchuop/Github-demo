# libhal-starter

## 🧰 Setup

1. [Setup libhal tools](https://libhal.github.io/prerequisites/)
2. Add `libhal-trunk` remote conan server

    ```bash
    conan remote add libhal-trunk https://libhal.jfrog.io/artifactory/api/conan/trunk-conan
    ```

    > The "trunk" repository represents the latest packaged code based on
    > github.
    >
    > This command will insert `libhal-trunk` as the first server to check
    > before checking the conan center index. The second command will enable
    > revision mode which is required to use the `libhal-trunk` conan package
    > repository.

## 🏗️ Building Project

### Debug Build

Debug builds are helpful as they reduce the amount of compile time optimizations
in order to make the debugging experience better. This comes at the cost of
slower code and larger binary sizes.

To build with this level:

```
conan build . -s build_type=Debug
```

### Release Build

Release builds are harder to debug but are faster and have smaller binary sizes.

To build with this level:

```
conan build . -s build_type=Release
```

## Contributing

See [`CONTRIBUTING.md`](CONTRIBUTING.md) for details.

## License

Apache 2.0; see [`LICENSE`](LICENSE) for details.

## Disclaimer

This project is not an official Google project. It is not supported by
Google and Google specifically disclaims all warranties as to its quality,
merchantability, or fitness for a particular purpose.

